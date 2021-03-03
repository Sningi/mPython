
import requests
from bs4 import BeautifulSoup
import re

import os

from enum import Enum


class Pages(Enum):

    page1 = 'http://www.stats.gov.cn/was5/web/search?page=1&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E5%95%86%E5%93%81%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page2 = 'http://www.stats.gov.cn/was5/web/search?page=2&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E5%95%86%E5%93%81%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page3 = 'http://www.stats.gov.cn/was5/web/search?page=3&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E5%95%86%E5%93%81%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page4 = 'http://www.stats.gov.cn/was5/web/search?page=4&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E5%95%86%E5%93%81%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    
    page5 = 'http://www.stats.gov.cn/was5/web/search?page=4&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page6 = 'http://www.stats.gov.cn/was5/web/search?page=5&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page7 = 'http://www.stats.gov.cn/was5/web/search?page=6&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page8 = 'http://www.stats.gov.cn/was5/web/search?page=7&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page9 = 'http://www.stats.gov.cn/was5/web/search?page=8&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'
    page10 = 'http://www.stats.gov.cn/was5/web/search?page=9&channelid=288041&orderby=-DOCRELTIME&was_custom_expr=like%2870%E4%B8%AA%E5%A4%A7%E4%B8%AD%E5%9F%8E%E5%B8%82%E4%BD%8F%E5%AE%85%E9%94%80%E5%94%AE%E4%BB%B7%E6%A0%BC%E5%8F%98%E5%8A%A8%E6%83%85%E5%86%B5%29%2Fsen&perpage=20&outlinepage=10'


_path = "./data/"


def down_html(filename, url, refresh=False):
    if not os.path.exists(filename) or refresh:
        data = requests.get(url)
        html = str(data.content, 'utf-8')
        with open(filename, 'w', encoding='utf-8') as f:
            f.writelines(html)
    else:
        # print("existed, skip")
        pass


def get_list(refresh=False):
    for name, page in Pages.__members__.items():
        down_html(_path+name + ".html", page.value, refresh)


def gen_month_list(refresh=False):
    for name, page in Pages.__members__.items():
        if not os.path.exists(_path+ "list_"+name) or refresh:
            with open(_path+name+'.html', 'r', encoding='utf-8') as lf:
                html = str(lf.readlines())
                soup = BeautifulSoup(html, 'lxml')
                ul = soup.find('ul', 'center_list_contlist')
                all_li = ul.find_all("li")
                with open(_path+ "list_"+name, 'w', encoding='utf-8') as hf:
                    for li in all_li:
                        link = re.compile(
                            r"urlstr = '(http://www.stats.gov.cn/tjsj/zxfb/.*?.html)'", re.S)
                        ret = set(link.findall(str(li)))
                        for e in ret:
                            hf.write(e+'\n')


def decre_month(raw_str):
    year = int(raw_str[:4])
    month = int(raw_str[4:])
    if month - 1 == 0:
        year -= 1
        month = 12
    else:
        month -= 1
    return str(year)+'%2s' % (str(month).zfill(2))


def get_html_of_per_month(refresh=False):
    for name, page in Pages.__members__.items():
        with open(_path+"list_"+name, 'r', encoding='utf-8') as hf:
            lines = hf.readlines()
        for line in lines:
            down_html(
                _path+"data_"+decre_month(line[34:40])+".html", line.strip("\n"), refresh=False)


def judge_month():
    files = os.listdir(_path)
    for fname in files:
        if 'data_' in fname:
            with open(_path + fname, 'r', encoding='utf-8') as lf:
                html = str(lf.readlines())
                soup = BeautifulSoup(html, 'lxml')
                title = soup.title.string
                year = fname[5:9]
                month = fname[10:11]
                assert year in title
                assert str(int(month))+'月份' in title


def main():
    get_list(refresh=False)
    gen_month_list(refresh=False)
    get_html_of_per_month(refresh=False)
    judge_month()
    print("data get finish")


if __name__ == "__main__":
    main()