# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ginbabmenu.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_menu(object):
    def setupUi(self, menu):
        menu.setObjectName("menu")
        menu.resize(299, 511)
        self.photo1 = QtWidgets.QLabel(menu)
        self.photo1.setGeometry(QtCore.QRect(0, 0, 301, 361))
        self.photo1.setText("")
        self.photo1.setPixmap(QtGui.QPixmap("김밥메뉴.jpg"))
        self.photo1.setObjectName("photo1")
        self.widget = QtWidgets.QWidget(menu)
        self.widget.setGeometry(QtCore.QRect(0, 360, 301, 151))
        self.widget.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.widget.setObjectName("widget")
        self.label_2 = QtWidgets.QLabel(self.widget)
        self.label_2.setGeometry(QtCore.QRect(10, 10, 41, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.label_2.setFont(font)
        self.label_2.setText("")
        self.label_2.setPixmap(QtGui.QPixmap("수량.jpg"))
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.widget)
        self.label_3.setGeometry(QtCore.QRect(170, 10, 121, 41))
        self.label_3.setText("")
        self.label_3.setPixmap(QtGui.QPixmap("수량btn1.jpg"))
        self.label_3.setObjectName("label_3")
        self.btn_minus = QtWidgets.QPushButton(self.widget)
        self.btn_minus.setGeometry(QtCore.QRect(190, 20, 21, 21))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.btn_minus.setFont(font)
        self.btn_minus.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_minus.setText("")
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("캡처.PNG"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.btn_minus.setIcon(icon)
        self.btn_minus.setIconSize(QtCore.QSize(17, 17))
        self.btn_minus.setCheckable(False)
        self.btn_minus.setFlat(True)
        self.btn_minus.setObjectName("btn_minus")
        self.btn_plus = QtWidgets.QPushButton(self.widget)
        self.btn_plus.setGeometry(QtCore.QRect(260, 20, 21, 21))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.btn_plus.setFont(font)
        self.btn_plus.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.btn_plus.setText("")
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap("plussign_83738.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.btn_plus.setIcon(icon1)
        self.btn_plus.setIconSize(QtCore.QSize(10, 10))
        self.btn_plus.setCheckable(False)
        self.btn_plus.setFlat(True)
        self.btn_plus.setObjectName("btn_plus")
        self.label_number = QtWidgets.QLabel(self.widget)
        self.label_number.setGeometry(QtCore.QRect(220, 20, 31, 16))
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.label_number.setFont(font)
        self.label_number.setObjectName("label_number")
        self.btn_pluscart = QtWidgets.QPushButton(self.widget)
        self.btn_pluscart.setGeometry(QtCore.QRect(120, 100, 171, 41))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.btn_pluscart.setFont(font)
        self.btn_pluscart.setAutoFillBackground(False)
        self.btn_pluscart.setStyleSheet("background-color: rgb(43, 194, 189);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"")
        self.btn_pluscart.setInputMethodHints(QtCore.Qt.ImhNone)
        self.btn_pluscart.setAutoExclusive(False)
        self.btn_pluscart.setAutoDefault(False)
        self.btn_pluscart.setDefault(False)
        self.btn_pluscart.setFlat(False)
        self.btn_pluscart.setObjectName("btn_pluscart")
        self.label = QtWidgets.QLabel(self.widget)
        self.label.setGeometry(QtCore.QRect(10, 90, 101, 51))
        self.label.setText("")
        self.label.setPixmap(QtGui.QPixmap("최소금액.jpg"))
        self.label.setObjectName("label")
        self.label_4 = QtWidgets.QLabel(self.widget)
        self.label_4.setGeometry(QtCore.QRect(240, 20, 21, 16))
        self.label_4.setObjectName("label_4")
        self.back_btn = QtWidgets.QPushButton(menu)
        self.back_btn.setGeometry(QtCore.QRect(0, 0, 21, 21))
        self.back_btn.setText("")
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap("뒤로가기.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.back_btn.setIcon(icon2)
        self.back_btn.setIconSize(QtCore.QSize(20, 20))
        self.back_btn.setFlat(True)
        self.back_btn.setObjectName("back_btn")
        self.scrollArea_2 = QtWidgets.QScrollArea(menu)
        self.scrollArea_2.setGeometry(QtCore.QRect(560, 60, 310, 331))
        self.scrollArea_2.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.scrollArea_2.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.scrollArea_2.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.scrollArea_2.setWidgetResizable(True)
        self.scrollArea_2.setAlignment(QtCore.Qt.AlignCenter)
        self.scrollArea_2.setObjectName("scrollArea_2")
        self.scrollAreaWidgetContents_3 = QtWidgets.QWidget()
        self.scrollAreaWidgetContents_3.setGeometry(QtCore.QRect(0, 0, 310, 414))
        self.scrollAreaWidgetContents_3.setObjectName("scrollAreaWidgetContents_3")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.scrollAreaWidgetContents_3)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.kimzzi_btn = QtWidgets.QPushButton(self.scrollAreaWidgetContents_3)
        self.kimzzi_btn.setText("")
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap("SmartSelect_20230731_215211.jpg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.kimzzi_btn.setIcon(icon3)
        self.kimzzi_btn.setIconSize(QtCore.QSize(280, 120))
        self.kimzzi_btn.setFlat(True)
        self.kimzzi_btn.setObjectName("kimzzi_btn")
        self.verticalLayout_2.addWidget(self.kimzzi_btn)
        self.om_btn = QtWidgets.QPushButton(self.scrollAreaWidgetContents_3)
        self.om_btn.setText("")
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap("SmartSelect_20230731_215159.jpg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.om_btn.setIcon(icon4)
        self.om_btn.setIconSize(QtCore.QSize(280, 120))
        self.om_btn.setFlat(True)
        self.om_btn.setObjectName("om_btn")
        self.verticalLayout_2.addWidget(self.om_btn)
        self.dzzi_btn = QtWidgets.QPushButton(self.scrollAreaWidgetContents_3)
        self.dzzi_btn.setText("")
        icon5 = QtGui.QIcon()
        icon5.addPixmap(QtGui.QPixmap("SmartSelect_20230731_215221.jpg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.dzzi_btn.setIcon(icon5)
        self.dzzi_btn.setIconSize(QtCore.QSize(280, 120))
        self.dzzi_btn.setFlat(True)
        self.dzzi_btn.setObjectName("dzzi_btn")
        self.verticalLayout_2.addWidget(self.dzzi_btn)
        self.scrollArea_2.setWidget(self.scrollAreaWidgetContents_3)

        self.retranslateUi(menu)
        QtCore.QMetaObject.connectSlotsByName(menu)

    def retranslateUi(self, menu):
        _translate = QtCore.QCoreApplication.translate
        menu.setWindowTitle(_translate("menu", "배달의민족"))
        self.label_number.setText(_translate("menu", "1"))
        self.btn_pluscart.setText(_translate("menu", "          담기"))
        self.label_4.setText(_translate("menu", "개"))
