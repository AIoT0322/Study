#include <iostream>
#include "MenuClass.h"
#include "OrderClass.h"
using namespace std;

int main()
{
    int choice;
    OrderClass Order;
    while (1)
    {
        cout << "환영합니다! 스타벅스입니다." << endl;
        cout << "1. 메뉴보기  2. 일매출정산" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int addorder = 0;
            while (1)
            {
                int menu;
                int choice1;
                MenuClass Menu;

                if (addorder == 0)
                {
                    cout << "카테고리를 선택하세요: 1.커피  2.콜드브루  3.프라푸치노  4.블렌디드  5.피지오  6.티" << endl;
                    cin >> menu;
                    if (menu < 1 or menu > 6)
                    {
                        cout << "잘못된 번호입니다. 다시 선택해주세요." << endl;
                        continue;
                    }
                    switch (menu)
                    {
                        int menunum;
                        int sizenum;
                    case 1:
                        menunum = 7;
                        sizenum = 4;
                        Menu.Coffee();
                        Order.Choice(menunum, sizenum);
                        Order.Coffee();
                        break;
                    case 2:
                        menunum = 4;
                        sizenum = 3;
                        Menu.Coldbrew();
                        Order.Choice(menunum, sizenum);
                        Order.Coldbrew();
                        break;
                    case 3:
                        menunum = 9;
                        sizenum = 3;
                        Menu.Frappuccino();
                        Order.Choice(menunum, sizenum);
                        Order.Frappuccino();
                        break;
                    case 4:
                        menunum = 5;
                        sizenum = 3;
                        Menu.Blended();
                        Order.Choice(menunum, sizenum);
                        Order.Blended();
                        break;
                    case 5:
                        menunum = 3;
                        sizenum = 3;
                        Menu.Fizzio();
                        Order.Choice(menunum, sizenum);
                        Order.Fizzio();
                        break;
                    case 6:
                        menunum = 8;
                        sizenum = 3;
                        Menu.Tea();
                        Order.Choice(menunum, sizenum);
                        Order.Tea();
                        break;
                    default:
                        break;
                    }
                }
                              
                cout << "1.추가주문  2.계산" << endl;
                cin >> choice1;
                cout << endl;

                if (choice1 == 1)
                {
                    addorder = 0;
                    continue;
                }
                else if (choice1 == 2)
                    break;
                else
                {
                    cout << "잘못된 번호입니다. 다시 선택해주세요." << endl;
                    addorder = 1;
                }              
            }
        }
        else if(choice == 2)
        {
            Order.Account();
            continue;
        }
        else
        {
            cout << "잘못된 번호입니다. 다시 선택해주세요." << endl;
            continue;
        }
        Order.Calculate();
        continue;
    }
    return 0;
}