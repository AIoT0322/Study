import sys
from PyQt5 import QtWidgets
from PyQt5.QtGui import QPixmap, QIcon
from PyQt5.QtWidgets import QApplication, QWidget, QDialog, QLabel, QVBoxLayout
from UI_Gimbabnara import Ui_Form
from UI_gimbabmenu import Ui_menu
from UI_cart import Ui_cart
from UI_order import Ui_order
from UI_addmenu import Ui_addmenu
from UI_end import Ui_end
import sqlite3

cart_list = []
d = [0]
e = [0]

conn = sqlite3.connect("gimbab.db")  # DB 연결
con = conn.cursor()
con.execute("SELECT * FROM menu")
data = con.fetchall()

class ginbabmenu(QDialog, QWidget, Ui_menu):  # 메뉴선택 화면
    def __init__(self, i):
        super(ginbabmenu, self).__init__()
        self.initUI()
        self.i = i
        self.pixmap = None
        self.setup()
        self.setWindowIcon(QIcon('main.png'))
        self.show()  # 두번째창 실행
        self.btn_plus.clicked.connect(self.plus)
        self.btn_minus.clicked.connect(self.minus)
        self.btn_pluscart.clicked.connect(self.cart)
        self.name = ""
        self.price = ""

    def setup(self):  # 라벨에 이미지 설정
        for j in range(len(data)):
            if int(self.i) == int(data[j][0]):
                self.pixmap = QPixmap(data[j][3])
                self.image = data[j][4]
                self.btn_pluscart.setText(f'{data[j][2]}원 담기')
                self.menu = data[j][1]
        self.photo1.setPixmap(self.pixmap)

        con.close()

    def plus(self):
        for j in range(len(data)):
            if int(self.i) == int(data[j][0]):
                self.name = data[j][1]
                self.price = int(data[j][2])
                b = int(self.label_number.text()) + 1
                c = b * self.price
                self.label_number.setText(str(b))
                self.btn_pluscart.setText(f'{c}원 담기')
        con.close()

    def minus(self):
        b = int(self.label_number.text()) - 1
        for j in range(len(data)):
            if int(self.i) == int(data[j][0]):
                self.name = data[j][1]
                self.price = int(data[j][2])
                c = b * self.price

        if int(b) >= 1:
            self.label_number.setText(str(b))
            self.btn_pluscart.setText(f'{c}원 담기')
        con.close()

    def initUI(self):
        self.setupUi(self)
        self.back_btn.clicked.connect(self.back)

    def cart(self):
        for j in range(len(data)):
            if int(self.i) == int(data[j][0]):
                self.name = data[j][1]
                self.price = int(data[j][2])

        self.total = int(self.label_number.text()) * self.price
        a = [self.name, self.image, self.price, str(self.total)]
        cart_list.append(a)
        self.close()
        con.close()

    def back(self):
        self.close()  # 창 닫기


class ItemWidget(QtWidgets.QWidget, Ui_addmenu):
    def __init__(self, i, cart_instance):  # 디폴트값
        super(ItemWidget, self).__init__()
        self.cart_instance = cart_instance
        self.pixmap = None
        self.setupUi(self)
        self.i = i
        self.set()
        self.pushButton.clicked.connect(lambda state: self.remove_widget(i))

    def set(self):
        self.picture = cart_list[self.i][1]
        self.pixmap = QPixmap(self.picture)
        # 라벨에 이미지 설정
        self.menuname.setText(cart_list[self.i][0])
        self.menuimage.setPixmap(self.pixmap)
        self.cost.setText(f'{cart_list[self.i][2]}원')
        self.sum.setText(f'합계 :     {cart_list[self.i][3]}원')

    def remove_widget(self, i):
        for j in range(len(cart_list)):
            if cart_list[j][0] == self.menuname.text():
                self.i = j
        self.setParent(None)
        self.deleteLater()
        d[0] = int((self.cart_instance.label_11.text()[:-1])) - int(cart_list[self.i][2])
        self.cart_instance.label_11.setText(f'{d[0]}원')
        e[0] = d[0] - 3500
        self.cart_instance.label_10.setText(f'{e[0]}원')
        self.cart_instance.total.setText(f'{d[0]}원')

        del cart_list[self.i]

    # def delete_item(self):
    #     # 아이템 삭제 로직
    #     del cart_list[self.i]
    #     self.cart_instance.remove_item_widget(self)


class Cart(QDialog, QWidget, Ui_cart):  # 장바구니 화면
    def __init__(self):
        super(Cart, self).__init__()
        self.setWindowIcon(QIcon('main.png'))
        self.initUI()
        self.show()  # 장바구니창 실행
        self.total1 = 0
        self.btn_order.clicked.connect(lambda: self.button_Order())

        for i in range(len(cart_list)):
            self.add_widget(i)
            self.total1 += int(cart_list[i][3])

        self.label_10.setText(f'{str(self.total1)}원')
        self.label_11.setText(f'{str(self.total1 + 3500)}원')
        self.total.setText(self.label_11.text())

    def add_widget(self, i):
        if self.addWidget.layout() is None:
            vbox = QVBoxLayout(self.addWidget)
            self.addWidget.setLayout(vbox)

        vbox = self.addWidget.layout()
        Item_widget = ItemWidget(i, self)  # self (현재 Cart 클래스의 인스턴스)를 전달
        vbox.addWidget(Item_widget)

    def initUI(self):
        self.setupUi(self)
        self.back_btn.clicked.connect(self.back)

    def button_Order(self):
        # self.hide()  # 메인 윈도우 숨김
        self.order = Order()
        self.order.exec()  # 주문하기창 닫을때까지 기다림
        # self.show()  # 주문하기창 닫으면 다시 첫 번째 창 보여짐

    def back(self):
        self.close()  # 창 닫기


class Order(QDialog, QWidget, Ui_order):  # 주문하기 화면
    def __init__(self):
        super(Order, self).__init__()
        self.setWindowIcon(QIcon('main.png'))
        self.initUI()
        self.total1 = 0
        self.num = 1
        order_list = []
        self.show()
        self.pushButton.clicked.connect(lambda: self.button_End())
        menu_list = []
        amount_list = []

        for i in range(len(cart_list)):
            self.total1 += int(cart_list[i][3])
            list = [cart_list[i][0], cart_list[i][3], int(int(cart_list[i][3])/cart_list[i][2])]
            order_list.append(list)
            menu_list.append(order_list[i][0])
            amount_list.append(order_list[i][2])

        self.label_6.setText(f'                    {e[0]}원')
        self.label_8.setText(f'                    {d[0]}원')
        self.label_5.setText(f'     {d[0]}원')

        # self.total = int(self.label_number.text()) * self.price
        # a = [self.name, self.image, self.price, str(self.total)]

        conn = sqlite3.connect("gimbab.db")  # DB 연결
        con = conn.cursor()
        con.execute("INSERT INTO olist(mlist, amount, total) VALUES(?, ?, ?)", (str(menu_list), str(amount_list), self.total1))
        conn.commit()
        con.close()

    def initUI(self):
        self.setupUi(self)
        self.back_btn.clicked.connect(self.back)

    def button_End(self):
        self.hide()  # 메인 윈도우 숨김
        self.end = End()
        self.end.exec()  # 장바구니창 닫을때까지 기다림
        self.show()  # 장바구니창 닫으면 다시 첫 번째 창 보여짐

    def back(self):
        self.close()  # 창 닫기


class End(QDialog, QWidget, Ui_end):
    def __init__(self):
        super(End, self).__init__()
        self.setWindowIcon(QIcon('main.png'))
        self.initUI()
        self.show()

    def initUI(self):
        self.setupUi(self)


class MyForm(QtWidgets.QWidget, Ui_Form):  # 첫번째 화면
    def __init__(self):
        super().__init__()
        self.setWindowIcon(QIcon('main.png'))
        self.setupUi(self)
        self.gimbab_btn.clicked.connect(lambda: self.button_Second("1"))
        self.tunagimbab_btn.clicked.connect(lambda: self.button_Second("2"))
        self.shrimp_btn.clicked.connect(lambda: self.button_Second("3"))
        self.dongimbab_btn.clicked.connect(lambda: self.button_Second("4"))
        self.bulgimbab_btn.clicked.connect(lambda: self.button_Second("5"))
        self.zzol_btn.clicked.connect(lambda: self.button_Second("6"))
        self.ttok_btn.clicked.connect(lambda: self.button_Second("7"))
        self.la_btn.clicked.connect(lambda: self.button_Second("8"))
        self.udong_btn.clicked.connect(lambda: self.button_Second("9"))
        self.od_btn.clicked.connect(lambda: self.button_Second("10"))
        self.suje_btn.clicked.connect(lambda: self.button_Second("11"))
        self.kal_btn.clicked.connect(lambda: self.button_Second("12"))
        self.bi_btn.clicked.connect(lambda: self.button_Second("13"))
        self.don_dtn.clicked.connect(lambda: self.button_Second("14"))
        self.chdon_btn.clicked.connect(lambda: self.button_Second("15"))
        self.godon_btn.clicked.connect(lambda: self.button_Second("16"))
        self.kimbok_btn.clicked.connect(lambda: self.button_Second("17"))
        self.shbok_btn.clicked.connect(lambda: self.button_Second("18"))
        self.bibim_btn.clicked.connect(lambda: self.button_Second("19"))
        self.je_btn.clicked.connect(lambda: self.button_Second("20"))
        self.oj_btn.clicked.connect(lambda: self.button_Second("21"))
        self.buldup_btn.clicked.connect(lambda: self.button_Second("22"))
        self.om_btn.clicked.connect(lambda: self.button_Second("23"))
        self.kimzzi_btn.clicked.connect(lambda: self.button_Second("24"))
        self.dzzi_btn.clicked.connect(lambda: self.button_Second("25"))
        self.sun_btn.clicked.connect(lambda: self.button_Second("26"))
        self.budae_btn.clicked.connect(lambda: self.button_Second("27"))
        self.ttuk_btn.clicked.connect(lambda: self.button_Second("28"))
        self.cart_btn.clicked.connect(lambda: self.button_Cart())

    def button_Second(self, i):
        self.hide()  # 메인 윈도우 숨김
        second = ginbabmenu(i)
        second.exec()  # 두번째창 닫을때까지 기다림
        self.show()  # 두번째창 닫으면 다시 첫 번째 창 보여짐

    def button_Cart(self):
        self.hide()  # 메인 윈도우 숨김
        self.cart = Cart()
        self.cart.exec()  # 장바구니창 닫을때까지 기다림
        self.show()  # 장바구니창 닫으면 다시 첫 번째 창 보여짐


def show_error_message(message, traceback):
    msg_box = QtWidgets.QMessageBox()
    msg_box.setIcon(QtWidgets.QMessageBox.Critical)
    msg_box.setWindowTitle("Error")
    msg_box.setText(message)
    msg_box.exec()
    traceback.print_exc()


if __name__ == '__main__':
    myapp = QApplication(sys.argv)
    myform = MyForm()
    myform.show()
    sys.excepthook = lambda exctype, value, traceback: show_error_message(str(value), traceback)
    sys.exit(myapp.exec())
