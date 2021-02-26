import re
import os
import urllib.request
import time

start = time.clock()
x = 1


def craw(url, page):
    html1 = urllib.request.urlopen(url).read()
    #html1 = str(html1)
    html1 = str(html1, 'utf-8')
    #print(html1)
    pat1 = '<div class="w1180 clearfix">.+? <div class="pages">'
    result1 = re.compile(pat1,re.S).findall(html1)
    result1 = result1[0]
    # print(result1)
    pat2 = 'href="(http://www.win4000.com/.+?\.html)".+?title=".+?"'
    fin = re.compile(pat2, re.S).findall(result1)
    global x
    for iu in fin:
        try:
            os.mkdir("/home/sgming/Ms/Media/work/junshi/"+str(x))
        except Exception as e:
            print("exist")

        down(iu, x, 1)
        print("page:", page, " ", x)
        for i in range(2, 10):
            down(iu[0:-5]+"_"+str(i)+'.html', x, i)
        x += 1


def down(url, zhuti, num):
    try:
        html2 = urllib.request.urlopen(url).read()
        html2 =str(html2,'utf-8')
    except urllib.error.URLError as e:
        print("none")
        return
    p1 = '<div class="paper-down">.+?(http:.+?\.jpg).down"'
    rs1 = re.compile(p1, re.S).findall(html2)
    try:
        rs1 = rs1[0]
    except Exception as e:
        print("rs1 is none")
    print("rs1:",rs1)
    imagename = "/home/sgming/Ms/Media/work/junshi/"+str(zhuti)+'/'+str(num)+".jpg"
    try:
        urllib.request.urlretrieve(rs1, filename=imagename)
        print("down finish", imagename)
    except Exception as e:
        print('down fialed:',str(e))

for i in range(1, 6):
    url = "http://www.win4000.com/wallpaper_194_0_10_"+str(i)+".html"
    craw(url, i)
end = time.clock()
print("time consum:", str(end-start))
