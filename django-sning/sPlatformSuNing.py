# # coding:utf-8

# import json
# import time
# import requests
# import sys
# import re
# import datetime
# from bs4 import BeautifulSoup


# session = requests.session()


# def spider():
#     # 设置浏览器需要打开的url
#     url = "https://www.suning.com/"
#     browser.get(url)
#     time.sleep(5)

#     browser.find_element_by_id("searchKeywords").send_keys(u'手机')
#     time.sleep(2)

#     for i in range(1, 100):
#         browser.find_element_by_name("index1_none_search_ss1").click()
#         browser.find_element_by_id("nextPage").click()
#         result = browser.page_source
#         soup = BeautifulSoup(result, 'html.parser')
#         result_ul = soup.find_all('div', attrs={"id": "filter-results"})[0]

#         result_list = result_ul.find_all('div', attrs={"class": "li-bg"})
#         print len(result_list)
#         print result_list[1]
#         # for item in result_list:
#         #     print item
#         #     print "==" * 30
#         #
#         # time.sleep(500)

#         for item in result_list:

#             item = str(item).replace('\n', '').replace(
#                 '\r', '').replace('\t', '')
#             print "==" * 30

#             print item
#             try:
#                 sold_price = re.findall(
#                     'pricefn="priceCenterShow"><i>¥</i>(.*?)<i>.*?</i></span>', item)[0]
#             except:
#                 sold_price = re.findall(
#                     '<i>¥</i>(.*?)<i>.*?</i></span>', item)[0]
#             try:
#                 item_name = re.findall(
#                     '<i class=".*?" style=".*?"></i>(.*?)</b></a>', item)[0]
#             except:
#                 item_name = re.findall(
#                     'target="_blank" title="(.*?)"><i class=', item)[0]

#             try:
#                 item_url = re.findall('class=".*?" href="(.*?)" name', item)[0]
#             except:
#                 item_url = re.findall(
#                     '<a class=".*?" href="(.*?)" id=', item)[0]
#             try:
#                 item_desc = re.findall(
#                     '<span><i></i><em>(.*?)</em><b></b></span>', item)[0]
#             except:
#                 item_desc = re.findall('<em>(.*?)</em>', item)[0]

#             print item_url
#             print item_name
#             print sold_price
#             print item_desc

#     time.sleep(500)


# spider()
# -*- coding: utf-8 -*-
import scrapy as scrY
import re
import json
import datetime

# 每页分为4层，直接请求 商品列表页地址 的话，只会显示第一层，其余 3层 是用户下拉后 异步加载出来的，使用抓包的方法可以截取到，所以每一页都分为 4步来分别请求
# 商品列表页 一共有 50页，请求地址参数中的 cp 为页数（0~49），paging 为层数（0~3）
# 商品详情页 可以加载出 商品价格页，携带 商品的id 即可请求


class SuningPhoneSpider(scrY.Spider):
    name = 'suning_phone'
    allowed_domains = ['suning.com']
    # 需要爬取的 类目
    keyword = '手机'
    # 商品列表页的 初始页
    page = 0
    # 商品列表页的 层数
    layer = 0
    # 商品列表页的 地址
    url = 'https://search.suning.com/emall/searchV1Product.do?keyword={0}&pg=01&cp=%d&paging=%d'.format(
        keyword)
    # 商品价格页的 地址
    price_url = 'https://icps.suning.com/icps-web/getVarnishAllPriceNoCache/0000000%s_010_0100101_0000000000_1_getClusterPrice.jsonp?callback=getClusterPrice'

    def start_requests(self):
        yield scrY.Request(url=self.url % (self.page, self.layer), callback=self.parse)

    def parse(self, response):
        # 获取 商品列表页 的所有商品
        goodsInfoList = response.css('.item-wrap')
        for goodsInfo in goodsInfoList:
            # 获取 id 并清洗
            id = goodsInfo.css(
                '.item-wrap::attr(id)').extract()[0].split('-')[1]
            # 获取 详情页地址 并清洗
            url = ''.join(['https:', goodsInfo.css(
                '.img-block a::attr(href)').extract()[0]])
            # 获取 标题
            title = goodsInfo.css(
                '.img-block a img::attr(alt)').extract_first('')
            # 获取 评论数 并清洗
            comment_count = goodsInfo.css(
                '.evaluate-old.clearfix .info-evaluate a i::text').extract_first('0').strip('+')
            # 进一步清洗 评论数
            comment_count = int(float(comment_count.strip(
                '万')) * 10000) if comment_count.endswith('万') else int(comment_count)
            # 获取 店名
            shop_name = goodsInfo.css('.store-stock a::text').extract_first('')
            # 回调去处理 parseDetail函数（处理商品详情页函数）
            yield scrY.Request(url=url, callback=self.parseDetail, meta={'id': id, 'url': url, 'title': title, 'comment_count': comment_count, 'shop_name': shop_name})
        # 判断 商品列表页 层数 并 回调 parse函数（处理商品列表页函数）
        if self.layer < 3 and self.page < 50:
            self.layer += 1
            # meta={'download_timeout':3}（设置超时时间）
            yield scrY.Request(url=self.url % (self.page, self.layer), callback=self.parse)
        if self.layer == 3 and self.page < 49:
            self.layer = 0
            self.page += 1
            yield scrY.Request(url=self.url % (self.page, self.layer), callback=self.parse)

    def parseDetail(self, response):
        # 获取 商品品牌
        brand = response.css('.dropdown-text a::text').extract()[2] if len(
            response.css('.dropdown-text').extract()) == 3 else ''
        # 获取 商品型号 并 清洗
        model_clean = brand.split('(')
        model = response.css(
            '.breadcrumb-title::attr(title)').extract_first('')
        model = model.replace(model_clean[0], '').replace(''.join(['(', model_clean[1]]), '').replace(
            '手机', '') if len(model_clean) == 2 else model.replace(model_clean[0], '').replace('手机', '')
        # 回调去处理 parsePrice函数（处理商品价格页函数）
        yield scrY.Request(url=self.price_url % (response.meta['id']), callback=self.parsePrice, meta={'id': response.meta['id'], 'url': response.meta['url'], 'title': response.meta['title'], 'comment_count': response.meta['comment_count'], 'shop_name': response.meta['shop_name'], 'brand': brand, 'model': model})

    def parsePrice(self, response):
        # 获取 商品价格信息 的json 并 清洗
        text = response.text
        price_info = re.match(
            '.*getClusterPrice\(?(.+)\).*', text, re.S).group(1)
        price = json.loads(price_info)[0]['price']
        price = float(price) if price else 0.0
        # 传入item
        item = Suning_phoneItem()
        item['id'] = response.meta['id']
        item['title'] = response.meta['title']
        item['price'] = price
        item['brand'] = response.meta['brand']
        item['model'] = response.meta['model']
        item['shop_name'] = response.meta['shop_name']
        item['comment_count'] = response.meta['comment_count']
        item['url'] = response.meta['url']
        item['crawl_date'] = datetime.datetime.now()
        yield item
