import requests
import os
import json
import re
import time
import queue
import getsonghotcom
from scrapy.selector import Selector


# 歌曲队列
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

    def get_songinfos(self, songurls):
        '''根据songid进入每首歌对应的url，拿到歌手名字，url就是:"http://music.163.com/song?id=64006"'''
        num = 0
        fhandle = open('./xiaoya_songlist.txt', 'a')  # 写入文件
        for songurl in songurls:
            url = self.main_url+songurl
            re = self.session.get(url)
            sel = Selector(text=re.text)
            song_id = url.split('=')[1]
            song_name = sel.xpath(
                "//em[@class='f-ff2']/text()").extract_first()
            singer = '&'.join(
                sel.xpath("//p[@class='des s-fc4']/span/a/text()").extract())

            num += 1
            fhandle.write(str(num)+'.'+str(song_name)+" " +
                          str(singer)+" "+str(song_id)+'\n')
            print(song_id, song_name, singer)
            con = {'id': song_id, 'name': song_name, 'singer': singer}
            # 歌曲信息加入队列
            songqueue.put(con)
            songqueue.task_done()
        fhandle.close()

    def work(self, playlist):
        songurls = self.get_songurls(playlist)
        self.get_songinfos(songurls)


def getsonglrc(count, songid, songname, songsinger):
    url = 'http://music.163.com/api/song/lyric?' + \
        'id=' + str(songid) + '&lv=1&kv=1&tv=-1'
    r = requests.get(url)
    json_obj = r.text
    j = json.loads(json_obj)
    lrc=''
    try:
        lrc = j['lrc']['lyric']
    except Exception as e:
        print('lrc is nulll:', str(e))
        return
    pat = re.compile(r'\[.*\]')
    lrc = re.sub(pat, "", lrc)
    lrc = lrc.strip()
    fhandle = open('./'+str(count)+"."+songname + " " +
                   songsinger+" "+songid+".txt", 'a')
    fhandle.write('\n----------歌词----------\n')
    fhandle.write(lrc)
    fhandle.close()
    print(songname+"：歌词下载完成")


if __name__ == '__main__':
    d = wangyiyun()
    d.work(724147711)
    count = 1
    processing = True
    while (processing):
        # 从队列取出并下载
        con = songqueue.get()
        songid = con['id']
        songname = con['name']
        songsinger = con['singer']
        if(count>104):
            #下载歌词
            getsonglrc(count, str(songid), songname, songsinger)
            # 延时2~3秒 避免被禁
            time.sleep(2)
        #下载热评
        #getsonghotcom.get_save_hotcoms(
        #   count, str(songid), songname, songsinger)

        count += 1

        if(songqueue.empty()):
            processing = False
