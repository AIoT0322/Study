import sys
from socket import *
from threading import Thread

from PyQt5.QtWidgets import *
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication
import time

from UI_join import Ui_join


class Mainui(QWidget, Ui_join):

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.data = list()
        self.sock = socket(AF_INET, SOCK_STREAM)  # 소켓
        self.sock.connect(('127.0.0.1', 9999))  # 소켓연결
        self.btn_1.clicked.connect(lambda: self.move_page('회원가입'))
        self.btn_3.clicked.connect(self.joinButton)
        self.btn_2.clicked.connect(self.login)
        self.btn_idcheck.clicked.connect(self.idcheck)
        self.btn_name1.clicked.connect(lambda: self.move_page('채팅1'))
        self.btn_name2.clicked.connect(lambda: self.move_page('채팅2'))
        self.btn_name3.clicked.connect(lambda: self.move_page('채팅3'))
        self.btn_name4.clicked.connect(lambda: self.move_page('채팅4'))
        self.btn_send.clicked.connect(self.send_msg)

    def move_page(self, page):  # 페이지 이동 함수
        if page == '로그인':
            self.stackedWidget.setCurrentWidget(self.login_page)
        elif page == '회원가입':
            self.stackedWidget.setCurrentWidget(self.signup_page)
        elif page == '친구목록':
            self.stackedWidget.setCurrentWidget(self.friendlist_page)
            self.setname()
            receiver = Thread(target=self.receive_messages, args=(self.sock,))  # 수신 스레드
            receiver.start()
        elif '채팅' in page:
            self.stackedWidget.setCurrentWidget(self.chat_page)
            # my_name = self.name_label.text()
            # msg = self.input_textEdit.toPlainText()
            #
            # if page == '채팅1':
            #     your_name = self.btn_name1.text()
            #     self.sock.send(f'invite/{your_name}'.encode())
            # elif page == '채팅2':
            #     your_name = self.btn_name2.text()
            # elif page == '채팅3':
            #     your_name = self.btn_name3.text()
            # elif page == '채팅4':
            #     your_name = self.btn_name4.text()
            #
            # if your_name:
            #     sendData = f'chat/{my_name}/{your_name}/{msg}'
            #     self.sock.send(sendData.encode('utf-8'))
            #     self.input_textEdit.clear()

    def join(self):  # 회원가입
        self.id = self.id_lineEdit.text()
        self.pw = self.pw_lineEdit.text()
        self.name = self.name_lineEdit.text()
        self.sock.send(f'{self.id}/{self.pw}/{self.name}'.encode('utf-8'))

    def idcheck(self):  # id중복확인
        self.sign_id = self.id_lineEdit.text()  # 회원가입 ID lineEdit 값 가져오기

        sendData = f"{'signup/' + self.sign_id}"
        self.sock.send(sendData.encode())

        recv_message = self.sock.recv(4096).decode()
        print('회원가입 메시지: ', recv_message)

        if '!OK' in recv_message:
            QMessageBox.information(self, '알림', '사용가능한 ID입니다.')
        elif 'null' in recv_message:
            QMessageBox.information(self, '알림', 'ID를 입력해주세요.')
        else:
            QMessageBox.information(self, '알림', '이미 존재하는 ID입니다.')

    def joinButton(self):
        self.join()
        self.move_page('로그인')

    def login(self):
        self.login_id = self.lineEdit_3.text()  # 로그인 ID lineEdit 값 가져오기
        self.login_pw = self.lineEdit_4.text()  # 로그인 PW lineEdit 값 가져오기
        self.sock.send(f"{'login/' + self.login_id + '/' + self.login_pw}".encode())  # 로그인/ID/PW
        print('아이디:', self.login_id)
        recv_message = self.sock.recv(4096).decode()
        print('로그인 메시지: ', recv_message)

        if '!OK' in recv_message:
            recv_name = self.sock.recv(1024).decode()
            # print(recv_name)
            self.name_label.setText(recv_name)
            self.move_page('친구목록')  # 로그인 성공 시 다음 페이지로 이동

        elif 'not' in recv_message:
            QMessageBox.information(self, '알림', 'ID와 PW가 일치하지 않습니다.')
        elif 'null' in recv_message:
            QMessageBox.information(self, '알림', '아이디와 비밀번호를 입력하세요.')
        else:
            QMessageBox.information(self, '알림', '존재하지 않는 ID입니다.')

    def setname(self):  # 이름 받아와서 출력하는 함수
        self.sock.send("getnames".encode())
        recv_names = self.sock.recv(4096).decode('utf-8')  # 서버에서 사용자 이름 받기
        names = recv_names.split('/')  # 받은 이름을 리스트로 분할
        names.remove(self.name_label.text())
        # 사용자 이름을 적절한 버튼에 할당하기
        if len(names) >= 4:
            self.btn_name1.setText(names[0])
            self.btn_name2.setText(names[1])
            self.btn_name3.setText(names[2])
            self.btn_name4.setText(names[3])

    def send_msg(self):
        msg = self.input_textEdit.toPlainText()
        self.output_textEdit.setText(msg)
        self.input_textEdit.clear()

    def receive_messages(self, sock):  # 메시지 받기
        while True:
            recv_message = sock.recv(4096)
            self.final_message = recv_message.decode('utf-8')

            print(self.final_message)

            if 'chat/' in self.final_message:
                name = self.final_message.split('/')[-3]
                chat = self.final_message.split('/')[-1]

                self.output_textEdit.append(name + ":" + chat)
                pass

            elif '채팅 초대' in self.final_message:
                # QmessageBox로 yes or no 판별
                invite = QMessageBox.question(self, "채팅요청", "상대가 채팅을 신청하였습니다. ", QMessageBox.Yes | QMessageBox.No,
                                              QMessageBox.Yes)

                if invite == QMessageBox.Yes:
                    self.sock.send('yes'.encode())
                    self.move_page('채팅')

                else:
                    self.sock.send('수락 거절'.encode())

            elif '수락' in self.final_message:
                self.move_page('채팅')


def show_error_message(message, traceback):
    msg_box = QtWidgets.QMessageBox()
    msg_box.setIcon(QtWidgets.QMessageBox.Critical)
    msg_box.setWindowTitle("Error")
    msg_box.setText(message)
    msg_box.exec()
    traceback.print_exc()


if __name__ == '__main__':
    myapp = QApplication(sys.argv)
    myform = Mainui()
    myform.show()
    sys.excepthook = lambda exctype, value, traceback: show_error_message(str(value), traceback)
    sys.exit(myapp.exec())
