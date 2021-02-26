#!/usr/bin/python
# coding=utf-8

import time
import random
from multiprocessing import Process


def run_thread():
    n = 0
    while n <= 100000000:
        n += 1
        if n % 10000000 == 0:
            # print(n)
            pass


# def foo(i):
#     print time.ctime(), "process the %d begin ......" % i
#     time.sleep(random.uniform(1, 3))
#     print time.ctime(), "process the %d end !!!!!!" % i


if __name__ == "__main__":
    # print time.ctime(), "process begin......"
    start_time = time.time()
    p_lst = list()
    for i in range(4):
        p_lst.append(Process(target=run_thread,))  # 创建4个子进程
    # 启动子进程
    for p in p_lst:
        p.start()
    # 等待子进程全部结束
    for p in p_lst:
        p.join()
    print('multi threads times:', time.time() - start_time)
