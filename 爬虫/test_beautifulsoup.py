import re
import time
import requests
import urllib.request


def downimage(image):
    imagename = "/home/sgming/Ms/Sgming/PL/python/数据可视化/shapes/" + image
    trueurl = 'https://wordart.com/static/creator/images/shapes/'+image
    #html = requests.get(trueurl)
    data = urllib.request.urlopen(trueurl).read()
    f = open(imagename,"wb+")
    f.write(data)  
    f.close()
    #with open(imagename, 'wb') as file:
    #   file.write(html.content)
    print(child+"下载成功")


intxt = open('select', 'r').read()
p1 = 'thumbs/(.+?png)'
list = re.compile(p1, re.S).findall(intxt)
for i,child in enumerate(list):
    print(i,child)
    if(i==382):
        downimage(child)
