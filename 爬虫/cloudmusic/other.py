import requests
import os
import json
import re
import time
import queue
import zhihu
from scrapy.selector import Selector


#歌曲队列
songqueue = queue.Queue()

class wangyiyun():
    def __init__(self):
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36',
            'Referer': 'http://music.163.com/'}
        self.main_url = 'http://music.163.com/'
        self.session = requests.Session()
        self.session.headers.update(self.headers)

    def get_songurls(self, playlist):
        '''进入所选歌单页面，得出歌单里每首歌各自的ID 形式就是“song?id=64006"'''
        url = self.main_url+'playlist?id=%d' % playlist
        re = self.session.get(url)  # 直接用session进入网页，懒得构造了
        sel = Selector(text=re.text)  # 用scrapy的Selector，懒得用BS4了
        songurls = sel.xpath('//ul[@class="f-hide"]/li/a/@href').extract()
        return songurls  # 所有歌曲组成的list

    def getHotComments(self, id):  # 这里的id是歌曲的id
        url = 'http://music.163.com/weapi/v1/resource/comments/R_SO_4_' + \
            str(id)+'?csrf_token=c0f6bfdcd0526ec0ba6c207051a08960'

        param = {'params': 'wxLqdGgw16OHb6UwY/sW16VtLqAhGaDMeI2F4DaESDplHA+CPsscI4mgiKoVCPuWW8lcd9eY0YWR/iai0sJqs0NmtLubVCkG\
        dpNTN3mLhevZpdZy/XM1+z7L18InFz5HbbRkq230i0aOco/3jVsMWcD3/tzzOCLkGuu5xdbo99aUjDxHwDSVfu4pz4spV2KonJ47Rt6vJhOorV7LfpIVmP/qeZghfaXXuKO2chlqU54=',
                 'encSecKey': '12d3a1e221cd845231abdc0c29040e9c74a47ee32eb332a1850b6e19ff1f30218eb9e2d6d9a72bd797f75fa115b769ad580fc51128cc9993e51276043ccbd9ca4e1f589a2ec479ab0323c973e7f7b1fe1a7cd0a02ababe2adecadd4ac93d09744be0deafd1eef0cfbc79903216b1b71a82f9698eea0f0dc594f1269b419393c0'}
        r = requests.post(url, param)
        data = r.text
        jsob = json.loads(data)  # 加载获取的json数据，获得json对象
        hotComments = jsob['hotComments']

        return hotComments

    def get_songinfos(self, songurls):
        '''根据songid进入每首歌对应的url，拿到歌手名字，url就是:"http://music.163.com/song?id=64006"'''
        num=0
        fhandle=open('./xiaoya/xiaoya_歌单','a')  #写入文件
        for songurl in songurls:
            url = self.main_url+songurl
            re = self.session.get(url)
            sel = Selector(text=re.text)
            song_id = url.split('=')[1]
            song_name = sel.xpath(
                "//em[@class='f-ff2']/text()").extract_first()
            singer = '&'.join(
                sel.xpath("//p[@class='des s-fc4']/span/a/text()").extract())

            num+=1
            fhandle.write(str(num)+'.'+str(song_name)+" "+str(singer)+" "+str(song_id)+'\n')
            print(song_id, song_name, singer)
            con={'id':song_id,'name':song_name,'singer':singer}
            songqueue.put(con)
            songqueue.task_done()
        fhandle.close()
    def work(self, playlist):
        songurls = self.get_songurls(playlist)
        self.get_songinfos(songurls)

if __name__ == '__main__':
    d = wangyiyun()
    d.work(724147711)
    count=1
    processing=True
    while (processing):
        con = songqueue.get()
        if(count<3):
            songid = con['id']
            songname = con['name']
            songsinger=con['singer']
            zhihu.get_and_save_top_keywords(count,str(songid), songname, songsinger)
            count += 1
        if(songqueue.empty()):
            processing=False