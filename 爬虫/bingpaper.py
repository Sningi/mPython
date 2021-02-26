import re
import urllib.request
import datetime


def open_url(url):
    headers = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.3")
    opener = urllib.request.build_opener()
    opener.addheaders = [headers]
    data = opener.open(url).read()
    data = data.decode('utf-8')
    return data


def find_pic_url(http_response):
    # print(http_response)
    paturl = '<url>.+?</url'
    patname = '<copyright>.+?</copyright>'
    urllist = re.compile(paturl, re.S).findall(http_response)
    namelist = re.compile(patname, re.S).findall(http_response)
    name_copyright_pat = '(.+?)'
    # del_substr=re.compile(name_copyright_pat)
    x = 0
    for image in urllist:
        #
        save_url_image("http://cn.bing.com/" + str(image[6:-5]).replace(
            "1366x768", "1920x1080"), "bing/" + str(re.sub(u"\\(.*?\\)", "", str(namelist[x][12:-12]))) + ".jpg")
        x += 1


def save_url_image(url, save_addr):
    print(url, save_addr)
    try:
        urllib.request.urlretrieve(url, filename=save_addr)
        print("down finish", save_addr)
    except Exception as e:
        print("faied", save_addr)
        print(e)


for i in range(1, 2):
    print("page:", i)
    temp_str = "http://cn.bing.com/HPImageArchive.aspx?format=xml&idx=%d&n=100" % i
    response = open_url(temp_str)
    find_pic_url(response)
