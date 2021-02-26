import requests
import os
import json
import re

def getsonglrc(songid, songname, songsinger):
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
    fhandle = open('./'+songname + " " +
                   songsinger+" "+songid+".txt", 'a')
    fhandle.write(lrc)
    fhandle.close()
    print(songname+"：歌词下载完成")



if __name__ == '__main__':
    getsonglrc("526464145","喜欢","阿肆")