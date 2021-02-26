import urllib.request
import re

url = "https://blog.csdn.net/csdnsevenn/article/details/80014149"
headers = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.3")
opener = urllib.request.build_opener()
opener.addheaders = [headers]
data = opener.open(url).read()
print(str(data,'utf-8'))
data=data.decode('utf-8')
pat = '<h1 class="csdn_top">.+?</h1>'
rs = re.compile(pat).findall(data)[0]
#print(rs)
pat2='>.+?<'
rs =re.compile(pat2).findall(rs)[0][1:-1]
print(rs)