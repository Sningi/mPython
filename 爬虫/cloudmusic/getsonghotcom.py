import requests
import json
import os
from Crypto.Cipher import AES
import base64
import codecs


def aesEncrypt(text, secKey):
    pad = 16 - len(text) % 16
    if isinstance(text, bytes):
        # print("type(text)=='bytes'")
        text = text.decode('utf-8')
    # print(type(text))
    text = text + str(pad * chr(pad))
    encryptor = AES.new(secKey, 2, '0102030405060708')
    ciphertext = encryptor.encrypt(text)
    ciphertext = base64.b64encode(ciphertext)
    return ciphertext


def rsaEncrypt(text, pubKey, modulus):
    text = text[::-1]
    #   rs = int(text.encode('hex'), 16)**int(pubKey, 16)%int(modulus, 16)
    rs = int(codecs.encode(text.encode('utf-8'), 'hex_codec'),
             16) ** int(pubKey, 16) % int(modulus, 16)
    return format(rs, 'x').zfill(256)


modulus = '00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7'
nonce = '0CoJUm6Qyw8W8jud'
pubKey = '010001'


def createSecretKey(size):
    return (''.join(map(lambda xx: (hex(ord(xx))[2:]), str(os.urandom(size)))))[0:16]


def get_it_comments(url):

    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36'}
    comment_list = []
    count = 0
    for i in range(1):
        # 一个i获取10个评论
        text = {
            'username': '',
            'password': '',
            'rememberLogin': 'true',
            'offset': i * 10
        }
        text = json.dumps(text)
        secKey = createSecretKey(16)
        encText = aesEncrypt(aesEncrypt(text, nonce), secKey)
        encSecKey = rsaEncrypt(secKey, pubKey, modulus)
        payload = {
            'params': encText,
            'encSecKey': encSecKey
        }

        r = requests.post(url, headers=headers, data=payload)
        r.raise_for_status()
        try:
            r_dic = json.loads(r.text)
        except:
            print("json.loads(r.text)出错了")
        # print(r_dic)
        comments = r_dic['hotComments']
        print(len(comments))
        for comment in comments:
            print(count, comment['content'])
            comment_list.append([count, comment['content']])
            count += 1
    return comment_list


def get_save_hotcoms(count, songid, songname, songsinger):
    dic_keywords = {}
    url = 'http://music.163.com/weapi/v1/resource/comments/R_SO_4_' + songid + '?csrf_token='
    comments_lst = get_it_comments(url)
    #assert comments_lst, 'comments_lst is Null'
    print("曲名：" + songname + '爬取完成')
    # 写入文件 a 即append 末尾添加模式
    fhandle = open(str(count) + "." + songname +
                   " " + songsinger + " " + songid + ".txt", 'a')

    for i, comment in comments_lst:
        print(i, comment)
        fhandle.write('\n------------------------------\n')
        fhandle.write(str(i) + ":" + str(comment))
    fhandle.close()


if __name__ == '__main__':
    count = 1
    songid = '448590500'
    songname = 'py'
    songsinger = 'xx'
    get_save_hotcoms(count, songid, songname, songsinger)
