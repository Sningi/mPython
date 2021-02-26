# !/user/bin/env python
# -*- coding: utf-8 -*-
import os
import queue
import threading
import time
import re
import pycurl
import random

User_Agents = [
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36',
    'Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML like Gecko) Chrome/44.0.2403.155 Safari/537.36',
    'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36',
    'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.1 Safari/537.36',
    'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.0 Safari/537.36',
    'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.0 Safari/537.36',
    'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2226.0 Safari/537.36',
    'Mozilla/5.0 (Windows NT 6.4; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2225.0 Safari/537.36',
    'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2225.0 Safari/537.36',
]

# 去除文件无效字符


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title


# 合并转换为mp4格式
def convert_mp4(ts_path):
    # 读取ts文件夹下所有的ts文件
    path_list = os.listdir(ts_path)
    # # 对文件进行排序
    path_list.sort(key=lambda x: int(x[:-3]))
    # 将排序后的ts的绝对路径放入列表中
    li = [os.path.join(ts_path, filename)
          for filename in path_list if filename.endswith(".ts")]
    # 类似于[001.ts|00.2ts|003.ts]
    input_file = ''
    output_file = ''
    for i, ts in enumerate(li):
        input_file += ts + "|"
        output_file = ts_path + "_" + str(int(i / 1000))
        if (i + 1) % 1000 == 0:
            # input_file = '|'.join(li)
            # 指定输出文件名称
            # 使用ffmpeg将ts合并为mp4
            command = 'ffmpeg  -y -i  "concat:%s" -acodec copy -vcodec copy -absf aac_adtstoasc mp4/%s.mp4' % (
                input_file, output_file)
            input_file = ''
            # 指行命令
            os.system(command)
    command = 'ffmpeg  -y -i  "concat:%s" -acodec copy -vcodec copy -absf aac_adtstoasc mp4/%s.mp4' % (
        input_file, output_file)
    os.system(command)


def saveM3u8(url, filename, userAgents):
    if os.path.exists(filename):
        print("File existed: %s skip" % filename)
        return True
    try:
        curl = pycurl.Curl()
        curl.setopt(pycurl.USERAGENT, random.choice(userAgents))
        curl.setopt(pycurl.URL, url)
        with open(filename, 'wb') as f:
            curl.setopt(pycurl.WRITEDATA, f)
            curl.perform()
        return True
    except Exception as err:
        print(f'Get list.meu8 failed:({url})\n', err)
        return False

# 解析ts队列


def parseM3u8(url_m3u8, file_name, taskQueue):
    print('begin parseing ...')
    sum = 0
    # 读文件的操作
    f = open(file_name, 'r')
    for line in f:  # 循环读取每行
        tempName_ts = line[:-1]  # 去除换行
        if not '.ts' in line:
            continue
        else:
            if not line.startswith('http'):
                line = url_m3u8.replace(url_m3u8.split('/')[-1], line[:-1])
            taskQueue.put((line, tempName_ts))
            sum += 1
            # print("第%d 次： %s 入列" % (sum, line))
    f.close()
    print("共计 %d 个ts文件" % sum)


class Consumer(threading.Thread):
    def __init__(self, urlqueue, ts_path, proxy, userAgents):
        threading.Thread.__init__(self)
        self.urlqueue = urlqueue
        self.ts_path = ts_path
        self.proxy = proxy
        self.curl = pycurl.Curl()
        self.curl.setopt(pycurl.CONNECTTIMEOUT, 20)
        self.finishSet = set()
        self.userAgents = userAgents
        if not os.path.exists(ts_path):
            os.mkdir(ts_path)
        logtxt = "%s_finished.txt" % self.ts_path
        if not os.path.exists(logtxt):
            temp = open(logtxt, 'w')
            temp.close()
        else:
            with open(logtxt, 'r') as f:
                for i in f.readlines():
                    self.finishSet.add(i[:-1])
        self.logfile = open(logtxt, "ab+", buffering=0)

    def run(self):
        while(not self.urlqueue.empty()):
            if self.urlqueue.empty():
                print("queue is empty")
                time.sleep(3)
            else:
                con = self.urlqueue.get()
                url_ts = con[0]
                tempName_ts = con[1]
                # print("第%d次出列：%s 剩余数目：%d" %
                #       (subcount, tempName_ts, self.urlqueue.qsize()))
                self.downTs(url_ts, tempName_ts)  # 下载视频流
        print(str(self) + " 出列结束")
    # 下载ts文件

    def downTs(self, url, file_name, fullPath=False):
        if not fullPath:
            file_name = "%s/%s" % (self.ts_path, file_name)
        if os.path.exists(file_name):
            if file_name in self.finishSet:
                print("Aready finished: ", file_name,
                      '剩余数目：', self.urlqueue.qsize())
                return
        if self.proxy:
            down_cmd = "curl -x %s -o %s %s" % (
                self.proxy, file_name, url)
        else:
            down_cmd = "curl -o %s %s" % (file_name, url)
        try:
            self.downFileByCurl(url, file_name)
            self.finishSet.add(file_name)
            self.logfile.write(file_name.encode('utf-8') + b"\n")
            print("下载完成：", url, '\t| 剩余数目：', self.urlqueue.qsize())
        except Exception as e:
            print(e)
            if os.path.exists(file_name):
                os.remove(file_name)
            print("Retry: ", url)
            self.downTs(url, file_name, fullPath=True)

    def downFileByCurl(self, url, filename):
        self.curl.setopt(pycurl.USERAGENT, random.choice(self.userAgents))
        self.curl.setopt(pycurl.URL, url)
        with open(filename, 'wb') as f:
            self.curl.setopt(pycurl.WRITEDATA, f)
            self.curl.perform()

    def __del__(self):
        self.logfile.close()
        finishlist = list(self.finishSet)
        finishlist.sort(key=lambda x: int(x[len(self.ts_path) + 1:-3]))
        with open("%s_finished.txt" % self.ts_path, 'w') as f:
            for i in finishlist:
                f.write(i + '\n')


def downVideo(url_m3u8, ts_path, userAgents, consumer=3):
    print("Downloading %s ..." % ts_path)
    taskQueue = queue.Queue()
    list_name = '%s.m3u8' % ts_path
    if saveM3u8(url_m3u8, list_name, userAgents):
        parseM3u8(url_m3u8, list_name, taskQueue)
    proxy = None
    # proxy = '127.0.0.1:8123'
    for i in range(consumer):
        g2 = Consumer(urlqueue=taskQueue, ts_path=ts_path,
                      proxy=proxy, userAgents=userAgents)
        g2.start()
        time.sleep(1)


if __name__ == '__main__':
    url = "https://www.youyouww.com/filets/5691/list.m3u8"
    pat1 = r"/(\d+?)/"
    ts_path = re.compile(pat1, re.S).findall(url)[0]
    ts_path='4950'
    finish = True
    if not finish:
        downVideo(url_m3u8=url, ts_path=ts_path,
                  userAgents=User_Agents, consumer=5)
    else:
        convert_mp4(ts_path)
    # os.system("rm -r %s" % path)
