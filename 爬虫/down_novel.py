import re
import urllib.request
import urllib.error
from bs4 import BeautifulSoup
import time
count = 1
User_Agent = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36")
# referer = (
#     "Referer", "https://static.hdslb.com/play.swf?cid=30062526&aid=18419262&pre_ad=")
# oR = ("Origin", "https://www.bilibili.com")
# opener.addheaders = [referer]
opener = urllib.request.build_opener()
opener.addheaders = [User_Agent]
urllib.request.install_opener(opener)
filename = "/home/sning/Downloads/my.txt"
base_url1 = 'http://book.3g.cn/index.php?m=Book&a=content&bookid=159981&menuid='
base_url2 = '&lid=8370&wsto=0'


def savetxt(url):
    try:
        urllib.request.urlretrieve(url, filename=filename)
        print("down finish:", filename)
    except Exception as e:
        print('down fialed:', str(e))


def main():
    f = open(filename, 'a')
    for i in range(1, 6):
        url = base_url1 + str(i) + base_url2
        html = opener.open(url).read().decode('utf-8')
        soup_html = BeautifulSoup(html, 'html.parser')
        div = soup_html.find('div', id="menu_content")
        p = div.find_all('p')
        f.write("  张" + str(i) + "章" + '\n')
        print("张" + str(i) + "章")
        for child in p:
            #print('    ')
            # f.write(str(child.string))
            f.write("  " + str(child.string) + '\n')
            #print("    " + str(child.string))
            # print('\n')
        time.sleep(0.5)
    f.close()


if __name__ == '__main__':
    main()
