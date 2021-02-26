import sys
from PyQt5.QtWidgets import QWidget, QMessageBox, QApplication, QDesktopWidget
 
 
class Example(QWidget):
    
    def __init__(self):
        super().__init__()
        
        self.initUI()
        
        
    def initUI(self):               
        
        self.resize(400, 250)        
        self.setWindowTitle('Message box')    
        self.center()
        self.show()
        
    def center(self):
        
        #获得窗口
        qr = self.frameGeometry()
        #获得屏幕中心点
        cp = QDesktopWidget().availableGeometry().center()
        #显示到屏幕中心
        qr.moveCenter(cp)
        print(qr.topLeft())
        self.move(qr.topRight())
        
    def closeEvent(self, event):
        
        reply = QMessageBox.question(self, '请确认',
            "退出?", QMessageBox.Ok| 
            QMessageBox.Cancel, QMessageBox.Cancel)
        
        if reply == QMessageBox.Ok:
            event.accept()
        else:
            event.ignore()        
        
        
if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
