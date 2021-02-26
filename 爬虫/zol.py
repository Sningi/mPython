# _*_ coding:utf-8 _*_
"""爬取zol壁纸网站上所有的壁纸"""

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
sort=""

def down_image(url, path):
    html = requests.get(url)
    with open(path, 'wb+') as file:
        file.write(html.content)
    print("下载完成：",url,":",path)

class ZolSpider(object):
    def __init__(self, url=''):
        self.url = url
        self.base_url = 'http://desk.zol.com.cn'

    def get_html(self):
        """将获取到的html文本经过beautifulsoup加工"""
        url = self.url
        html = requests.get(url)
        soup_html = BeautifulSoup(html.content, 'html.parser')
        return soup_html

    def spider(self):
        """调用类别爬虫"""
        CategorySpider(self.base_url).category_spider()


class CategorySpider(ZolSpider):
    def get_category_url(self):
        """获取所有的类别"""
 #       soup_html = self.get_html()
        category_url = []
 #       category = soup_html.find('dl', class_='filter-item first clearfix')
 #       for child in category.find_all('a'):
 #           category_url.append(self.base_url + child['href'])
        category_url.append(self.base_url+'/meinv/1920x1080/')
        return category_url

    def category_spider(self):
        """调用图片列表爬虫"""
        for url in self.get_category_url():
            print('Current_Category:' + url.split('.cn')[-1])
            PhotoListSpider(url).list_spider()
            time.sleep(3)

# 图片列表


class PhotoListSpider(ZolSpider):
    def get_photo_list_url(self):
        """获取图片列表链接"""
        soup_html = self.get_html()
        photo_list_url = []
        photo_list = soup_html.find_all('li', class_='photo-list-padding')
        for child in photo_list:
            photo_list_url.append(
                self.base_url + child.a['href']+child.img['title'][:-4])
            try:
                os.mkdir("/home/sgming/Ms/Media/work/zol/mn/" +
                         str(child.img['title'][:-4])+'5.5')
            except Exception as e:
                print("exist")
        return photo_list_url

    def get_next_page_url(self):
        """获取下一页链接"""
        soup_html = self.get_html()
        next_page_tag = soup_html.find('a', id='pageNext')
        next_page_url = self.base_url + next_page_tag['href']
        return next_page_url

    def list_spider(self):
        """递归遍历所有列表"""
        print(u'Current_List:' + self.url.split('.cn')[-1])
        #next_page = self.get_next_page_url()
        self.photo_spider()
        # if next_page:
        #   PhotoListSpider(next_page).list_spider()
        #   time.sleep(5)

    def photo_spider(self):
        """调用图片爬虫"""
        for url in self.get_photo_list_url():
            #print('Current_Set:' + url)
            PhotoSpider(url).photo_spider()
            time.sleep(1)

# 图片展示


class PhotoSpider(ZolSpider):
    def get_photo_url(self):
        global num
        global sort
        """获取图片链接"""
        pats = self.url.split('.html')
        self.url = pats[0]+'.html'
        if pats[1]:
            sort = pats[1]
        imagename = "/home/sgming/Ms/Media/work/zol/mn/" + \
            sort+"5.5"+'/'+str(num)+".jpg"
        soup_html = self.get_html()
        img_tag = soup_html.find('img', id='bigImg')
        img_url = img_tag['src']
        img_url=img_url.replace("960x600", "1920x1080")
        urlandpath = img_url+imagename
        global imagequeue
        num += 1
        print(urlandpath, "入列")
        imagequeue.put(urlandpath)
        imagequeue.task_done()
        return img_url

    def get_next_page_url(self):
        """获取下一页链接"""
        soup_html = self.get_html()
        next_page_tag = soup_html.find('div', id='photo-next')
        _next_page_url = self.base_url + next_page_tag.a['href']
        return _next_page_url

    def photo_spider(self):
        """递归遍历所有图片"""
        self.get_photo_url()
        next_page = self.get_next_page_url()
        if 'javascript' not in next_page:
            PhotoSpider(next_page).photo_spider()


class control(threading.Thread):
    def __init__(self, imagequeue):
        threading.Thread.__init__(self)
        self.imagequeue = imagequeue

    def run(self):
        global processing
        time.sleep(30)
        while(processing):
            print("processing")
            time.sleep(30)
            if(self.imagequeue.empty()):
                print("qenue is empty processing:", processing)
                processing = False
                end = time.clock()
                global start
                print("time consum:", str(end-start))
        print("程序结束")
        print(str(self)+" finish")


class getcontent(threading.Thread):
    def __init__(self,urlqueue):
        threading.Thread.__init__(self)
        #self.proxy = proxy
        self.urlqueue = urlqueue

    def run(self):
        global subcount
        #print("get content Threads:",str(self))
        global processing
        while(processing):
            time.sleep(5)
            try:
                if(self.urlqueue.empty()):
                    print("queue is empty")
                    time.sleep(3)
                else:
                    print("剩余图片：", self.urlqueue.qsize())
                    url_path=self.urlqueue.get()
                    pat=url_path.split("/home")
                    trueurl=pat[0]
                    namepath="/home"+pat[1]
                    print("第"+str(subcount)+"次出列 出列内容：", trueurl, namepath)
                    subcount += 1
                    down_image(trueurl, namepath)
            except Exception as e:
                print("getcontent exception:", str(e))
                time.sleep(1)
        print(str(self)+" 出列结束")


if __name__ == '__main__':
    control1 = control(imagequeue)
    control1.start()
    for s in range(5):
        g2 = getcontent(imagequeue)
        g2.start()
    ZolSpider().spider()
