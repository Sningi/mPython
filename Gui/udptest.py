from socket import *
from time import ctime
import threading


class EcommUdpServer(threading.Thread):
    """docstring for EcommUdpServer"""
    def __init__(self, host, port):
        threading.Thread.__init__(self)
        self.listening = True
        self.host = host
        self.port = port
        self.UdpServer = socket(AF_INET, SOCK_DGRAM)
        self.UdpServer.bind((self.host,self.port))  # 开始监听
        
        print(self.get_ip())

    def run(self):
        while (self.listening):
            print(self.port,"is listening")
            data, addr = self.UdpServer.recvfrom(1024)
            if data[:5] == b'sucet':
                print("confirm")
            else:
                self.process(data, addr)
                self.sendmsg('chattpythonhello')
        print("外部命令停止接收")
        self.UdpServer.close()

    def process(self, data, addr):
        print("recevied:", data.decode(encoding="utf-8"))
        self.UdpServer.sendto('sucet'.encode(), addr)
    def sendmsg(self,msg):
        self.UdpServer.sendto(msg.encode(),('192.168.1.106',10000))

    def get_ip(self):
        self.UdpServer.connect(('114.114.114.114', 80))
        ip = self.UdpServer.getsockname()[0]
        return ip 
if __name__ == '__main__':
    s1=EcommUdpServer('192.168.1.106',8000)
    s1.start()
    while(True):
        send=input("input msg:")
        s1.sendmsg('chatt'+send)