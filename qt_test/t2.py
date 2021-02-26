# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 't2.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!
import sys
from PyQt5 import QtCore, QtWidgets


class Mywindows(QtWidgets.QMainWindow):

    def __init__(self):
        super(Mywindows, self).__init__()
        self.setupUi(self)
        self.retranslateui(self)

    def setupUi(self, mainwindows):

        mainwindows.setObjectName("MainWindow")
        mainwindows.resize(480, 608)
        self.centralwidget = QtWidgets.QWidget(mainwindows)
        self.centralwidget.setObjectName("centralwidget")
        self.formLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.formLayoutWidget.setGeometry(QtCore.QRect(-1, 30, 411, 431))
        self.formLayoutWidget.setObjectName("formLayoutWidget")
        self.formLayout = QtWidgets.QFormLayout(self.formLayoutWidget)
        self.formLayout.setContentsMargins(0, 0, 0, 0)
        self.formLayout.setObjectName("formLayout")
        self.calendarWidget = QtWidgets.QCalendarWidget(self.formLayoutWidget)
        self.calendarWidget.setObjectName("calendarWidget")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.calendarWidget)
        self.lcdNumber = QtWidgets.QLCDNumber(self.formLayoutWidget)
        self.lcdNumber.setObjectName("lcdNumber")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.lcdNumber)
        mainwindows.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(mainwindows)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 480, 32))
        self.menubar.setObjectName("menubar")
        mainwindows.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(mainwindows)
        self.statusbar.setObjectName("statusbar")
        mainwindows.setStatusBar(self.statusbar)

        self.retranslateui(mainwindows)
        QtCore.QMetaObject.connectSlotsByName(mainwindows)

    def retranslateui(self, mainwindows):
        _translate = QtCore.QCoreApplication.translate
        mainwindows.setWindowTitle(_translate("MainWindow", "MainWindow"))


app = QtWidgets.QApplication(sys.argv)

win = Mywindows()

win.show()

app.exec_()
