import threading
class A(threading.Thread):
    """docstring for A"""
    def __init__(self,):
        threading.Thread.__init__(self)
    def run(self):
        for i in range(10):
            print("I am A")
class B(threading.Thread):
    """docstring for B"""
    def __init__(self):
        threading.Thread.__init__(self)
    def run(self):
        for i in range(10):
            print("I am B") 
t1=A()
t1.start()
t2=B()
t2.start()