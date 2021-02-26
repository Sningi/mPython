from bs4 import BeautifulSoup
import requests
import codecs
import time
import resource
import random


class Item(object):
    top_num = None
    score = None
    mvName = None
    singer = None
    releasTime = None


class GetMvList(object):
    def __init__(self):
        self.urlBase = 'http://vchart.yinyuetai.com/vchart/trends?'
        self.areasDic = {'ML': 'MainLand', 'HT': 'HongKong&Taiwan',
                         'US': 'Americ', 'KR': 'Korea', 'JP': 'Japan'}
        self.getUrls()

    def getUrls(self):
        areas = ['ML', 'HT', 'US', 'KR', 'JP']
        pages = [str(i) for i in range(1, 4)]
        for area in areas:
            urls = []
            for page in pages:
                urlEnd = 'area=' + area + '&page=' + page
                url = self.urlBase + urlEnd
                urls.append(url)
            self.spider(area, urls)

    def getResponseContent(self, url):
        fakeHeaders = {'user-agent': self.getRandomHeader()}
        proxies = self.getRandomProxy()
        try:
            r = requests.get(url, headers=fakeHeaders,
                             proxies=proxies, timeout=30)
            r.raise_for_status()
            r.encoding = r.apparent_encoding
            time.sleep(1)
            return r.text
            # print(r.text)
        except:
            return

    def spider(self, area, urls):
        items = []
        for url in urls:
            html = self.getResponseContent(url)
            if not html:
                continue
            soup = BeautifulSoup(html, 'lxml')
            tags = soup.find_all('li', attrs={'name': 'dmvLi'})
            # tags = soup.find_all('li',attrs={'class','vitem J_li_toggle_date'})
            for tag in tags:
                item = Item()
                item.top_num = tag.find(
                    'div', attrs={'class': 'top_num'}).get_text()
                # if tag.find('h3',attrs={'class':'desc_score'}):
                #   item.score = tag.find('h3',attrs={'class':'des_score'}).text()
                # else:
                #   item.score = tag.find('h3',attrs={'class':'asc_score'}).get_text()
                item.mvName = tag.find('img').get('alt')
                item.singer = tag.find(
                    'a', attrs={'class': 'special'}).get_text()
                item.releasTime = tag.find(
                    'p', attrs={'class': 'c9'}).get_text()
                items.append(item)
        self.sava(items, area)
        # print(items[0])

    def getRandomProxy(self):
        return random.choice(resource.PROXIES)

    def getRandomHeader(self):
        return random.choice(resource.UserAgents)

    def sava(self, items, area):
        fileName = 'mvTopList.txt'
        nowTime = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        with codecs.open(fileName, 'w', 'utf8') as fp:
            fp.write('%s --------%s\r\n' % (self.areasDic.get(area), nowTime))
            for item in items:
                fp.write('%s  \t %s \t %s \t %s \r\n' % (
                    item.top_num, item.releasTime, item.singer, item.mvName))
        print('success')


if __name__ == '__main__':
    GML = GetMvList()
