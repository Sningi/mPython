import sys
import time
from PyQt5.QtCore import *
from PyQt5.QtGui import*
from PyQt5.QtWidgets import QApplication, QWidget
app = QApplication(sys.argv)
while(1):
    try:
        due = QTime.currentTime()
        msg = 'alert'
        if len(sys.argv) < 2:
            raise ValueError
        hours, mins = sys.argv[1].split(":")
        dues = QTime(int(hours), int(mins), 0, 0)
        # print(due)
        # print(dues)
        if not due.isValid():
            raise ValueError
        if len(sys.argv) > 2:
            msg = " ".join(sys.argv[1:])
        if due == dues:
            w = QWidget()
            # resize()方法调整窗口的大小。这离是250px宽150px高
            w.resize(500, 600)
            # move()方法移动窗口在屏幕上的位置到x = 300，y = 300坐标。
            w.move(500, 300)
            # 设置窗口的标题
            w.setWindowTitle(sys.argv[1])
            # 显示在屏幕上
            w.show()
    except ValueError:
        msg = "Usage :HH:MM"
