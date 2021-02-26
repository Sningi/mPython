import re
import urllib.request
import urllib.error
from beans_progress import ProgressBar

User_Agent = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36")
referer = (
    "Referer", "https://static.hdslb.com/play.swf?cid=30062526&aid=18419262&pre_ad=")
oR = ("Origin", "https://www.bilibili.com")

opener = urllib.request.build_opener()
opener.addheaders = [User_Agent]
opener.addheaders = [referer]

urllib.request.install_opener(opener)

# GET /vg3/upgcxcode/27/25/30062527/30062527-1-32.flv?expires=1524507600&platform=pc&ssig=zDPy7qNCPmItRI8GR3hXNA&oi=1972855779&nfa=uTIiNt+AQjcYULykM2EttA==&dynamic=1&hfa=2028808926&hfb=Yjk5ZmZjM2M1YzY4ZjAwYTMzMTIzYmIyNWY4ODJkNWI=&trid=a6ec1b363de744b8b313f091bc3d148e HTTP/1.1


#url = 'http://baobab.kaiyanapp.com/api/v1/playUrl?vid=18973&resourceType=video&editionType=normal&source=aliyun'
imagename = "/home/sgming/Ms/Media/work/video/5.mp4"
# https://cn-zjtz-cmcc-v-03.acgvideo.com/vg3/upgcxcode/27/25/30062527/30062527-1-32.flv?expires=1524538800&platform=pc&ssig=XC0ksMbIRBHj9j9MVC3rqQ&oi=1972855779&nfa=uTIiNt+AQjcYULykM2EttA==&dynamic=1&hfa=2028839170&hfb=Yjk5ZmZjM2M1YzY4ZjAwYTMzMTIzYmIyNWY4ODJkNWI=&trid=fc46e16acec04adfb87e45b87312837b
url = 'https://cn-zjtz-cmcc-v-03.acgvideo.com/vg3/upgcxcode/27/25/30062527/30062527-1-32.flv?expires=1524538800&platform=pc&ssig=XC0ksMbIRBHj9j9MVC3rqQ&oi=1972855779&nfa=uTIiNt+AQjcYULykM2EttA==&dynamic=1&hfa=2028839170&hfb=Yjk5ZmZjM2M1YzY4ZjAwYTMzMTIzYmIyNWY4ODJkNWI=&trid=fc46e16acec04adfb87e45b87312837b'
try:
    urllib.request.urlretrieve(url, filename=imagename)
    print("down finish:", imagename)
except Exception as e:
    print('down fialed:', str(e))
