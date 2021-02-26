import sys
import time
from urllib import request

User_Agent = ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.117 Safari/537.36")
opener = request.build_opener()
opener.addheaders = [User_Agent]
request.install_opener(opener)


'''
 urllib.urlretrieve 的回调函数：
def callbackfunc(blocknum, blocksize, totalsize):
    @blocknum:  已经下载的数据块
    @blocksize: 数据块的大小
    @totalsize: 远程文件的大小
'''


def Schedule(blocknum, blocksize, totalsize):
    speed = (blocknum * blocksize) / (time.time() - start_time)
    # speed_str = " Speed: %.2f" % speed
    speed_str = " Speed: %s" % format_size(speed)
    recv_size = blocknum * blocksize
    # total_str = " file size: %s" % format_size(int(totalsize))
    # 设置下载进度条
    f = sys.stdout
    pervent = recv_size / totalsize
    percent_str = "%.2f%%" % (pervent * 100)
    n = round(pervent * 50)
    s = ('#' * n).ljust(50, '-')
    f.write(percent_str.ljust(8, ' ') + '[' + s + ']' + speed_str)
    f.flush()
    # time.sleep(0.1)
    f.write('\r')

# 字节bytes转化K\M\G


def format_size(bytes):
    try:
        bytes = float(bytes)
        kb = bytes / 1024
    except:
        print("传入的字节格式不对")
        return "Error"
    if kb >= 1024:
        M = kb / 1024
        if M >= 1024:
            G = M / 1024
            return "%.3fG" % (G)
        else:
            return "%.3fM" % (M)
    else:
        return "%.3fK" % (kb)


if __name__ == '__main__':
    print(format_size(26653618))
    start_time = time.time()
    filename = 'eyevideo/' + sys.argv[2] + '.mp4'
    url = 'https://baobab.kaiyanapp.com/api/v1/playUrl?vid=' + \
        sys.argv[1] + '&resourceType=video&editionType=default&source=aliyun'
    request.urlretrieve(url, filename, Schedule)
