import threading
import queue
import re
import urllib.request
import time
import urllib.error
import os

start = time.clock()
# 主题url队列
urlqueue = queue.Queue()
# 模拟浏览器
headers = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.3")
opener = urllib.request.build_opener()
opener.addheaders = [headers]
urllib.request.install_opener(opener)

addcount = 1
subcount = 1

processing = True


# 使用代理服务器
def use_proxy_get_html_data(proxy_addr, url):
    try:
        '''
        print(proxy_addr)
        proxy = urllib.request.ProxyHandler({'http': proxy_addr})
        opener = urllib.request.build_opener(proxy, urllib.request.HTTPHandler)
        urllib.request.install_opener(opener)
        #page = opener.open('http://ip.chinaz.com/getip.aspx')
        # print(page.read().decode('utf-8'))
        #print("try get html")
        # print(proxy,url)
        '''
        data = urllib.request.urlopen(url).read().decode('utf-8')
        # print(data)
        return data
    except urllib.error.URLError as e:
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)
    except Exception as e:
        print("exception:", str(e))

    # 线程1 获取主题url队列


def down_image(proxy, url, zhuti):
    try:
        os.mkdir("/home/sgming/Ms/Media/work/mt/"+str(zhuti))
    except Exception as e:
        print("exist")
        zhuti=zhuti+"_1"
    down(proxy, url, str(zhuti), 1)
    for i in range(2, 10):
        down(proxy, url[0:-5]+"_"+str(i)+'.html', str(zhuti), i)


def down(proxy, url, zhuti, num):
    try:
        html2 = urllib.request.urlopen(url).read().decode('utf-8')
    except urllib.error.URLError as e:
        print("none")
        return
    p1 = '<div class="paper-down">.+?(http:.+?\.jpg).down"'
    rs1 = re.compile(p1, re.S).findall(html2)
    try:
        rs1 = rs1[0]
    except Exception as e:
        print("rs1 is none")
    print("rs1:", rs1)
    imagename = "/home/sgming/Ms/Media/work/mt/" + \
        str(zhuti)+'/'+str(num)+".jpg"
    try:
        urllib.request.urlretrieve(rs1, filename=imagename)
        print("down finish", imagename)
    except Exception as e:
        print('down fialed:', str(e))


class get_sort_url(threading.Thread):
    def __init__(self, url, page, proxy, urlqueue):
        threading.Thread.__init__(self)
        self.url = url
        self.page = page
        self.proxy = proxy
        self.urlqueue = urlqueue

    def run(self):
        print("try open page "+str(self.page))
        main_data = use_proxy_get_html_data(self.proxy, self.url)
        pat1 = '<div class="w1180 clearfix">.+?<div class="pages">'
        fin = re.compile(pat1, re.S).findall(str(main_data))
        fin = fin[0]
        pat2 = 'href="(http://www.win4000.com/.+?\.html)".+?title="(.+?)"'
        fin = re.compile(pat2, re.S).findall(fin)
        global addcount
        for url_and_title in fin:
            # time.sleep(5)
            self.urlqueue.put(url_and_title)
            self.urlqueue.task_done()
            #print("第"+str(addcount)+"次入列 内容：",url_and_title[0], url_and_title[1])
            addcount += 1
        print(str(self)+"入列结束")


class getcontent(threading.Thread):
    def __init__(self, proxy, urlqueue):
        threading.Thread.__init__(self)
        self.proxy = proxy
        self.urlqueue = urlqueue

    def run(self):
        global subcount
        #print("get content Threads:",str(self))
        global processing
        while(processing):
            try:
                if(self.urlqueue.empty()):
                    print("queue is empty")
                    time.sleep(3)
                else:
                    print("剩余主题数目：", urlqueue.qsize())
                    con = self.urlqueue.get()
                    url = con[0]
                    zhuti = con[1][:-6]
                    #print("第"+str(subcount)+"次出列 出列内容：", url, zhuti)
                    down_image(self.proxy, url, zhuti)
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
    proxy = "113.12.72.24:3128"
    for i in range(1, 6):
        url = "http://www.win4000.com/wallpaper_2285_0_10_"+str(i)+".html"
        g1 = get_sort_url(url, i, proxy, urlqueue)
        g1.start()
    for s in range(6):
        g2 = getcontent(proxy, urlqueue)
        g2.start()
    control1 = control(urlqueue)
    control1.start()
