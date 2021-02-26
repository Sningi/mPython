#!/usr/bin/env python
# _*_ coding:utf-8 _*_
"""爬取zol壁纸网站上的壁纸"""

import time
from bs4 import BeautifulSoup
import requests
import re
import queue
import threading
import os

start = time.clock()
num = 1
subcount = 1
processing = True
imagequeue = queue.Queue()
sort = ""
page_start=2
page_end=5
# 设置的重点2 ：下载地址
downpath = "/home/sgming/Ms/Media/work/zol/katong/"
downsort = '/katong/1920x1080/'

# 模拟请求头

headers = {
    'Host': 'desk.zol.com.cn',
    'Connection': 'keep-alive',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'Accept-Encoding': 'gzip, deflate',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
}


def down_image(url, path):
    html = requests.get(url)
    with open(path, 'wb+') as file:
        file.write(html.content)
    print("图片下载完成：", url)


class ZolSpider(object):
    def __init__(self, url=''):
        self.url = url
        self.base_url = 'http://desk.zol.com.cn'

    def get_html(self):
        """将获取到的html文本经过beautifulsoup加工"""
        url = self.url
        html = requests.get(url, headers=headers)
        content=html.content.decode('gbk')
        soup_html = BeautifulSoup(content, 'html.parser')
        return soup_html

    def spider(self):
        PhotoListSpider().list_spider()


# 专辑列表


class PhotoListSpider(ZolSpider):
    def get_photo_list_url(self):
        """获取图片列表链接"""
        soup_html = self.get_html()
        photo_list_url = []
        photo_list = soup_html.find_all('li', class_='photo-list-padding')
        cancel=1;
        for child in photo_list:
            if cancel==1:
                cancel=0
                continue
            photo_list_url.append(
                self.base_url + child.a['href']+child.img['title'][:-4])
            try:
                os.mkdir(downpath +
                         str(child.img['title'][:-4]))
            except Exception as e:
                print("exist")
        return photo_list_url

    def list_spider(self):
        """递归遍历所有列表"""
        print(u'Current_List:' + self.url[22:])

        #！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
        # 设置的重点3 分类下某几页
        for i in range(page_start, page_end):
            # 设置的重点1 爬取类别和分辨率
            self.url = self.base_url+downsort+str(i)+'.html'
            self.photo_spider()

    def photo_spider(self):
        """调用图片爬虫"""
        # 给本页约15列表查找专辑全部地址
        for url in self.get_photo_list_url():
            print('Current Album:' + url)
            PhotoSpider(url).photo_spider()

# 图片展示


class PhotoSpider(ZolSpider):
    def put_photo_to_queue(self):
        global num
        global sort
        """获取图片链接"""
        pats = self.url.split('.html')
        self.url = pats[0]+'.html'
        if pats[1]:
            sort = pats[1]
        # 设置地址
        imagename = downpath + \
            sort+'/'+str(num)+".jpg"
        soup_html = self.get_html()
        img_tag = soup_html.find('img', id='bigImg')
        img_url = img_tag['src']
        img_url = img_url.replace("960x600", "1920x1080")
        urlandpath = img_url+imagename
        global imagequeue
        num += 1
        print(urlandpath, "入列")
        imagequeue.put(urlandpath)
        imagequeue.task_done()

    def get_next_page_url(self):
        """获取下一页链接"""
        soup_html = self.get_html()
        next_page_tag = soup_html.find('div', id='photo-next')
        _next_page_url = self.base_url + next_page_tag.a['href']
        return _next_page_url

    def photo_spider(self):
        """递归遍历所有图片"""
        self.put_photo_to_queue()
        next_page = self.get_next_page_url()
        if 'javascript' not in next_page:
            PhotoSpider(next_page).photo_spider()


class control(threading.Thread):
    def __init__(self, urlqueue):
        threading.Thread.__init__(self)
        self.urlqueue = urlqueue

    def run(self):
        global processing
        time.sleep(60)
        while(processing):
            print("processing")
            time.sleep(60)
            if(self.urlqueue.empty()):
                time.sleep(30)
                if(self.urlqueue.empty()):
                    time.sleep(10)
                    if(self.urlqueue.empty()):
                        print("qenue is empty processing:", processing)
                        processing = False
                        end = time.clock()
                        global start
                        print("time consum:", str(end-start))
        print(str(self)+"All down finish")


class getcontent(threading.Thread):
    def __init__(self, urlqueue):
        threading.Thread.__init__(self)
        self.urlqueue = urlqueue

    def run(self):
        global subcount
        #print("get content Threads:",str(self))
        global processing
        time.sleep(5)
        while(processing):
            try:
                if(self.urlqueue.empty()):
                    print("queue is empty")
                    time.sleep(5)
                else:
                    print("剩余图片：", self.urlqueue.qsize())
                    url_path = self.urlqueue.get()
                    pat = url_path.split("/home")
                    trueurl = pat[0]
                    namepath = "/home"+pat[1]
                    print("第"+str(subcount)+"次出列")
                    subcount += 1
                    down_image(trueurl, namepath)
            except Exception as e:
                print("getcontent exception:", str(e))
                time.sleep(1)
        print(str(self)+" 出列结束")


if __name__ == '__main__':
    control1 = control(imagequeue)
    control1.start()
    for s in range(4):
        g2 = getcontent(imagequeue)
        g2.start()
    ZolSpider().spider()
