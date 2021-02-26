#!/usr/bin/env python
# -*- coding:utf-8 -*-
import socket
import threading
import json
import pymysql as Mysql
import random
import queue
from datetime import datetime
import time
# 连接数据库
db_conn = Mysql.connect(host='127.0.0.1', user='sning',
                        passwd='197010', db='monitor')

# 通讯格式  0:退出    1:请求数据  2:历史记录 3:控制灯的亮度 9:Java终端     8:数据采集

Ctrlqueue = queue.Queue()
# 灯光 1 开  2 关
status = [{'status': '000', 'type': 30}]


class JProcess(threading.Thread):
    """Java"""

    def __init__(self, conn, count):
        super(JProcess, self).__init__()
        self.conn = conn
        self.num = count

    def run(self):
        Flag = True
        while Flag:
            global status
            jdata = self.conn.recv(1024).decode('utf-8')
            #print(self.num, 'java', jdata)
            if not jdata:
                print(self.num, 'java socket 断开 ')
                break
            if jdata == '0':
                Flag = False
                print(self.num, 'Java 端退出')
            elif jdata == '1':
                self.sendinfo()
                print('请求刷新成功')
            elif jdata[0] == '2':
                self.historyinfo(int(jdata[1:]))
                print('请求历史数据')
            elif jdata == '4':
                #print('查询状态')
                self.conn.sendall(json.dumps(status).encode("utf-8"))
            elif jdata[0] == '3':
                print('灯光控制(亮度):', jdata[1:])
                status = [{'status': jdata[1:], 'type': 30}]
                Ctrlqueue.put(jdata)
            else:
                self.conn.sendall(json.dumps(status).encode("utf-8"))
        self.conn.close()

    def sendinfo(self):
        # 获取数据库的信息
        cur = db_conn.cursor()
        cmd = 'select time,speed,direction from windinfo where id =(select max(id) from windinfo)'
        cur.execute(cmd)
        data = cur.fetchall()
        json_data = []
        if data:
            direction = data[0][2]
            speed = data[0][1]
            dtime = str(data[0][0])
            # print(dtime)
            json_data = [{
                "type": 1,
                "direction": direction,
                "speed": speed,
                "time": dtime}]

        self.conn.sendall(json.dumps(json_data).encode("utf-8"))

    def historyinfo(self, page):
        cur = db_conn.cursor()
        cmd = 'select time,speed,direction from windinfo order by id desc limit ' + \
            str(page * 5) + ',5;'
        cur.execute(cmd)
        data = cur.fetchall()
        json_data = []
        for i in data:
            temp = {
                "type": 2,
                "direction": i[2],
                "speed": i[1],
                "time": str(i[0])}
            json_data.append(temp)
        self.conn.sendall(json.dumps(json_data).encode("utf-8"))


class WProcess(threading.Thread):
    """win"""

    def __init__(self, conn, count):
        super(WProcess, self).__init__()
        self.conn = conn
        self.num = count

    def run(self):
        # 通讯格式 0:退出 1:请求数据 2:
        Flag = True
        cprocess = CProcess(self.conn, Ctrlqueue)
        # 设置守护进程 随着连接关闭退出子进程
        cprocess.setDaemon(True)
        cprocess.start()

        while Flag:
            wdata = self.conn.recv(1024).decode('utf-8')

            # 模拟控制任务
            # moni = 3000
            # s = random.randint(10, 99)
            # moni = moni + s
            # Ctrlqueue.put(str(moni))
            #
            if not wdata:
                print(self.num, 'win socket 断开 ')
                break
            # 把数据插入数据库
            speed = str(wdata)
            print('风速:', speed)
            direction = str(random.randint(0, 360))
            cur = db_conn.cursor()
            cmd = "insert into windinfo values(0,'%s','%s','%s');" % (
                datetime.now(), speed, direction)
            try:
                cur.execute(cmd)
                # 提交
                db_conn.commit()
                print('插入风速数据成功')
            except Exception as e:
                # 错误回滚
                print(e)
                db_conn.rollback()
        self.conn.close()


class CProcess(threading.Thread):
    """docstring for CProcess"""

    def __init__(self, connect, ctrlqueue):
        super(CProcess, self).__init__()
        self.ctrlqueue = ctrlqueue
        self.connect = connect

    def run(self):
        while True:
            if(self.ctrlqueue.empty()):
                time.sleep(0.2)
            else:
                cmd = self.ctrlqueue.get()
                print('下发控制任务(亮度):', cmd[1:])
                self.connect.sendall(cmd.encode('utf-8'))


if __name__ == '__main__':
    ip_port = ('0.0.0.0', 8888)
    # 默认ipv4,tcp
    sk = socket.socket()
    sk.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sk.bind(ip_port)
    sk.listen(5)
    count = 0
    print('server is listening...')
    while True:
        conn, address = sk.accept()
        count += 1
        addr = str(address)
        num = conn.recv(1024).decode('utf-8')
        if num == '9':
            # Java客户端服务线程
            print(count, addr, 'Java 端连接成功')
            jprocess = JProcess(conn, count)
            jprocess.start()
        elif num[0] == '8':
            # 数据采集服务线程
            print(count, addr, 'Win C 端连接成功')
            Wprocess = WProcess(conn, count)
            Wprocess.start()

    db_conn.close()
