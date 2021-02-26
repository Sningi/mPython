import time
from collections import deque as dq
from random import Random
import threading


# 重写用于事件队列的deque，使得对deque的变动会触发信号量
class deque(dq):
    # 存储信号的集合
    sign = set()

    # 重写append、appendleft、extend、extendleft方法
    def append(self, *args, **kwargs):
        dq.append(self, *args, **kwargs)
        self.sign_set()

    def appendleft(self, *args, **kwargs):
        dq.appendleft(self, *args, **kwargs)
        self.sign_set()

    def extend(self, *args, **kwargs):
        dq.extend(self, *args, **kwargs)

    def extendleft(self, *args, **kwargs):
        dq.extendleft(self, *args, **kwargs)

    # 触发信号
    def sign_set(self):
        for s in self.sign:
            s.set()

    # 添加一个信号
    def add_sign(self, s):
        self.sign.add(s)


class Example():

    def __init__(self):
        self.r = Random(time.time())

    # 添加一个信号量绑定给deque，当发现deque中没有值之后等待信号传入
    def worker_run(self, name, q):
        sign = threading.Event()
        q.add_sign(sign)
        while True:
            if q:
                print("%s pop number: %s, %s numbers left" % (name, q.pop(), len(q)))
            else:
                sign.wait()
                sign.clear()

    def manager_run(self, worker_num):
        queue_list = [deque() for i in range(worker_num)]

        worker_list = [threading.Thread(target=self.worker_run,
                                        args=["Thread-%s" % i, queue_list[i]])
                       for i in range(worker_num)]
        for worker in worker_list:
            worker.start()
        while True:
            i = 0
            while i < self.r.randint(0, 20):
                queue_list[self.r.randint(0, worker_num - 1)].appendleft(
                    self.r.randint(1, 100)
                )
                i += 1
            time.sleep(self.r.random())


if __name__ == '__main__':
    Example().manager_run(3)
