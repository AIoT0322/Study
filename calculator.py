import sys

from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication

from converted_cal import Ui_Form


class calculator(QtWidgets.QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        # adding action to each of the button
        self.Button0.clicked.connect(self.action0)
        self.Button1.clicked.connect(self.action1)
        self.Button2.clicked.connect(self.action2)
        self.Button3.clicked.connect(self.action3)
        self.Button4.clicked.connect(self.action4)
        self.Button5.clicked.connect(self.action5)
        self.Button6.clicked.connect(self.action6)
        self.Button7.clicked.connect(self.action7)
        self.Button8.clicked.connect(self.action8)
        self.Button9.clicked.connect(self.action9)
        self.Buttonminus.clicked.connect(self.action_minus)
        self.Buttonequal.clicked.connect(self.action_equal)
        self.Buttondivide.clicked.connect(self.action_div)
        self.Buttonmul.clicked.connect(self.action_mul)
        self.Buttonplus.clicked.connect(self.action_plus)
        self.ButtonC.clicked.connect(self.action_clear)


    def action_equal(self):
        # get the label text
        equation = self.labelresult.text()

        try:
            # getting the ans
            ans = eval(equation)

            # setting text to the label
            self.labelresult.setText(str(ans))

        except:
            # setting text to the label
            self.labelresult.setText("Wrong Input")


    def action_plus(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + " + ")


    def action_minus(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + " - ")


    def action_div(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + " / ")


    def action_mul(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + " * ")



    def action0(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "0")


    def action1(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "1")


    def action2(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "2")


    def action3(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "3")


    def action4(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "4")


    def action5(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "5")


    def action6(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "6")


    def action7(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "7")


    def action8(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "8")


    def action9(self):
        # appending label text
        text = self.labelresult.text()
        self.labelresult.setText(text + "9")


    def action_clear(self):
        # clearing the label text
        self.labelresult.setText("")



if __name__ == '__main__':
    myapp = QApplication(sys.argv)
    myform = calculator()
    myform.show()


    def show_error_message(message, traceback):
        msg_box = QtWidgets.QMessageBox()
        msg_box.setIcon(QtWidgets.QMessageBox.Critical)
        msg_box.setWindowTitle("Error")
        msg_box.setText(message)
        msg_box.exec()
        traceback.print_exc()


    sys.excepthook = lambda exctype, value, traceback: show_error_message(str(value), traceback)

    myapp.exec()
