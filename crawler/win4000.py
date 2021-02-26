import urllib.request
import urllib.error
import threading
import queue
import re
import os
import time
import pycurl
debug = False
addcount = 1
subcount = 1
running = 0

# 生产者


class ObtainAlbums(threading.Thread):
    # 获取分类目录下专辑信息列表线程
    def __init__(self, urlCategory, page, proxy, albumQueue):
        threading.Thread.__init__(self)
        # 分类URL地址、页码、代理、Album队列
        self.urlCategory = urlCategory
        self.albumQueue = albumQueue
        self.page = page
        self.proxy = proxy

    # 是否使用代理服务器
    def getHtml(self):
        try:
            if self.proxy:
                if debug:
                    print("使用代理")
                data = urllib.request.urlopen(
                    self.urlCategory).read().decode('utf-8')
                return data
            else:
                if debug:
                    print("未使用代理")
                data = urllib.request.urlopen(
                    self.urlCategory).read().decode('utf-8')
                return data
        except urllib.error.URLError as e:
            if hasattr(e, "code"):
                print(e.code)
            if hasattr(e, "reason"):
                print(e.reason)
        except Exception as e:
            print("exception:", str(e))

    def run(self):
        if debug:
            print("try open page " + str(self.page))
        htmlData = self.getHtml()
        pat1 = '<div class="w1180 clearfix">.+?<div class="pages">'
        result1 = re.compile(pat1, re.S).findall(str(htmlData))
        if len(result1) > 0:
            result1 = result1[0]
        else:
            result1 = ""
        pat2 = r'href="(http://www.win4000.com/.+?\.html)".+?title="(.+?)"'
        albums = re.compile(pat2, re.S).findall(result1)
        global addcount
        for album in albums:
            # time.sleep(5)
            self.albumQueue.put(album)
            self.albumQueue.task_done()
            if debug:
                print("第" + str(addcount) + "次入列 内容：",
                      album[0], album[1])
            addcount += 1
        global running
        running -= 1
        print("生产者线程:" + str(self) + "入列结束")


# 消费者
class DownAlbum(threading.Thread):
    # 下载专辑内容
    def __init__(self, path, proxy, albumQueue):
        threading.Thread.__init__(self)
        self.albumQueue = albumQueue
        self.proxy = proxy
        self.path = path
        self.curl = pycurl.Curl()

    def run(self):
        global subcount
        global running
        processing = True
        time_start = time.time()
        while(processing):
            if self.albumQueue.empty():
                if debug:
                    print("queue is empty")
                time.sleep(3)
                if self.albumQueue.empty() and running < 1:
                    processing = False
            else:
                if debug:
                    print("剩余主题数目：", self.albumQueue.qsize())
                con = self.albumQueue.get()
                albumLink = con[0]
                albumName = con[1]
                if debug:
                    print("第%d次出列 album：%s %s" %
                          (subcount, albumLink, albumName))
                self.downAlbum(albumLink, albumName)
                subcount += 1
        print("消费者线程：%s结束" % str(self))
        time_end = time.time()
        print('time cost:', time_end - time_start, 's')

    # 专辑列表
    def downAlbum(self, albumLink, albumName):
        albumPath = '%s/%s' % (self.path, albumName)
        if not os.path.exists(albumPath):
            try:
                os.makedirs(albumPath)
            except Exception:
                pass
        else:
            print("Album exist：%s" % albumName)
            return
        self.saveIamge(albumPath, albumLink)
        for i in range(2, 10):
            self.saveIamge(albumPath, "%s_%d.html" %
                           (albumLink[0:-5], i))

    # 专辑下的图片页
    def saveIamge(self, albumPath, pageLink):
        try:
            html2 = urllib.request.urlopen(pageLink).read().decode('utf-8')
        except urllib.error.URLError as e:
            return
        pattern = r'<div class="paper-down">.+?(http:.+?\..+?g).down"'
        imageurl = re.compile(pattern, re.S).findall(html2)[0]
        imagename = '%s/%s' % (albumPath, imageurl[imageurl.rfind('/') + 1:])
        try:
            urllib.request.urlretrieve(imageurl, filename=imagename)
            # self.downFile(imageurl, imagename)
            print("down finish", imagename)
        except Exception as e:
            print('down fialed:', str(e))

    def __del__(self):
        self.curl.close()

    def downFile(self, url, filename):
        with open(filename, 'wb') as f:
            self.curl.setopt(pycurl.URL, url)
            self.curl.setopt(pycurl.WRITEDATA, f)
            self.curl.perform()


def win4000(path, Category, proxy=None, startpage=1, endpage=5, consumer=3):
        # 主题url队列
    albumQueue = queue.Queue()
    # 模拟浏览器
    headers = (
        "User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.3")
    opener = urllib.request.build_opener()
    opener.addheaders = [headers]
    urllib.request.install_opener(opener)
    global running
    for page in range(startpage, endpage + 1):
        running += 1
        url = "http://www.win4000.com/wallpaper_%s_%d.html" % (
            Category, page)
        obtainalbums = ObtainAlbums(url, page, proxy, albumQueue)
        obtainalbums.start()
    time.sleep(5)
    for i in range(consumer):
        downloader = DownAlbum(path, proxy, albumQueue)
        downloader.start()


if __name__ == '__main__':
    proxy = None
    print("欢迎使用美桌网壁纸爬虫\n")
    print('请到 http://www.win4000.com/ 确定分类目录地址')
    # Category = input('分类目录(建议选择桌面壁纸，其他类型未测试)，格式默认：192_0_14\n')
    Category = ''
    if not Category:
        Category = "192_0_14"

    catepath = "./%s" % Category
    if not os.path.exists(catepath):
        os.mkdir(catepath)
    win4000(path=catepath, Category=Category, proxy=proxy,
            startpage=1, endpage=1, consumer=1)
