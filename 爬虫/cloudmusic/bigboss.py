# -*-coding:utf-8-*-
'author:guoya'
import os
import time
import json
import base64
import requests
import codecs
from Crypto.Cipher import AES


class CommentCrawl(object):
    '''评论的API封装成一个类，直接传入评论的API，再调用函数get_song_comment()和get_album_comment()即可分别获取歌曲和专辑的评论信息 '''

    def __init__(self, comment_url):
        self.comment_url = comment_url
        self.headers = {
            "Referer": "http://music.163.com/song?id=551816010",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.101 Safari/537.36",
        }

    # 生成长度为16的随机字符串作为密钥secKey
    def createSecretKey(self, size):
        return (''.join(map(lambda xx: (hex(ord(xx))[2:]), str(os.urandom(size)))))[0:16]

    # 进行aes加密
    def aesEncrypt(self, text, secKey):
        pad = 16 - len(text) % 16
        # print("leix")
        # print(type(text))
        #print(type(pad * chr(pad)))
        if isinstance(text, bytes):
            # print("type(text)=='bytes'")
            text = text.decode('utf-8')
        text = text + str(pad * chr(pad))
        encryptor = AES.new(secKey, AES.MODE_CBC, '0102030405060708')

        ciphertext = encryptor.encrypt(text)
        ciphertext = base64.b64encode(ciphertext)
        return ciphertext

    # 进行rsa加密
    def rsaEncrypt(self, text, pubKey, modulus):
        text = text[::-1]
        #rs = int(text.encode('hex'), 16) ** int(pubKey, 16) % int(modulus, 16)
        rs = int(codecs.encode(text.encode('utf-8'), 'hex_codec'),
                 16) ** int(pubKey, 16) % int(modulus, 16)
        return format(rs, 'x').zfill(256)

    # 将明文text进行两次aes加密获得密文encText，因为secKey是在客户端上生成的，所以还需要对其进行RSA加密再传给服务端
    def encrypted_request(self, text):
        modulus = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7'
        nonce = '0CoJUm6Qyw8W8jud'
        pubKey = '010001'
        text = json.dumps(text)
        secKey = self.createSecretKey(16)
        encText = self.aesEncrypt(self.aesEncrypt(text, nonce), secKey)
        encSecKey = self.rsaEncrypt(secKey, pubKey, modulus)
        data = {
            'params': encText,
            'encSecKey': encSecKey
        }
        return data

    def get_post_req(self, url, data):
        try:
            req = requests.post(url, headers=self.headers, data=data)
            print(u"已连接上网易云音乐")
        except Exception as e:
            print(url)
            print(e)
        if(req == ""):
            print(u"什么都没有抓取到")
        else:
            # print(req.json())
            # 这里我们就得到了所有的json格式的评论了，并把它写进了txt文本
            with codecs.open(filename, 'a', encoding='utf-8') as f:
                f.writelines(req.text)
        print("----------------")
        return req.json()

    # 偏移量
    def get_offset(self, offset):
        if offset == 0:
            text = {'rid': '', 'offset': '0', 'total': 'true',
                    'limit': '20', 'csrf_token': ''}
        else:
            text = {'rid': '', 'offset': '%s' % offset,
                    'total': 'false', 'limit': '20', 'csrf_token': ''}
        return text

    # 得到json格式的评论
    def get_json_data(self, url, offset):
        text = self.get_offset(offset)
        data = self.encrypted_request(text)
        json_text = self.get_post_req(url, data)
        return json_text

    def get_song_comment(self):
        '''某首歌下前两页评论 '''

        comment_info = []
        data = self.get_json_data(self.comment_url, offset=0)
        comment_count = 40
        # comment_count =
        if comment_count:
            comment_info.append(data)
        if comment_count > 20:
            for offset in range(20, int(comment_count), 20):
                print(u"开始爬取第{}页".format(offset / 20))
                comment = self.get_json_data(self.comment_url, offset=offset)
                comment_info.append(comment)
        return comment_info


def save_to_file(list, filname):
    with codecs.open(filename, 'a', encoding='utf-8') as f:
        f.writelines(list)

    print(u"写入文件成功!")


start_time = time.time()
filename = "rock.txt"
comment_url = 'https://music.163.com/weapi/v1/resource/comments/R_SO_4_324513?csrf_token='
all_coment = []
craw_song_pinglun = CommentCrawl(comment_url)
print(u"开始")
all_coment = craw_song_pinglun.get_song_comment()
print("--------------")


end_time = time.time()  # 结束时间
print(u"程序耗时%f秒." % (end_time - start_time))
print(u"已完成")
