
import requests

name = '拆弹专家'
url = 'https://www.dytt8.net/html/gndy/china/list_4_'

for page in range(1,51):
    print("page :", page )
    curl =  'https://www.dytt8.net/html/gndy/china/list_4_{0}.html'.format(page)
    data = requests.get(curl)
    html = data.content.decode("gbk",errors='ignore')
    if name in html:
        print(curl)
