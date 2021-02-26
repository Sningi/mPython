# -*- coding:utf-8 -*-
import EncryptUtil
import json
import requests
import time
#import DataBase
#import Logger

#logger = Logger.Log()

class Crawler(object):

    def __init__(self,id):
        modulus = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7'
        self.nonce = '0CoJUm6Qyw8W8jud'
        pubKey = '010001'
        self.secKey = EncryptUtil.createSecretKey(16)
        self.encSecKey = EncryptUtil.rsaEncrypt(self.secKey, pubKey, modulus)
        #self.mysql = DataBase.Mysql()
        self.musicId = id
        self.requestUrl = "http://music.163.com/weapi/v1/resource/comments/R_SO_4_%d/"%int(id)

        self.headers = {
        'Host': 'music.163.com',
        'Connection': 'keep-alive',
        'Content-Length': '484',
        'Cache-Control': 'max-age=0',
        'Origin': 'http://music.163.com',
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.84 Safari/537.36',
        'Content-Type': 'application/x-www-form-urlencoded',
        'Accept': '*/*',
        'DNT': '1',
        'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'zh-CN,zh;q=0.8,en;q=0.6,zh-TW;q=0.4',
        'Cookie': 'JSESSIONID-WYYY=b66d89ed74ae9e94ead89b16e475556e763dd34f95e6ca357d06830a210abc7b685e82318b9d1d5b52ac4f4b9a55024c7a34024fddaee852404ed410933db994dcc0e398f61e670bfeea81105cbe098294e39ac566e1d5aa7232df741870ba1fe96e5cede8372ca587275d35c1a5d1b23a11e274a4c249afba03e20fa2dafb7a16eebdf6%3A1476373826753; _iuqxldmzr_=25; _ntes_nnid=7fa73e96706f26f3ada99abba6c4a6b2,1476372027128; _ntes_nuid=7fa73e96706f26f3ada99abba6c4a6b2; __utma=94650624.748605760.1476372027.1476372027.1476372027.1; __utmb=94650624.4.10.1476372027; __utmc=94650624; __utmz=94650624.1476372027.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none)',
        }

    def getComment(self, offset):
        text = {
            'username': "17739458175",
            'password': "s96097019mg",
            'rememberLogin': 'true',
            'offset': offset
        }
        text = json.dumps(text)
        encText = EncryptUtil.aesEncrypt(EncryptUtil.aesEncrypt(text, self.nonce), self.secKey)
        data = {
            'params': encText,
            'encSecKey': self.encSecKey
        }
        res = requests.post(self.requestUrl,headers=self.headers, data=data)
        jsonData = res.json()
        self.databaseSave(jsonData)
        return int(jsonData["total"])

    def databaseSave(self ,jsonData):
        
        for comment in jsonData["comments"]:
            print(str(comment["commentId"]),
            str(comment["user"]["userId"]),
            comment["content"].encode('utf-8'),
            str(comment["likedCount"]),
            str(EncryptUtil.timeStamp(comment["time"])), )
            '''
            commentData = {
                'id': str(comment["commentId"]),
                'user': str(comment["user"]["userId"]),
                'content': comment["content"].encode('utf-8'),
                'likeCount': str(comment["likedCount"]),
                'commentTime': str(EncryptUtil.timeStamp(comment["time"])),
                'musicId': str(self.musicId)
            }
            if not comment["beReplied"] == []:
                commentData["reComment"] = str(comment["beReplied"][0]["user"]["userId"])
            userData = {
                'id': str(comment["user"]["userId"]),
                'username': comment["user"]["nickname"].encode('utf-8'),
                'avatarUrl': comment["user"]["avatarUrl"].encode('utf-8')
            }
        '''
            '''
            if self.mysql.insertData("comment",commentData) >= 0:
                logger.info("Comment %s Saved."%commentData["id"])

            userData = {
                'id': str(comment["user"]["userId"]),
                'username': comment["user"]["nickname"].encode('utf-8'),
                'avatarUrl': comment["user"]["avatarUrl"].encode('utf-8')
            }
            if self.mysql.insertData("user",userData) >= 0:
                logger.info("User %s Saved."%userData["id"])
            '''

    def process(self, offset):
        if offset == -1:
            return
        off = offset
        total = self.getComment(off)
        while off<total:
             off += 10
             self.getComment(off)
        self.taskSchedule.trigger(self.musicId,"-1")


def main():
    c = Crawler(5279721)
    c.process(1)

if __name__ == '__main__':
    main()