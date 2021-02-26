#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket
socket.setdefaulttimeout(5)

ip_port = ('39.108.188.187', 8888)
sk = socket.socket()
sk.connect(ip_port)
sk.settimeout(5)
sk.sendall('8'.encode('utf-8'))
while True:
    inp = input('please input:(0 exit,1 get info) ')
    if inp == '1':
        print('try required info')
        sk.sendall(inp.encode('utf-8'))
        data = sk.recv(1024)
        print('receive:', data.decode('utf-8'))
    elif inp[0] == '2':
        sk.sendall(inp.encode('utf-8'))
        #data = sk.recv(1024)
        #print('receive:', data.decode('utf-8'))
        # break
sk.close()
