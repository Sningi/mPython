import sys
from PyQt5.QtWidgets import (
    QWidget, QToolTip, QPushButton, QApplication, QMessageBox)
from PyQt5.QtGui import QFont, QIcon,QCloseEvent
from PyQt5.QtCore import QCoreApplication


class Example(QWidget):

    def __init__(self):
        super().__init__()

        self.initUI()

    def closeEvent(self, event):
        reply = QMessageBox.question(self,
                                     'Message',
                                     "Are you sure to quit?",
                                     QMessageBox.Yes | QMessageBox.No,
                                     QMessageBox.No)

        if reply == QMessageBox.Yes:
            #event.accept()
            QCoreApplication.quit()
        elif type(event)==QCloseEvent:
            event.ignore()

    def initUI(self):
        # 这种静态的方法设置一个用于显示工具提示的字体。我们使用10px滑体字体。
        QToolTip.setFont(QFont('SansSerif', 10))

        # 创建一个提示，我们称之为settooltip()方法。我们可以使用丰富的文本格式
        self.setToolTip('This is a <b>QWidget</b> widget')
        self.setWindowIcon(QIcon('s1.ico'))
        # 创建一个PushButton并为他设置一个tooltip
        btn = QPushButton('Button', self)
        btn.setToolTip('This is a <b>QPushButton</b> widget')
        # btn.sizeHint()显示默认尺寸
        btn.resize(btn.sizeHint())
        # 移动窗口的位置
        btn.move(200, 200)

        btnq = QPushButton('quit', self)
        btnq.setToolTip('This is a <b>QPushButton</b> widget')
        # btn.sizeHint()显示默认尺寸
        btnq.resize(btn.sizeHint())
        # 移动窗口的位置
        btnq.move(300, 300)
        # btnq.clicked.connect(QCoreApplication.quit)
        # btnq.clicked.connect(QCoreApplication.instance().quit)
        btnq.clicked.connect(self.closeEvent)
        self.setGeometry(300, 300, 500, 500)
        self.setWindowTitle('error')
        self.show()


if __name__ == '__main__':

    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
