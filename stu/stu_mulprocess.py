from multiprocessing import Pool
import gevent
from gevent import monkey
# monkey.patch_all()


def test1():
    print(12)
    gevent.sleep(1)
    print(34)


def test2():
    print(56)
    gevent.sleep(1)
    print(78)


def coroutine():
    gevent.joinall([
        gevent.spawn(test1),
        gevent.spawn(test2)
    ])


if __name__ == "__main__":
    p = Pool()
    for i in range(3):
        p.apply_async(coroutine, args=())
    p.close()
    p.join()
