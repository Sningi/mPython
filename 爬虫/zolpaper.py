import threading
import queue
import re
import urllib.request
import time
import urllib.error
import os
import random
start = time.clock()
# 主题url队列
urlqueue = queue.Queue()
# 模拟浏览器


# 小主题数目
addcount = 1
# 已完成数目
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
        # page = opener.open('http://ip.chinaz.com/getip.aspx')
        # print(page.read().decode('utf-8'))
        # print("try get html")
        # print(proxy,url)
        '''
        data = urllib.request.urlopen(url).read().decode('gb2312')
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


def down_image(proxy, url, zhuti, num, day):
    # print("出列:", url, zhuti, "num:", num, "date", day)
    try:
        os.mkdir("/home/sgming/Ms/Media/work/zol/"+str(zhuti)+str(day))
    except Exception as e:
        print("exist")
        # zhuti = zhuti+"_1"
        # os.mkdir("/home/sgming/Ms/Media/work/zol/"+str(zhuti)+str(day))
    print("即将下载：张",num)
    down(proxy, url, str(zhuti), num)

    # for i in range(1, num):
    # down(proxy, url[0:-5]+"_"+str(i)+'.html', str(zhuti), i)


def down(proxy_addr, url, zhuti, num):
    #user_agent_list = ["Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/22.0.1207.1 Safari/537.1", "Mozilla/5.0 (X11; CrOS i686 2268.111.0) AppleWebKit/536.11 (KHTML, like Gecko) Chrome/20.0.1132.57 Safari/536.11", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.6 (KHTML, like Gecko) Chrome/20.0.1092.0 Safari/536.6", "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/536.6 (KHTML, like Gecko) Chrome/20.0.1090.0 Safari/536.6", "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/19.77.34.5 Safari/537.1", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/536.5 (KHTML, like Gecko) Chrome/19.0.1084.9 Safari/536.5", "Mozilla/5.0 (Windows NT 6.0) AppleWebKit/536.5 (KHTML, like Gecko) Chrome/19.0.1084.36 Safari/536.5", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1063.0 Safari/536.3", "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1063.0 Safari/536.3","Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_0) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1063.0 Safari/536.3", "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1062.0 Safari/536.3", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1062.0 Safari/536.3", "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.1 Safari/536.3", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.1 Safari/536.3", "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.1 Safari/536.3", "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.0 Safari/536.3", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/535.24 (KHTML, like Gecko) Chrome/19.0.1055.1 Safari/535.24", "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/535.24 (KHTML, like Gecko) Chrome/19.0.1055.1 Safari/535.24", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36"]
    User_Agent = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36")
    Host=["Host","desk.zol.com.cn"]
    #myuse=random.choice(user_agent_list)
    proxy = urllib.request.ProxyHandler({'http': proxy_addr})
    opener = urllib.request.build_opener(proxy, urllib.request.HTTPHandler)
    #headers = ("User-Agent", myuse)
    opener.addheaders=[User_Agent]
    opener.addheaders=[Host]
    urllib.request.install_opener(opener)
    # page = opener.open('http://ip.chinaz.com/getip.aspx')
    # get_trueurl
    ulpt = '.+?_(.+?)_.+?'
    trueul = re.compile(ulpt).findall(url)
    trueul = trueul[0]
    trueuls = 'http://desk.zol.com.cn/down/1920x1080_'+trueul+".html"
    # print("地址：",trueuls)
    imagename = "/home/sgming/Ms/Media/work/zol/" + \
        str(zhuti)+'/'+str(num)+".jpg"
    try:
        # rf=("Referer", "http://desk.zol.com.cn"+url)
        # for cont in opener.headers:
        #  print("cont:",cont)
        # headers = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36")
        # opener = urllib.request.build_opener()
        # host= ("Host","desk.zol.com.cn")
        # opener.addheaders = [headers]
        # opener.addheaders=[host]
        # opener.addheaders=[rf]
        # urllib.request.install_opener(opener)
        print("图片地址：",trueuls,"图片名",imagename)
        # urllib.request.urlretrieve(trueuls, filename=imagename)
        print("down finish", imagename)
    except Exception as e:
        print('down fialed:', str(e))
    num = num-1
    print("now num:",num)
    time.sleep(5)
    print("sleep 5 s")
    if(num > 0):
        try:
            
            print("try request:",'http://desk.zol.com.cn'+url)
            Url='http://desk.zol.com.cn'+url
            htmlcon= opener.open(Url)
            print("request success")
            if(num==4):
                print(htmlcon)
            nexthtml=htmlcon.read().decode('gb2312')
            #nexthtml =  opener.open('http://desk.zol.com.cn'+url).read().decode('gb2312')
            print("执行")
            p1 = 'pageNext.+?href="(.+?html)"'
            
            rs = re.compile(p1,re.S).findall(nexthtml)
            rs=rs[0]
            print('next:http://desk.zol.com.cn'+rs)
            #time.sleep(1)
            down(proxy,rs,zhuti,num)
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
        main_data = use_proxy_get_html_data(self.proxy, self.url)
        pat1 = '<ul class="pic-list2  clearfix">.+?<div class="pagecon">'
        fin = re.compile(pat1, re.S).findall(str(main_data))
        fin = fin[0]
        pat2 = 'href="(/bizhi/.+?\.html)".+?<em>(.+?)</em> (.+?张).+?<ins>(.+?)</ins'
        fin = re.compile(pat2, re.S).findall(fin)
        global addcount
        for url_and_title in fin:
            # time.sleep(5)
            self.urlqueue.put(url_and_title)
            self.urlqueue.task_done()
            # print("第"+str(addcount)+"次入列 内容：",url_and_title[0],":",url_and_title[1],":",url_and_title[2],":",url_and_title[3])
            addcount += 1
        print(str(self)+"入列结束")


class getcontent(threading.Thread):
    con=""
    def __init__(self, proxy, urlqueue):
        threading.Thread.__init__(self)
        self.proxy = proxy
        self.urlqueue = urlqueue

    def run(self):
        global subcount
        # print("get content Threads:",str(self))
        global processing
        while(processing):
            try:
                if(self.urlqueue.empty()):
                    print("queue is empty")
                    time.sleep(3)
                else:
                    #print("剩余主题数目：", urlqueue.qsize())
                    self.con = self.urlqueue.get()
                    print("num:",int(self.con[2][1:-1]))
                    #url = con[0]
                    #zhuti = con[1][:-4]
                    #num =int(con[2][1][-1])
                    #day = con[3]
                    # print("第"+str(subcount)+"次出列 出列内容：", url, zhuti)
                    down_image(self.proxy, self.con[0], self.con[1][:-4], int(self.con[2][1:-1]), self.con[3])
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
    for s in range(1):
        g2 = getcontent(proxy, urlqueue)
        g2.start()
    control1 = control(urlqueue)
    control1.start()
