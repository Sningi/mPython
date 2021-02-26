import pycurl
# cmd = pycurl.Curl()
# cmd.setopt(pycurl.URL, "https://www.sina.com.cn/")
# data = cmd.perform()
# print(data)


def header_function(info):
    print(info)


def get_pycurl(url):
    # 创建一个buffer,要使用BytesIO
    buffer = io.BytesIO()
    # 创建实例
    c = pycurl.Curl()
    c.setopt(pycurl.URL, url)
    c.setopt(pycurl.WRITEFUNCTION, buffer.write)
    c.setopt(pycurl.HEADERFUNCTION, header_function)
    c.perform()
    c.close()

    body = buffer.getvalue().decode('utf-8')
#    print (body)


def write_file(path, url):
    with open(path, 'wb') as f:
        c = pycurl.Curl()
        c.setopt(pycurl.URL, url)
        c.setopt(pycurl.WRITEDATA, f)
        c.perform()
        c.close()
    print('写入成功')


def get_content(url):
    res = urllib.request.urlopen(url)
    content = res.read().decode('utf-8')
    print(content)


def main():
    #    root = Tk()
    #    button_my = my_button(root, 'a', 'b', action)
    #    root.mainloop()
    #    c1 = myClass()
    #    c1.get_name()
    #    c1.get_file('deng.txt')
    #    print ()
    #    get_file('deng.txt')
    #    get_pycurl('http://www.baidu.com')
    url = 'http://www.lgo100.com/d/file/p/20180428/smalla7a45e09afc5f2fbd25b061ab1464c731524883416.jpg'
    filename = url[url.rfind('/') + 1:]
#    get_content(url)
#    get_pycurl(url)
    write_file(filename, url)


if __name__ == '__main__':
    import time
    time_start = time.time()
    main()
    for i in range(1000000):
        i += 1
    time_end = time.time()
    print('time cost:', time_end - time_start, 's')
