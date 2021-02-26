import sys

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QLCDNumber, QSlider, 
    QHBoxLayout, QApplication)
from PyQt5.QtCore import QDate, QTime, QDateTime 
 
class Example(QWidget):
    
    def __init__(self):
        super().__init__()
        
        self.initUI()
        
        
    def initUI(self):
        time = QTime.currentTime()
        lcd = QLCDNumber(self)
        lcd.setDigitCount(10)
        print(time.toString(Qt.DefaultLocaleLongDate))
        lcd.display(time.toString(Qt.DefaultLocaleLongDate)[-10:])
        sld = QSlider(Qt.Vertical, self)
 
        vbox = QHBoxLayout()
        vbox.addWidget(lcd)
        vbox.addWidget(sld)
 
        self.setLayout(vbox)
        sld.valueChanged.connect(lcd.display)
        
        self.setGeometry(300, 300, 800, 150)
        self.setWindowTitle('Signal & slot')
        self.show()
        
 
if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())