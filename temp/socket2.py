import socket
import numpy as np
import cv2
import struct
import time

obj = socket.socket()
obj.connect(("127.0.0.1",8080))  # 用于双python
#obj.connect(("192.168.7.4",6666))
obj.sendall(bytes('hello Apple Cai!', encoding="utf-8"))

while(True):
    buf_size, a2 = struct.unpack("ii", obj.recv(8))
    temp_buf = b''
    time.sleep(0.001) #不加延时就不行，不知道为什么。
    while(buf_size):
        temp_buf = obj.recv(buf_size)
        buf_size-= len(temp_buf)
        str_encode = temp_buf
        nparr = np.fromstring(str_encode, np.uint8)
        #解压jpg格式数据
        img_decode = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
        #显示为图片
        cv2.imshow("img_decode", img_decode)
    if(cv2.waitKey(10)==27):        #每10ms刷新一次图片
        print('go here')
        obj.close()
        cv2.destroyAllWindows()