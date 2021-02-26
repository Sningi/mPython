import re
import urllib.request
import time
import urllib.error
'''
headers = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.3")
opener = urllib.request.build_opener()
opener.addheaders = [headers]
urllib.request.install_opener(opener)

urllist= []
def use_proxy(proxy_addr,url):
    try:
        import urllib.request
        proxy= urllib.request.ProxyHandler({'http':proxy_addr})
        opener=urllib.request.build_opener(proxy,urllib.request.HTTPHandler)
        urllib.request.install_opener(opener)
        data = urllib.request.urlopen(url).read().decode('utf-8')
        return data
    except urllib.error.URLError as e:
            if hasattr(e,"code"):
                print(e.code)
            if hasattr(e,"reason"):
                print(e.reason)
                time.sleep(5)
    except Exception as e:
        print("exception:"+str(e))
        time.sleep(1)

def getlisturl(key,pagestart,pageend,proxy):
    try:
        page=pagestart
        keycode=urllib.request.quote(key)
        for page  in range(pagestart,pageend):
            url="http://weixin.sogou.com/weixin?query="+keycode+"&type=2&page="+str(page)+"&ie=utf8"
            print(url)
            data1 =use_proxy(proxy,url)
            print(data1)
            listurlpat='<div class="txt-box">.*?(http://.*?)"'
            urllist.append(re.compile(listurlpat,re.S).findall(data1))
            print('find '+str(len(urllist))+' pages')
            return urllist
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)
        time.sleep(5)
    except Exception as e:
        print("exception:"+str(e))
        time.sleep(1)
key ="linux"
proxy="58.252.6.165:9000"
pagestart=1
pageend=2
urllist =getlisturl(key,pagestart,pageend,proxy)
'''

headers = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.3")
opener = urllib.request.build_opener()
opener.addheaders = [headers]
urllist= []
try:
    key="linux"
    keycode=urllib.request.quote(key)
    for page  in range(1,2):
        url="http://weixin.sogou.com/weixin?query="+keycode+"&type=2&page="+str(page)+"&ie=utf8"
        print(url)
        data1 = str(opener.open(url).read(),'utf-8')
        #print(data1)
        listurlpat='<div class="txt-box">.*?(http://.*?)"'
        urllist.append(re.compile(listurlpat,re.S).findall(data1))
        print('find '+str(len(urllist))+' pages')
except urllib.error.URLError as e:
    if hasattr(e,"code"):
        print(e.code)
    if hasattr(e,"reason"):
        print(e.reason)
    time.sleep(5)
except Exception as e:
    print("exception:"+str(e))
    time.sleep(1)
for url in urllist:
    print(str(url).replace("amp;",""))
    print("")