import re
import urllib.request
url='http://www.win4000.com/wallpaper_197_0_10_1.html'
s = urllib.request.urlopen(url).read().decode('utf-8')
pat = 'heet.*?(http://.*?)"'
#print(s)
pat2 = '<div class="w1180 clearfix">.+?.+?<div class="pages">'
fin = re.compile(pat2,re.S).findall(s)
fin=fin[0]
pat3 ='href="(http://www.win4000.com/.+?\.html)".+?title="(.+?)"'
fin =re.compile(pat3,re.S).findall(fin)
for con in fin:
    print(con[1])
