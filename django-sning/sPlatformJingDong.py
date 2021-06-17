# -*- coding: utf-8 -*-
import urllib.request as req
import json
import time
import sys
import os
from bs4 import BeautifulSoup
from sDBHelper import DBHelper
from sProcessComments import AnalyseOne
from cmd import moveAll
"""
@author: sning
createtime: 2018-12-25
updatetime: 2019-04-10
mark: 京东评论数据最多给了50页x10条
"""


def optiComment(com):
    # 处理部分数据类型
    level = 0
    if com['userLevelName'] == "铜牌会员":
        level = 1
    elif com['userLevelName'] == "银牌会员":
        level = 2
    elif com['userLevelName'] == "金牌会员":
        level = 3
    elif com['userLevelName'] == "钻石会员":
        level = 4
    elif com['userLevelName'] == "PLUS会员":
        level = 5
    ismobile = 0
    if com['isMobile']:
        ismobile = 1
    client = 0
    if com['userClientShow'] == '来自京东iPhone客户端':
        client = 1
    elif com['userClientShow'] == '来自京东Android客户端':
        client = 2
    elif com['userClientShow'] == '来自京东iPad客户端':
        client = 3
    elif com['userClientShow'] == '来自微信购物':
        client = 4
    elif com['userClientShow'] == '来自手机QQ购物':
        client = 5
    if len(com['nickname']) > 10:
        com['nickname'] = com['nickname'][:10]
    return level, ismobile, client


class JDCommentsSpider:
    comtype = ("全部类型", "差评", "中评", "好评")
    locationLink = 'https://sclub.jd.com/comment/productPageComments.action?'
    # locationLink = 'https://club.jd.com/comment/getProductPageFoldComments.action?'
    locationUrl = None
    paramValue = None
    # 日志去重
    finishPages = set()
    # 协程启动
    dbHelper = DBHelper()
    commentSaver = dbHelper.saveJingDongComment()
    commentSaver.send(None)

    def __init__(
            self,
            proxy,
            category,
            productId=None,
            score=0,
            sortType=6,
            pageSize=10):
        self.proxy = proxy
        self.category = category
        self.itemId = productId     # 商品ID
        self.score = score          # 评论类型（好：3、中：2、差：1、所有：0）
        self.sortType = sortType    # 排序类型（推荐：5、时间：6）
        self.pageSize = pageSize    # 每页显示多少条记录（默认10）
        self.headers = {
            'Connection': 'Keep-Alive',
            'Accept': 'text/html, application/xhtml+xml, */*',
            'Accept-Language': 'zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2',
            'User-Agent': "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) "
                          "Chrome/71.0.3578.98 Safari/537.36",
            'Referer': 'https://item.jd.com/%s.html' % self.itemId,
            # 'Host': 'club.jd.com',
            'Host': 'sclub.jd.com'}

        self.logtxt = "log/fp_%s.txt" % self.category
        if not os.path.exists(self.logtxt):
            temp = open(self.logtxt, 'w')
            temp.close()
        else:
            with open(self.logtxt, 'r') as f:
                for line in f.readlines():
                    self.finishPages.add(line[:-1])
        self.logfile = open(self.logtxt, "ab+", buffering=0)

    def getCommentBaseUrl(self):
        # 生成评论页基本地址
        def paramDict2Str(params):
            str1 = ''
            for p, v in params.items():
                str1 = str1 + p + '=' + str(v) + '&'
            return str1
        self.paramValue = {
            # 'callback': 'jQuery4492541',
            'productId': self.itemId,
            'score': self.score,
            'sortType': self.sortType,
            'pageSize': self.pageSize,
            'isShadowSku': 0,
            'rid': 0,
            'fold': 1
        }
        self.locationUrl = self.locationLink + \
            paramDict2Str(self.paramValue) + 'page='

    def getPage(self, pageUrl):
        # 使用urllib.request库
        proxy = req.ProxyHandler(self.proxy)
        opener = req.build_opener(proxy)
        request_m = req.Request(pageUrl, headers=self.headers)
        try:
            data = opener.open(request_m, timeout=4).read().decode(
                'gbk', 'ignore')
            return data
        except Exception as e:
            print("获取失败，再次尝试获取", end='')
            time.sleep(3)
            return self.getPage(pageUrl)

    def savePage(self, pageUrl):
        #  按页评论列表页
        jsonPage = self.getPage(pageUrl)
        if jsonPage:
            json_info = json.loads(jsonPage)
            productCommentSummary = json_info['productCommentSummary']
            productId = productCommentSummary['productId']
            comments = json_info['comments']
            # 返回结果为空 跳出
            if not comments:
                return False
            for com in comments:
                ndata = optiComment(com)
                temp = [
                    com['id'],
                    productId,
                    com['content'],
                    com['creationTime'],
                    com['score'],
                    com['nickname'],
                    ndata[0],
                    ndata[1],
                    ndata[2]]
                print(com['score'], end=' ')
                self.commentSaver.send(temp)
            print('')
            return True

    def processPages(self):
        # 获取所有页面商品评论
        self.getCommentBaseUrl()
        for page in range(0, 50):
            print("尝试采集 %s|页码：%d" %
                  (self.comtype[self.score], page), end='    ')
            pageUrl = self.locationUrl + str(page)
            # 去重
            if pageUrl in self.finishPages:
                print("已经抓取该评论页，跳过")
                continue
            # 采集到空页，该评论类型采集结束
            if not self.savePage(pageUrl):
                print("该页为空，跳出循环")
                # 必须等待，避免重启采集空页过快被屏蔽
                time.sleep(4)
                break
            else:
                self.finishPages.add(pageUrl)
                self.logfile.write(pageUrl.encode('utf-8') + b"\n")
            time.sleep(3)
        print("商品ID： %s 的 %s 抓取结束\n" %
              (self.itemId, self.comtype[self.score]))
        # 整理日志
        # finishlist = list(self.finishPages)
        # 排序规则待修正暂不排序
        # finishlist.sort(key=lambda x: int(x[len(self.locationUrl):]))

    def clear_log(self):
        with open(self.logtxt, 'w') as f:
            f.write('')
        print('日志：%s已清理' % self.logtxt)

    def __del__(self):
        with open(self.logtxt, 'w') as f:
            for page in self.finishPages:
                f.write(page + '\n')


def getPageItems(cateGory):
    dbHelper = DBHelper()
    itemInfoSaver = dbHelper.saveJingDongItem()
    itemInfoSaver.send(None)
    for i in range(1, 10):
        murl = "https://list.jd.com/list.html?cat=%s&page=%d" % (cateGory, i)
        html = req.urlopen(murl).read().decode('utf-8', 'ignore')
        soup = BeautifulSoup(html, features="lxml")
        items = soup.find_all('li', class_='gl-item')
        for e in items:
            try:
                platform_id = e.find(
                    'div', class_='gl-i-wrap j-sku-item').attrs['data-sku']
            except Exception:
                continue
            name = e.find('div', class_="p-name").find('em').text.strip()
            image_url = 'static/images/item/example.jpg'
            try:
                image_url = e.find('img').attrs['src']
            except Exception:
                image_url = e.find('img').attrs['data-lazy-img']
            price = '0'
            shopname = ''
            platform = '京东'
            good_percent = '0'
            itemInfoSaver.send((platform_id, name, price, shopname,
                                platform, good_percent, image_url))
            # 采集商品好中差评论
            if dbHelper.itemExisted(platform_id) and dbHelper.itemSpiderFinish(platform_id):
                print('该商品已经采集完成')
                continue
            processItem(platform_id, cateGory)
            dbHelper.setSpiderFinish(platform_id)
            AnalyseOne(platform_id)
            moveAll()


def processItem(Id, cateGory):
    proxy = {'https': '127.0.0.1:8123'}
    time_start = time.time()
    # 采集差评
    jdc3 = JDCommentsSpider(proxy=None, category=cateGory,
                            productId=Id, score=1)
    jdc3.processPages()
    # 采集中评
    jdc3.score = 2
    jdc3.processPages()
    # 采集好评
    jdc3.score = 3
    jdc3.processPages()
    jdc3.clear_log()
    time_end = time.time()
    print('该商品耗时：%fs' % (time_end - time_start))


def getItem(platform_id):
    dbHelper = DBHelper()
    if dbHelper.itemExisted(platform_id) and dbHelper.itemSpiderFinish(platform_id):
        print('该商品已经采集完成')
        return
    cateGory = '000'
    url = 'https://item.jd.com/%s.html' % platform_id
    data = req.urlopen(url).read().decode('gbk')
    bs = BeautifulSoup(data, "lxml")
    img = bs.find('img', id='spec-img')
    dbHelper = DBHelper()
    itemInfoSaver = dbHelper.saveJingDongItem()
    itemInfoSaver.send(None)
    name = img.attrs.get('alt')
    image_url = img.attrs.get('data-origin')
    price = '0'
    shopname = ''
    platform = '京东'
    good_percent = '0'
    itemInfoSaver.send((platform_id, name, price, shopname,
                        platform, good_percent, image_url))
    processItem(platform_id, cateGory)
    dbHelper.setSpiderFinish(platform_id)


if __name__ == '__main__':
    # def usage():
    #     print(u"""
    #     -c / --cate :使用帮助
    #     -i / --ip :参数为ip
    #     -p / --prot :参数为端口号
    #     """)
    category = '1713,3273,3545'
    # category = sys.argv[1]
    getPageItems(category)
    # proOne('6072614')
    # proOne('100002928171')
