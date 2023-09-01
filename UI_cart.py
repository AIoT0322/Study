# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'cart.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_cart(object):
    def setupUi(self, cart):
        cart.setObjectName("cart")
        cart.resize(300, 506)
        cart.setMinimumSize(QtCore.QSize(300, 0))
        cart.setMaximumSize(QtCore.QSize(300, 16777215))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        cart.setFont(font)
        cart.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.back_btn = QtWidgets.QPushButton(cart)
        self.back_btn.setGeometry(QtCore.QRect(0, 0, 21, 21))
        self.back_btn.setText("")
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("뒤로가기.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.back_btn.setIcon(icon)
        self.back_btn.setIconSize(QtCore.QSize(20, 20))
        self.back_btn.setFlat(True)
        self.back_btn.setObjectName("back_btn")
        self.label = QtWidgets.QLabel(cart)
        self.label.setGeometry(QtCore.QRect(120, 10, 81, 16))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.scrollArea = QtWidgets.QScrollArea(cart)
        self.scrollArea.setGeometry(QtCore.QRect(-10, 30, 305, 411))
        self.scrollArea.setMinimumSize(QtCore.QSize(305, 0))
        self.scrollArea.setMaximumSize(QtCore.QSize(305, 16777215))
        self.scrollArea.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.scrollArea.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 318, 411))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout.setObjectName("verticalLayout")
        self.widget = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.widget.setMinimumSize(QtCore.QSize(300, 80))
        self.widget.setMaximumSize(QtCore.QSize(300, 80))
        self.widget.setObjectName("widget")
        self.label_4 = QtWidgets.QLabel(self.widget)
        self.label_4.setGeometry(QtCore.QRect(0, 0, 151, 51))
        self.label_4.setText("")
        self.label_4.setPixmap(QtGui.QPixmap("배달.jpg"))
        self.label_4.setObjectName("label_4")
        self.label_2 = QtWidgets.QLabel(self.widget)
        self.label_2.setGeometry(QtCore.QRect(10, 60, 131, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.widget)
        self.label_3.setGeometry(QtCore.QRect(170, 60, 111, 31))
        self.label_3.setText("")
        self.label_3.setPixmap(QtGui.QPixmap("시간.jpg"))
        self.label_3.setObjectName("label_3")
        self.verticalLayout.addWidget(self.widget)
        self.addWidget = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.addWidget.setMinimumSize(QtCore.QSize(300, 0))
        self.addWidget.setMaximumSize(QtCore.QSize(300, 16777215))
        self.addWidget.setObjectName("addWidget")
        self.verticalLayout.addWidget(self.addWidget)
        self.widget_2 = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.widget_2.setMinimumSize(QtCore.QSize(300, 90))
        self.widget_2.setMaximumSize(QtCore.QSize(300, 90))
        self.widget_2.setObjectName("widget_2")
        self.label_6 = QtWidgets.QLabel(self.widget_2)
        self.label_6.setGeometry(QtCore.QRect(10, 10, 71, 16))
        self.label_6.setObjectName("label_6")
        self.line = QtWidgets.QFrame(self.widget_2)
        self.line.setGeometry(QtCore.QRect(-10, 50, 311, 16))
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.label_10 = QtWidgets.QLabel(self.widget_2)
        self.label_10.setGeometry(QtCore.QRect(220, 10, 56, 16))
        self.label_10.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_10.setObjectName("label_10")
        self.label_8 = QtWidgets.QLabel(self.widget_2)
        self.label_8.setGeometry(QtCore.QRect(10, 70, 81, 16))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.label_8.setFont(font)
        self.label_8.setObjectName("label_8")
        self.label_11 = QtWidgets.QLabel(self.widget_2)
        self.label_11.setGeometry(QtCore.QRect(220, 70, 56, 16))
        self.label_11.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_11.setObjectName("label_11")
        self.label_12 = QtWidgets.QLabel(self.widget_2)
        self.label_12.setGeometry(QtCore.QRect(220, 30, 56, 16))
        self.label_12.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_12.setObjectName("label_12")
        self.label_7 = QtWidgets.QLabel(self.widget_2)
        self.label_7.setGeometry(QtCore.QRect(10, 30, 71, 16))
        self.label_7.setObjectName("label_7")
        self.verticalLayout.addWidget(self.widget_2)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.btn_order = QtWidgets.QPushButton(cart)
        self.btn_order.setGeometry(QtCore.QRect(10, 450, 281, 51))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.btn_order.setFont(font)
        self.btn_order.setStyleSheet("background-color: rgb(43, 194, 189);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;")
        self.btn_order.setObjectName("btn_order")
        self.total = QtWidgets.QLabel(cart)
        self.total.setGeometry(QtCore.QRect(220, 470, 56, 12))
        font = QtGui.QFont()
        font.setPointSize(8)
        font.setBold(True)
        font.setWeight(75)
        self.total.setFont(font)
        self.total.setStyleSheet("background-color: rgb(43, 194, 189);\n"
"color: rgb(255, 255, 255);\n"
"")
        self.total.setAlignment(QtCore.Qt.AlignCenter)
        self.total.setObjectName("total")
        self.btn_order.raise_()
        self.back_btn.raise_()
        self.label.raise_()
        self.scrollArea.raise_()
        self.total.raise_()

        self.retranslateUi(cart)
        QtCore.QMetaObject.connectSlotsByName(cart)

    def retranslateUi(self, cart):
        _translate = QtCore.QCoreApplication.translate
        cart.setWindowTitle(_translate("cart", "배달의민족"))
        self.label.setText(_translate("cart", "장바구니"))
        self.label_2.setText(_translate("cart", "김밥나라 시영점"))
        self.label_6.setText(_translate("cart", "총 주문금액"))
        self.label_10.setText(_translate("cart", "원"))
        self.label_8.setText(_translate("cart", "결제예정금액"))
        self.label_11.setText(_translate("cart", "원"))
        self.label_12.setText(_translate("cart", "3500원"))
        self.label_7.setText(_translate("cart", "배달팁"))
        self.btn_order.setText(_translate("cart", "배달 주문하기"))
        self.total.setText(_translate("cart", "총 금액"))
