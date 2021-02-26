import urllib.request
import re
import urllib.error
import requests
opener = urllib.request.build_opener()
headers = {
    'Host': 'desk.zol.com.cn',
    'Connection': 'keep-alive',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    #    'Accept-Encoding': 'gzip, deflate',
    #  'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
    #   'Cookie': 'ip_ck=3Yyl14m6v8EuOTE5MjUwLjE1MjQyMjE1MTc%3D; visited_subcateProId=57-1147818; realLocationId=22; userFidLocationId=22; listSubcateId=57; dwhis=%22s%22%3A%2257%22%2C%22m%22%3A%2250840%22%2C%22p%22%3A%221147818%22%2C%22function%28e%29%7Breturn%22%5Bobject%20Array%5D%22%3D%3D%3D%7B%7D.toString.call%28e%29%7D%22%3A%22%22; questionnaire_close_today=1525305601; questionnaire_close_total=1; Hm_lvt_ae5edc2bc4fc71370807f6187f0a2dd0=1525392197; BDTUJIAID=e3b8220d55eec6c6737bfaedeeee198b; lv=1525451390; vn=10; Adshow=4; questionnaire_pv=1525392046'
}

opener.addheaders = [headers]
urllib.request.install_opener(opener)

trueuls = 'http://localhost/images/5.jpg'
imagename = "5" + ".jpg"

#urllib.request.urlretrieve(trueuls, filename=imagename)
html = requests.get(trueuls)
with open(imagename, 'wb') as file:
    file.write(html.content)
#data = urllib.request.urlopen(trueuls).read()
#f = open(imagename,"wb+")
# f.write(data)
# f.close()
