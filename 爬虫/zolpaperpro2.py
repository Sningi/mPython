import threading
import queue
import re
import urllib.request
import time
import urllib.error
import os
import random
start = time.clock()
# 主题队列 firsturl title num day
urlqueue = queue.Queue()
# 图片和地址队列 pathname url
imagequeue = queue.Queue()
Proxy_addr = "180.110.249.210:8118"

# 小主题数目
addcount = 1
# 已完成数目
subcount = 1
# 图片pathname,url数目
piccount = 1


processing = True

User_Agent = (
    "User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36")
Host = ["Host", "desk.zol.com.cn"]
proxy = urllib.request.ProxyHandler({'http': Proxy_addr})
opener = urllib.request.build_opener(proxy, urllib.request.HTTPHandler)
opener.addheaders = [User_Agent]
opener.addheaders = [Host]
urllib.request.install_opener(opener)


def get_HTML(Url, Code):
    try:
        data = urllib.request.urlopen(Url).read().decode(Code)
        print("get html success")
        return data
    except urllib.error.URLError as e:
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)
    except Exception as e:
        print("exception:", str(e))


def addtofile(filepath, content):
    fd = open(filepath, 'a+')
    fd.write(content + "\n")


def down_image(proxy, url, zhuti, num, day):
    print("出列:", url, zhuti, "num:", num, "date", day)
    try:
        os.mkdir("/home/sgming/Ms/Media/work/zol/"+str(zhuti)+str(day))
    except Exception as e:
        print("exist")
    for i in range(num):
        ulpt = '.+?_(.+?)_.+?'
        trueul = re.compile(ulpt).findall(url)
        trueul = trueul[0]
        trueuls = 'http://desk.zol.com.cn/down/1920x1080_'+trueul+".html"
        # print("地址：",trueuls)
        imagename = "/home/sgming/Ms/Media/work/zol/" + \
            str(zhuti)+str(day)+'/'+str(i)+".jpg"
        addtofile("/home/sgming/Ms/Media/work/zol/imagelist.txt",
                  imagename+":"+trueuls)
        if(i == num-1):
            break
        print("try open next")
        try:
            Url = 'http://desk.zol.com.cn'+url
            htmlcon = get_HTML(Url, 'gb2312')
            print("request success")
            p1 = 'pageNext.+?href="(.+?html)"'
            rs = re.compile(p1, re.S).findall(htmlcon)
            url = rs[0]
            print('next:http://desk.zol.com.cn'+url)
        except urllib.error.URLError as e:
            if hasattr(e, "code"):
                print(e.code)
            if hasattr(e, "reason"):
                print(e.reason)
        except Exception as e:
            print("exception:", str(e))


class get_sort_url(threading.Thread):
    def __init__(self, url, page, proxy, urlqueue):
        threading.Thread.__init__(self)
        self.url = url
        self.page = page
        self.proxy = proxy
        self.urlqueue = urlqueue

    def run(self):
        print("try open page "+str(self.page))
        main_data = get_HTML(self.url, 'gb2312')
        pat1 = '<ul class="pic-list2  clearfix">.+?<div class="pagecon">'
        fin = re.compile(pat1, re.S).findall(str(main_data))
        fin = fin[0]
        pat2 = 'href="(/bizhi/.+?\.html)".+?<em>(.+?)</em> (.+?张).+?<ins>(.+?)</ins'
        fin = re.compile(pat2, re.S).findall(fin)
        global addcount
        for url_and_title in fin:
            self.urlqueue.put(url_and_title)
            self.urlqueue.task_done()
            print("第"+str(addcount)+"次入列 内容：",url_and_title[0],":",url_and_title[1],":",url_and_title[2][1:1],":",url_and_title[3])
            addcount += 1
        print(str(self)+"入列结束，目前总数：", addcount)


class getcontent(threading.Thread):
    con = ''

    def __init__(self, proxy, urlqueue):
        threading.Thread.__init__(self)
        self.proxy = proxy
        self.urlqueue = urlqueue

    def run(self):
        global subcount
        global processing
        global addcount
        while(processing):
            try:
                if(self.urlqueue.empty()):
                    print("queue is empty")
                    time.sleep(3)
                else:
                    print("剩余主题数目：", str(addcount-subcount))
                    self.con = self.urlqueue.get()
                    #url = con[0]
                    #zhuti = con[1][:-4]
                    #num =int(con[2][1:-1])
                    #day = con[3]
                    # print("第"+str(subcount)+"次出列 出列内容：", url, zhuti)
                    down_image(
                        self.proxy, self.con[0], self.con[1][:-4], int(self.con[2][1:-1]), self.con[3])
                    subcount += 1
            except Exception as e:
                print("getcontent exception:", str(e))
                time.sleep(1)
        print(str(self)+" 出列结束")

# 控制线程


class control(threading.Thread):
    def __init__(self, urlqueue):
        threading.Thread.__init__(self)
        self.urlqueue = urlqueue

    def run(self):
        global processing
        while(processing):
            print("processing")
            time.sleep(30)
            if(self.urlqueue.empty()):
                print("qenue is empty processing:", processing)
                processing = False
                end = time.clock()
                global start
                print("time consum:", str(end-start))
        print("程序结束")
        print(str(self)+" finish")


if __name__ == '__main__':
    proxy = "180.110.249.210:8118"
    for i in range(1, 2):
        url = "http://desk.zol.com.cn/zhiwu/1920x1080/"+str(i)+".html"
        g1 = get_sort_url(url, i, proxy, urlqueue)
        g1.start()
    for s in range(1,2):
        g2 = getcontent(proxy, urlqueue)
        g2.start()
    control1 = control(urlqueue)
    control1.start()
