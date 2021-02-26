#!_*_coding:utf-8_*_
# Author: hkey
import threading
import time


def run_thread():
    n = 0
    while n <= 100000000:
        n += 1
        if n % 10000000 == 0:
            # print(n)
            pass


def single_run():
    start_time = time.time()
    for i in range(4):
        t = threading.Thread(target=run_thread,)
        t.start()
        t.join()    # 四个线程串行执行
    print('single thread times:', time.time() - start_time)


def multi_run():
    thread_list = []
    start_time = time.time()
    for i in range(4):
        t = threading.Thread(target=run_thread,)
        t.start()
        thread_list.append(t)
    for t in thread_list:
        t.join()    # 四个线程并行执行
    print('multi threads times:', time.time() - start_time)


if __name__ == '__main__':
    single_run()
    multi_run()
# 线程的串行和并行是通过join()方法来确定的，join方法是阻塞当前线程并等待正在执行的子线程执行完毕。
