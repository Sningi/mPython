import re
import urllib.request


def craw(url, page):
    html1 = urllib.request.urlopen(url).read()
    html1 = str(html1)
    pat1 = '<div id="plist".+? <div class="page clearfix">'
    result1 = re.compile(pat1).findall(html1)
    result1 = result1[0]
    pat2 = r'<img width="220" height="220" data-img="1" data-lazy-img="//.+?\.jpg">'
    imagelist = re.compile(pat2).findall(result1)
    pat3 = r'img[0-9]{2,2}.360buyimg.com/.+?\.jpg'
    x = 0
    urllist = []
    for alurl in imagelist:
        urllist.append(re.compile(pat3).findall(alurl))
        x += 1
    x = 1
    for imurl in urllist:
        imagename = "/home/sgming/work/jd/" + str(page) + str(x) + ".jpg"
        imurl = "http://" + str(imurl)[2:-2]
        try:
            urllib.request.urlretrieve(imurl, filename=imagename)
            print("down finish", imagename)
        except urllib.error.URLError as e:
            if hasattr(e, "code"):
                x += 1
            if hasattr(e, "reason"):
                x += 1
        x += 1


'''
    for imurl in imagelist:
        imagename = "/home/sgming/work/jd"+str(page)+str(x)+".jpg"
        imurl = "http://"+imurl
        print(imurl)
        try:
            urllib.request.urlretrieve(imurl, filename=imagename)
        except urllib.error.URLError as e:
            if hasattr(e, "code"):
                x += 1
            if hasattr(e, "reason"):
                x += 1
            x += 1
'''

for i in range(1, 10):
    url = "https://list.jd.com/list.html?cat=670,671,672&page=" + str(i)
    craw(url, i)
