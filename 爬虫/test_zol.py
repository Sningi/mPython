import urllib.request
import re
import urllib.error
opener = urllib.request.build_opener()
User_Agent = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36")
opener.addheaders = [User_Agent]
urllib.request.install_opener(opener)

urlpat='/bizhi/7267_89897_2.html'
num =6
for i in range(num):
    ulpt = '.+?_(.+?)_.+?'
    trueul = re.compile(ulpt).findall(urlpat)
    trueul = trueul[0]
    trueuls = 'http://desk.zol.com.cn/down/1920x1080_'+trueul+".html"
    # print("地址：",trueuls)
    imagename = "/home/sgming/Ms/Media/work/zol/" + \
        str(1)+'/'+str(num)+".jpg"
    try:
        print("图片地址：",trueuls,"图片名",imagename)
        urllib.request.urlretrieve(trueuls, filename=imagename)
        print("down finish", imagename)
    except Exception as e:
        print('down fialed:', str(e))

    try:
        #time.sleep(1)
        Url='http://desk.zol.com.cn'+urlpat
        htmlcon= opener.open(Url).read()
        print("request success")
        nexthtml=htmlcon.decode('gb2312')
        print("执行")
        p1 = 'pageNext.+?href="(.+?html)"'
        
        rs = re.compile(p1,re.S).findall(nexthtml)
        urlpat=rs[0]
        print('next:http://desk.zol.com.cn'+urlpat)
    except urllib.error.URLError as e:
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)
    except Exception as e:
        print("exception:", str(e))