import requests
import re
from bs4 import BeautifulSoup
import os

# 爬取的网站：http://www.win4000.com/wallpaper_detail_54520.html


def Get_image_url(url):
    # 传入页面的URL，得到所有图片所在的标签和图册的名字，并返回

    Res = requests.get(url)
    Soup = BeautifulSoup(Res.text, 'lxml')

    Name = Soup.select('h1')[0].string
    Tag = 'img[title=\"' + Name + '\"]'
    Image = Soup.select(Tag)

    return Image, Name


def Download_Image(PATH,Image_url):
    # 传入图片的URL，将图片保存在本地
    Image = requests.get(Image_url, stream=True)
    # 将链接的最后一个字符串最为图片的名字
    name = PATH+Image_url.split('/')[-1]
    # 白村图片
    with open(name, 'wb') as f:
        f.write(Image.content)


def Get_index_image(Url):
    Res = requests.get(Url)
    Reg = r'<a href="(.+?)" title=.+? target='
    Reg = re.compile(Reg)
    Image = re.findall(Reg, Res.text)
    Image = set(Image)
    Image = [i for i in Image if len(i) > 49]
    return Image


def main(url):
    # 主调函数
    #url = "http://www.win4000.com/wallpaper_detail_54520.html"
    [Image, Name] = Get_image_url(url)
    # print(Name,Image)
    # 保存当前目录
    path = os.getcwd()
    # 创建保存图片的目录
    print(path)
    if (not os.path.exists(Name)):
        os.mkdir(Name)
        os.chdir(path + '/' + Name)
        newPath=path+'/'+Name
        for I in Image:
            Download_Image(PATH,I['src'])
        # 返回之前的目录
        os.chdir(path)
        print(Name+'\n')
    else:
        print(Name + " 已经下载过了")


if __name__ == '__main__':
    Main_Url = "http://www.win4000.com/wallpaper_192_0_0_1.html"
    Url = Get_index_image(Main_Url)
    for u in Url:
        main(u)
    print("下载完成！")
