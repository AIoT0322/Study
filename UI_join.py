# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'join.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_join(object):
    def setupUi(self, join):
        join.setObjectName("join")
        join.resize(300, 500)
        join.setMinimumSize(QtCore.QSize(300, 500))
        join.setMaximumSize(QtCore.QSize(300, 500))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("톡이미지1.jpg"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        join.setWindowIcon(icon)
        self.stackedWidget = QtWidgets.QStackedWidget(join)
        self.stackedWidget.setGeometry(QtCore.QRect(0, 0, 300, 500))
        self.stackedWidget.setMinimumSize(QtCore.QSize(300, 500))
        self.stackedWidget.setMaximumSize(QtCore.QSize(300, 500))
        self.stackedWidget.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.stackedWidget.setObjectName("stackedWidget")
        self.login_page = QtWidgets.QWidget()
        self.login_page.setObjectName("login_page")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.login_page)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_5 = QtWidgets.QLabel(self.login_page)
        self.label_5.setText("")
        self.label_5.setPixmap(QtGui.QPixmap("톡이미지1.jpg"))
        self.label_5.setObjectName("label_5")
        self.verticalLayout_2.addWidget(self.label_5, 0, QtCore.Qt.AlignHCenter)
        self.widget = QtWidgets.QWidget(self.login_page)
        self.widget.setObjectName("widget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.widget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.widget_7 = QtWidgets.QWidget(self.widget)
        self.widget_7.setObjectName("widget_7")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout(self.widget_7)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.widget_8 = QtWidgets.QWidget(self.widget_7)
        self.widget_8.setObjectName("widget_8")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.widget_8)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.label_3 = QtWidgets.QLabel(self.widget_8)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_4.addWidget(self.label_3)
        self.label_4 = QtWidgets.QLabel(self.widget_8)
        self.label_4.setObjectName("label_4")
        self.verticalLayout_4.addWidget(self.label_4)
        self.horizontalLayout_4.addWidget(self.widget_8)
        self.widget_9 = QtWidgets.QWidget(self.widget_7)
        self.widget_9.setMinimumSize(QtCore.QSize(150, 0))
        self.widget_9.setMaximumSize(QtCore.QSize(150, 16777215))
        self.widget_9.setObjectName("widget_9")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.widget_9)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.widget_9)
        self.lineEdit_3.setMinimumSize(QtCore.QSize(0, 25))
        self.lineEdit_3.setMaximumSize(QtCore.QSize(16777215, 25))
        self.lineEdit_3.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.verticalLayout_5.addWidget(self.lineEdit_3)
        self.lineEdit_4 = QtWidgets.QLineEdit(self.widget_9)
        self.lineEdit_4.setMinimumSize(QtCore.QSize(0, 25))
        self.lineEdit_4.setMaximumSize(QtCore.QSize(16777215, 25))
        self.lineEdit_4.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.lineEdit_4.setEchoMode(QtWidgets.QLineEdit.Password)
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.verticalLayout_5.addWidget(self.lineEdit_4)
        self.horizontalLayout_4.addWidget(self.widget_9)
        self.verticalLayout.addWidget(self.widget_7)
        self.widget_2 = QtWidgets.QWidget(self.widget)
        self.widget_2.setObjectName("widget_2")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.widget_2)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.widget_10 = QtWidgets.QWidget(self.widget_2)
        self.widget_10.setObjectName("widget_10")
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout(self.widget_10)
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.btn_2 = QtWidgets.QPushButton(self.widget_10)
        self.btn_2.setMinimumSize(QtCore.QSize(0, 30))
        self.btn_2.setMaximumSize(QtCore.QSize(16777215, 30))
        self.btn_2.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;\n"
"background-color: rgba(249, 224, 0, 117);\n"
"")
        self.btn_2.setFlat(True)
        self.btn_2.setObjectName("btn_2")
        self.horizontalLayout_5.addWidget(self.btn_2)
        self.horizontalLayout_2.addWidget(self.widget_10)
        self.widget_6 = QtWidgets.QWidget(self.widget_2)
        self.widget_6.setObjectName("widget_6")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.widget_6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.btn_1 = QtWidgets.QPushButton(self.widget_6)
        self.btn_1.setMinimumSize(QtCore.QSize(100, 30))
        self.btn_1.setMaximumSize(QtCore.QSize(100, 16777215))
        self.btn_1.setSizeIncrement(QtCore.QSize(0, 30))
        self.btn_1.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.btn_1.setFlat(True)
        self.btn_1.setObjectName("btn_1")
        self.horizontalLayout.addWidget(self.btn_1)
        self.horizontalLayout_2.addWidget(self.widget_6)
        self.verticalLayout.addWidget(self.widget_2)
        self.verticalLayout_2.addWidget(self.widget)
        self.stackedWidget.addWidget(self.login_page)
        self.signup_page = QtWidgets.QWidget()
        self.signup_page.setObjectName("signup_page")
        self.widget_3 = QtWidgets.QWidget(self.signup_page)
        self.widget_3.setGeometry(QtCore.QRect(-10, 220, 318, 291))
        self.widget_3.setObjectName("widget_3")
        self.verticalLayout_9 = QtWidgets.QVBoxLayout(self.widget_3)
        self.verticalLayout_9.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_9.setObjectName("verticalLayout_9")
        self.widget_4 = QtWidgets.QWidget(self.widget_3)
        self.widget_4.setMinimumSize(QtCore.QSize(300, 0))
        self.widget_4.setMaximumSize(QtCore.QSize(300, 16777215))
        self.widget_4.setObjectName("widget_4")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.widget_4)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.widget_5 = QtWidgets.QWidget(self.widget_4)
        self.widget_5.setMinimumSize(QtCore.QSize(300, 0))
        self.widget_5.setSizeIncrement(QtCore.QSize(300, 0))
        self.widget_5.setObjectName("widget_5")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.widget_5)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.widget_11 = QtWidgets.QWidget(self.widget_5)
        self.widget_11.setObjectName("widget_11")
        self.verticalLayout_6 = QtWidgets.QVBoxLayout(self.widget_11)
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.label_7 = QtWidgets.QLabel(self.widget_11)
        self.label_7.setObjectName("label_7")
        self.verticalLayout_6.addWidget(self.label_7)
        self.label_8 = QtWidgets.QLabel(self.widget_11)
        self.label_8.setObjectName("label_8")
        self.verticalLayout_6.addWidget(self.label_8)
        self.label_9 = QtWidgets.QLabel(self.widget_11)
        self.label_9.setObjectName("label_9")
        self.verticalLayout_6.addWidget(self.label_9)
        self.horizontalLayout_3.addWidget(self.widget_11)
        self.widget_12 = QtWidgets.QWidget(self.widget_5)
        self.widget_12.setMinimumSize(QtCore.QSize(150, 0))
        self.widget_12.setMaximumSize(QtCore.QSize(150, 16777215))
        self.widget_12.setObjectName("widget_12")
        self.verticalLayout_7 = QtWidgets.QVBoxLayout(self.widget_12)
        self.verticalLayout_7.setObjectName("verticalLayout_7")
        self.id_lineEdit = QtWidgets.QLineEdit(self.widget_12)
        self.id_lineEdit.setMinimumSize(QtCore.QSize(0, 23))
        self.id_lineEdit.setMaximumSize(QtCore.QSize(16777215, 23))
        self.id_lineEdit.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.id_lineEdit.setObjectName("id_lineEdit")
        self.verticalLayout_7.addWidget(self.id_lineEdit)
        self.pw_lineEdit = QtWidgets.QLineEdit(self.widget_12)
        self.pw_lineEdit.setMinimumSize(QtCore.QSize(0, 23))
        self.pw_lineEdit.setMaximumSize(QtCore.QSize(16777215, 23))
        self.pw_lineEdit.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.pw_lineEdit.setEchoMode(QtWidgets.QLineEdit.Password)
        self.pw_lineEdit.setObjectName("pw_lineEdit")
        self.verticalLayout_7.addWidget(self.pw_lineEdit)
        self.name_lineEdit = QtWidgets.QLineEdit(self.widget_12)
        self.name_lineEdit.setMinimumSize(QtCore.QSize(0, 23))
        self.name_lineEdit.setMaximumSize(QtCore.QSize(16777215, 23))
        self.name_lineEdit.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.name_lineEdit.setObjectName("name_lineEdit")
        self.verticalLayout_7.addWidget(self.name_lineEdit)
        self.horizontalLayout_3.addWidget(self.widget_12)
        self.widget_14 = QtWidgets.QWidget(self.widget_5)
        self.widget_14.setObjectName("widget_14")
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout(self.widget_14)
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.btn_idcheck = QtWidgets.QPushButton(self.widget_14)
        self.btn_idcheck.setMinimumSize(QtCore.QSize(50, 20))
        self.btn_idcheck.setMaximumSize(QtCore.QSize(70, 20))
        self.btn_idcheck.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;\n"
"")
        self.btn_idcheck.setObjectName("btn_idcheck")
        self.horizontalLayout_6.addWidget(self.btn_idcheck)
        self.horizontalLayout_3.addWidget(self.widget_14, 0, QtCore.Qt.AlignTop)
        self.verticalLayout_3.addWidget(self.widget_5)
        self.widget_13 = QtWidgets.QWidget(self.widget_4)
        self.widget_13.setObjectName("widget_13")
        self.verticalLayout_8 = QtWidgets.QVBoxLayout(self.widget_13)
        self.verticalLayout_8.setObjectName("verticalLayout_8")
        self.btn_3 = QtWidgets.QPushButton(self.widget_13)
        self.btn_3.setMinimumSize(QtCore.QSize(100, 30))
        self.btn_3.setMaximumSize(QtCore.QSize(100, 30))
        self.btn_3.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;\n"
"background-color: rgba(249, 224, 0, 117);\n"
"")
        self.btn_3.setObjectName("btn_3")
        self.verticalLayout_8.addWidget(self.btn_3)
        self.verticalLayout_3.addWidget(self.widget_13, 0, QtCore.Qt.AlignHCenter)
        self.verticalLayout_9.addWidget(self.widget_4)
        self.label_6 = QtWidgets.QLabel(self.signup_page)
        self.label_6.setGeometry(QtCore.QRect(90, 10, 120, 238))
        self.label_6.setText("")
        self.label_6.setPixmap(QtGui.QPixmap("톡이미지1.jpg"))
        self.label_6.setObjectName("label_6")
        self.stackedWidget.addWidget(self.signup_page)
        self.friendlist_page = QtWidgets.QWidget()
        self.friendlist_page.setObjectName("friendlist_page")
        self.widget_15 = QtWidgets.QWidget(self.friendlist_page)
        self.widget_15.setGeometry(QtCore.QRect(0, 0, 300, 121))
        self.widget_15.setMinimumSize(QtCore.QSize(300, 0))
        self.widget_15.setMaximumSize(QtCore.QSize(300, 16777215))
        self.widget_15.setObjectName("widget_15")
        self.label = QtWidgets.QLabel(self.widget_15)
        self.label.setGeometry(QtCore.QRect(9, 15, 51, 21))
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.widget_16 = QtWidgets.QWidget(self.widget_15)
        self.widget_16.setGeometry(QtCore.QRect(9, 40, 111, 81))
        self.widget_16.setObjectName("widget_16")
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout(self.widget_16)
        self.horizontalLayout_7.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.profile_label = QtWidgets.QLabel(self.widget_16)
        self.profile_label.setMinimumSize(QtCore.QSize(50, 50))
        self.profile_label.setMaximumSize(QtCore.QSize(50, 50))
        self.profile_label.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.profile_label.setText("")
        self.profile_label.setPixmap(QtGui.QPixmap("플이미지.png"))
        self.profile_label.setAlignment(QtCore.Qt.AlignCenter)
        self.profile_label.setObjectName("profile_label")
        self.horizontalLayout_7.addWidget(self.profile_label)
        self.name_label = QtWidgets.QLabel(self.widget_16)
        self.name_label.setObjectName("name_label")
        self.horizontalLayout_7.addWidget(self.name_label)
        self.name_label.raise_()
        self.profile_label.raise_()
        self.btn_chat = QtWidgets.QPushButton(self.widget_15)
        self.btn_chat.setGeometry(QtCore.QRect(230, 50, 51, 51))
        self.btn_chat.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.btn_chat.setText("")
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap("채팅.PNG"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.btn_chat.setIcon(icon1)
        self.btn_chat.setIconSize(QtCore.QSize(40, 40))
        self.btn_chat.setAutoDefault(False)
        self.btn_chat.setFlat(False)
        self.btn_chat.setObjectName("btn_chat")
        self.scrollArea = QtWidgets.QScrollArea(self.friendlist_page)
        self.scrollArea.setEnabled(True)
        self.scrollArea.setGeometry(QtCore.QRect(0, 110, 300, 391))
        self.scrollArea.setMinimumSize(QtCore.QSize(300, 0))
        self.scrollArea.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 300, 391))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.f_widget4 = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.f_widget4.setGeometry(QtCore.QRect(11, 303, 109, 72))
        self.f_widget4.setObjectName("f_widget4")
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout(self.f_widget4)
        self.horizontalLayout_8.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.profile_label_2 = QtWidgets.QLabel(self.f_widget4)
        self.profile_label_2.setMinimumSize(QtCore.QSize(50, 50))
        self.profile_label_2.setMaximumSize(QtCore.QSize(50, 50))
        self.profile_label_2.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.profile_label_2.setText("")
        self.profile_label_2.setPixmap(QtGui.QPixmap("플이미지.png"))
        self.profile_label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.profile_label_2.setObjectName("profile_label_2")
        self.horizontalLayout_8.addWidget(self.profile_label_2)
        self.btn_name4 = QtWidgets.QPushButton(self.f_widget4)
        self.btn_name4.setFlat(True)
        self.btn_name4.setObjectName("btn_name4")
        self.horizontalLayout_8.addWidget(self.btn_name4)
        self.f_widget1 = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.f_widget1.setGeometry(QtCore.QRect(11, 28, 109, 72))
        self.f_widget1.setObjectName("f_widget1")
        self.horizontalLayout_9 = QtWidgets.QHBoxLayout(self.f_widget1)
        self.horizontalLayout_9.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_9.setObjectName("horizontalLayout_9")
        self.profile_label_3 = QtWidgets.QLabel(self.f_widget1)
        self.profile_label_3.setMinimumSize(QtCore.QSize(50, 50))
        self.profile_label_3.setMaximumSize(QtCore.QSize(50, 50))
        self.profile_label_3.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.profile_label_3.setText("")
        self.profile_label_3.setPixmap(QtGui.QPixmap("플이미지.png"))
        self.profile_label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.profile_label_3.setObjectName("profile_label_3")
        self.horizontalLayout_9.addWidget(self.profile_label_3)
        self.btn_name1 = QtWidgets.QPushButton(self.f_widget1)
        self.btn_name1.setFlat(True)
        self.btn_name1.setObjectName("btn_name1")
        self.horizontalLayout_9.addWidget(self.btn_name1)
        self.f_widget3 = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.f_widget3.setGeometry(QtCore.QRect(11, 211, 109, 72))
        self.f_widget3.setObjectName("f_widget3")
        self.horizontalLayout_10 = QtWidgets.QHBoxLayout(self.f_widget3)
        self.horizontalLayout_10.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_10.setObjectName("horizontalLayout_10")
        self.profile_label_4 = QtWidgets.QLabel(self.f_widget3)
        self.profile_label_4.setMinimumSize(QtCore.QSize(50, 50))
        self.profile_label_4.setMaximumSize(QtCore.QSize(50, 50))
        self.profile_label_4.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.profile_label_4.setText("")
        self.profile_label_4.setPixmap(QtGui.QPixmap("플이미지.png"))
        self.profile_label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.profile_label_4.setObjectName("profile_label_4")
        self.horizontalLayout_10.addWidget(self.profile_label_4)
        self.btn_name3 = QtWidgets.QPushButton(self.f_widget3)
        self.btn_name3.setFlat(True)
        self.btn_name3.setObjectName("btn_name3")
        self.horizontalLayout_10.addWidget(self.btn_name3)
        self.f_widget2 = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.f_widget2.setGeometry(QtCore.QRect(11, 120, 109, 72))
        self.f_widget2.setObjectName("f_widget2")
        self.horizontalLayout_13 = QtWidgets.QHBoxLayout(self.f_widget2)
        self.horizontalLayout_13.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_13.setObjectName("horizontalLayout_13")
        self.profile_label_7 = QtWidgets.QLabel(self.f_widget2)
        self.profile_label_7.setMinimumSize(QtCore.QSize(50, 50))
        self.profile_label_7.setMaximumSize(QtCore.QSize(50, 50))
        self.profile_label_7.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.profile_label_7.setText("")
        self.profile_label_7.setPixmap(QtGui.QPixmap("플이미지.png"))
        self.profile_label_7.setAlignment(QtCore.Qt.AlignCenter)
        self.profile_label_7.setObjectName("profile_label_7")
        self.horizontalLayout_13.addWidget(self.profile_label_7)
        self.btn_name2 = QtWidgets.QPushButton(self.f_widget2)
        self.btn_name2.setFlat(True)
        self.btn_name2.setObjectName("btn_name2")
        self.horizontalLayout_13.addWidget(self.btn_name2)
        self.line = QtWidgets.QFrame(self.scrollAreaWidgetContents)
        self.line.setEnabled(True)
        self.line.setGeometry(QtCore.QRect(10, 10, 282, 3))
        self.line.setStyleSheet("color: rgb(199, 199, 199);")
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.label_2 = QtWidgets.QLabel(self.scrollAreaWidgetContents)
        self.label_2.setGeometry(QtCore.QRect(20, 20, 56, 12))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(8)
        self.label_2.setFont(font)
        self.label_2.setStyleSheet("color: rgb(188, 188, 188);")
        self.label_2.setObjectName("label_2")
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.stackedWidget.addWidget(self.friendlist_page)
        self.chat_page = QtWidgets.QWidget()
        self.chat_page.setObjectName("chat_page")
        self.search_lineEdit = QtWidgets.QLineEdit(self.chat_page)
        self.search_lineEdit.setGeometry(QtCore.QRect(0, 0, 271, 31))
        self.search_lineEdit.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.search_lineEdit.setFrame(False)
        self.search_lineEdit.setObjectName("search_lineEdit")
        self.output_textEdit = QtWidgets.QTextEdit(self.chat_page)
        self.output_textEdit.setGeometry(QtCore.QRect(0, 30, 300, 411))
        self.output_textEdit.setMinimumSize(QtCore.QSize(300, 0))
        self.output_textEdit.setMaximumSize(QtCore.QSize(215, 16777215))
        self.output_textEdit.setStyleSheet("border:1px solid lightgray;\n"
"")
        self.output_textEdit.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.output_textEdit.setObjectName("output_textEdit")
        self.widget_17 = QtWidgets.QWidget(self.chat_page)
        self.widget_17.setGeometry(QtCore.QRect(0, 440, 300, 61))
        self.widget_17.setMinimumSize(QtCore.QSize(300, 0))
        self.widget_17.setMaximumSize(QtCore.QSize(300, 16777215))
        self.widget_17.setObjectName("widget_17")
        self.horizontalLayout_12 = QtWidgets.QHBoxLayout(self.widget_17)
        self.horizontalLayout_12.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_12.setObjectName("horizontalLayout_12")
        self.widget_18 = QtWidgets.QWidget(self.widget_17)
        self.widget_18.setObjectName("widget_18")
        self.horizontalLayout_14 = QtWidgets.QHBoxLayout(self.widget_18)
        self.horizontalLayout_14.setObjectName("horizontalLayout_14")
        self.input_lineEdit = QtWidgets.QLineEdit(self.widget_18)
        self.input_lineEdit.setMinimumSize(QtCore.QSize(210, 25))
        self.input_lineEdit.setMaximumSize(QtCore.QSize(16777215, 25))
        self.input_lineEdit.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.input_lineEdit.setObjectName("input_lineEdit")
        self.horizontalLayout_14.addWidget(self.input_lineEdit)
        self.horizontalLayout_12.addWidget(self.widget_18)
        self.widget_19 = QtWidgets.QWidget(self.widget_17)
        self.widget_19.setMinimumSize(QtCore.QSize(50, 0))
        self.widget_19.setMaximumSize(QtCore.QSize(50, 16777215))
        self.widget_19.setObjectName("widget_19")
        self.horizontalLayout_15 = QtWidgets.QHBoxLayout(self.widget_19)
        self.horizontalLayout_15.setObjectName("horizontalLayout_15")
        self.btn_send = QtWidgets.QPushButton(self.widget_19)
        self.btn_send.setMinimumSize(QtCore.QSize(35, 30))
        self.btn_send.setMaximumSize(QtCore.QSize(35, 30))
        self.btn_send.setStyleSheet("border:1px solid lightgray;\n"
"border-radius:5px;")
        self.btn_send.setFlat(False)
        self.btn_send.setObjectName("btn_send")
        self.horizontalLayout_15.addWidget(self.btn_send, 0, QtCore.Qt.AlignLeft)
        self.horizontalLayout_12.addWidget(self.widget_19, 0, QtCore.Qt.AlignLeft)
        self.btn_search = QtWidgets.QPushButton(self.chat_page)
        self.btn_search.setGeometry(QtCore.QRect(270, 0, 31, 31))
        self.btn_search.setText("")
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap("검색1.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.btn_search.setIcon(icon2)
        self.btn_search.setIconSize(QtCore.QSize(25, 25))
        self.btn_search.setFlat(True)
        self.btn_search.setObjectName("btn_search")
        self.search_lineEdit.raise_()
        self.widget_17.raise_()
        self.btn_search.raise_()
        self.output_textEdit.raise_()
        self.stackedWidget.addWidget(self.chat_page)
        self.result_page = QtWidgets.QWidget()
        self.result_page.setObjectName("result_page")
        self.label_10 = QtWidgets.QLabel(self.result_page)
        self.label_10.setGeometry(QtCore.QRect(20, 20, 81, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_10.setFont(font)
        self.label_10.setObjectName("label_10")
        self.result_textEdit = QtWidgets.QTextEdit(self.result_page)
        self.result_textEdit.setGeometry(QtCore.QRect(0, 50, 300, 451))
        self.result_textEdit.setMinimumSize(QtCore.QSize(300, 0))
        self.result_textEdit.setMaximumSize(QtCore.QSize(300, 16777215))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.result_textEdit.setFont(font)
        self.result_textEdit.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.result_textEdit.setObjectName("result_textEdit")
        self.stackedWidget.addWidget(self.result_page)

        self.retranslateUi(join)
        self.stackedWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(join)

    def retranslateUi(self, join):
        _translate = QtCore.QCoreApplication.translate
        join.setWindowTitle(_translate("join", "Form"))
        self.label_3.setText(_translate("join", "ID"))
        self.label_4.setText(_translate("join", "PW"))
        self.btn_2.setText(_translate("join", "로그인"))
        self.btn_1.setText(_translate("join", "회원가입"))
        self.label_7.setText(_translate("join", "ID"))
        self.label_8.setText(_translate("join", "PW"))
        self.label_9.setText(_translate("join", "이름"))
        self.btn_idcheck.setText(_translate("join", "확인"))
        self.btn_3.setText(_translate("join", "회원가입"))
        self.label.setText(_translate("join", " 친구"))
        self.name_label.setText(_translate("join", "이름"))
        self.btn_name4.setText(_translate("join", "이름"))
        self.btn_name1.setText(_translate("join", "이름"))
        self.btn_name3.setText(_translate("join", "이름"))
        self.btn_name2.setText(_translate("join", "이름"))
        self.label_2.setText(_translate("join", "목록"))
        self.btn_send.setText(_translate("join", "send"))
        self.label_10.setText(_translate("join", "검색 결과"))