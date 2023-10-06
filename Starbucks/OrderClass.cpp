#include "OrderClass.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <numeric>

using namespace std;

OrderClass::OrderClass()
{
   //생성자
}

void OrderClass::Choice(int menunum, int sizenum)
{
    while (1)
    {
        cout << "원하는 메뉴를 선택하세요." << endl;
        cin >> menu;
        if (menu < 1 or menu > menunum)
        {
            cout << "잘못된 번호입니다. 다시 선택해주세요" << endl;
            continue;
        }
        else
            break;
    }
    while (1)
    {
        cout << "음료의 사이즈를 선택하세요." << endl;
        cin >> size;
        if (size < 1 or size > sizenum)
        {
            cout << "잘못된 번호입니다. 다시 선택해주세요" << endl;
            continue;
        }
        else
            break;
    }
    while (1)
    {
        cout << "몇 잔 주문하시겠습니까?" << endl;
        cin >> num;
        if (num < 1)
        {
            cout << "잘못된 번호입니다. 다시 선택해주세요" << endl;
            continue;
        }
        else
            break;
    }
}

void OrderClass::Coffee()
{
    const char* coffeemenu[7] = { "아메리카노", "카페라떼", "카푸치노", "카라멜마끼아또", "화이트초콜릿모카", "카페모카", "돌체라떼" };
    int coffee[7][4] = {
        {4000, 4500, 5000, 5500},
        {4500, 5000, 5500, 6000},
        {4500, 5000, 5500, 6000},
        {5400, 5900, 6400, 6900},
        {5400, 5900, 6400, 6900},
        {5000, 5500, 6000, 6500},
        {5400, 5900, 6400, 6900}
    };

    sum1 = coffee[menu - 1][size - 1] * num;
    cout << "주문 금액: " << sum1;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum1);
    ordermenu.push_back(coffeemenu[menu - 1]);
}

void OrderClass::Coldbrew()
{
    const char* coldbrewmenu[4] = { "콜드브루오트라떼", "돌체콜드브루", "바닐라크림콜드브루", "콜드브루" };
    int coldbrew[4][3] = {
        {5800, 6300, 6800},
        {6000, 6500, 7000},
        {5800, 6300, 6800},
        {4900, 5400, 5900}
    };

    sum2 = coldbrew[menu - 1][size - 1] * num;
    cout << "주문 금액: " << sum2;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum2);
    ordermenu.push_back(coldbrewmenu[menu - 1]);
}

void OrderClass::Frappuccino()
{
    const char* frappuccinomenu[9] = { "더블에스프레소칩프라푸치노", "제주유기농말차로만든크림프라푸치노", "자바칩프라푸치노", "초콜릿크림칩프라푸치노", "화이트초콜릿모카프라푸치노", "모카프라푸치노", "카라멜프라푸치노", "에스프레소프라푸치노", "바닐라크림프라푸치노" };
    int frappuccino[9][3] = {
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {6000, 6500, 7000},
        {6000, 6500, 7000},
        {6000, 6500, 7000},
        {5900, 6400, 6900},
        {5500, 6000, 6500},
        {5500, 6000, 6500}
    };

    sum3 = frappuccino[menu - 1][size - 1] * num;
    cout << "주문 금액: " << sum3;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum3);
    ordermenu.push_back(frappuccinomenu[menu - 1]);
}

void OrderClass::Blended()
{
    const char* blendedmenu[5] = { "민트초콜릿칩블렌디드", "딸기딜라이트요거트블렌디드", "피치&레몬블렌디드", "망고바나나블렌디드", "망고패션프루트블렌디드" };
    int blended[5][3] = {
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {5400, 5900, 6400}
    };

    sum4 = blended[menu - 1][size - 1] * num;
    cout << "주문 금액: " << sum4;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum4);
    ordermenu.push_back(blendedmenu[menu - 1]);
}

void OrderClass::Fizzio()
{
    const char* fizziomenu[3] = { "쿨라임피지오", "블랙티레모네이드피지오", "패션탱고티레모네이드피지오" };
    int fizzio[3][3] = {
        {5900, 6400, 6900},
        {5400, 5900, 6400},
        {5400, 5900, 6400}
    };

    sum5 = fizzio[menu - 1][size - 1] * num;
    cout << "주문 금액: " << sum5;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum5);
    ordermenu.push_back(fizziomenu[menu - 1]);   
}

void OrderClass::Tea()
{
    const char* teamenu[8] = { "뉴이어시트러스티", "돌체블랙밀크티", "유자민트티", "패션프루트티", "제주유기농말차로만든라떼", "차이티라떼", "라임패션티", "자몽허니블랙티" };
    int tea[8][3] = {
        {6100, 6600, 7100},
        {5900, 6400, 6900},
        {5900, 6400, 6900},
        {5900, 6400, 6900},
        {6100, 6600, 7100},
        {5500, 6000, 6500},
        {5900, 6400, 6900},
        {5700, 6200, 6700}
    };

    sum6 = tea[menu - 1][size - 1] * num;
    cout << "주문 금액: " << sum6;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum6);
    ordermenu.push_back(teamenu[menu - 1]);
}

void OrderClass::Calculate()
{
    int discount;
    unordered_map<string, int> orderlist;
    auto menuIter = ordermenu.begin();
    auto numIter = menunum.begin();

    while (menuIter != ordermenu.end() && numIter != menunum.end()) 
    {
        orderlist[*menuIter] = *numIter;
        ++menuIter;
        ++numIter;
    }
    
    cout << "---------------장바구니---------------" << endl;
    for (const auto& pair : orderlist) 
    {
        cout << pair.first << " " << pair.second << "개" << endl;
    }
    cout << endl;

    money = accumulate(total.begin(), total.end(), 0);
    cout << "총 주문 금액: " << money << "원" << endl;
    cout << endl;

    while (1)
    {
        cout << "1. 멤버쉽 할인  2. 할인 없이 계산" << endl;
        cin >> discount;

        if (discount == 1)
        {
            Membership();
            break;
        }
        else if (discount == 2)
        {
            cout << "총 주문 금액: " << money << "원" << "결제되었습니다." << endl;
            cout << "감사합니다." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
            break;
        }
        else
        {
            cout << "잘못된 번호입니다. 다시 선택해주세요." << endl;
            continue;
        }
    }
}

void OrderClass::Membership()
{
    int member = rand() % 3;
    if (member == 0)
    {
        cout << "멤버쉽 등급은 Silver입니다!" << endl;
        if (money < 10000)
        {
            cout << "총 주문금액이 최소 금액보다 적어 할인을 적용할 수 없습니다." << endl;
            cout << "총 주문 금액: " << money << "원" << "결제되었습니다." << endl;
            cout << "감사합니다." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
        else
        {
            cout << "총 주문 금액: " << money*0.95 << "원" << "결제되었습니다." << endl;
            cout << "감사합니다." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
    }
    else if (member == 1)
    {
        cout << "멤버쉽 등급은 Gold입니다!" << endl;
        if (money < 20000)
        {
            cout << "총 주문금액이 최소 금액보다 적어 할인을 적용할 수 없습니다." << endl;
            cout << "총 주문 금액: " << money << "원" << "결제되었습니다." << endl;
            cout << "감사합니다." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
        else
        {
            cout << "총 주문 금액: " << money * 0.85 << "원" << "결제되었습니다." << endl;
            cout << "감사합니다." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
    }
    else
    {
        cout << "멤버쉽 등급은 Vip입니다!" << endl;
        cout << "총 주문 금액: " << money * 0.85 << "원" << "결제되었습니다." << endl;
        cout << "감사합니다." << endl;
        cout << endl;
        ordermenu.clear();
        total.clear();
    }
}

void OrderClass::Account()
{
    int total = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;
    cout << "----------------카테고리 별 매출----------------" << endl;
    cout << "  커피메뉴                              " << sum1 << "원" << endl;
    cout << "  콜드브루메뉴                          " << sum2 << "원" << endl;
    cout << "  프라푸치노메뉴                        " << sum3 << "원" << endl;
    cout << "  블렌디드메뉴                          " << sum4 << "원" << endl;
    cout << "  피지오메뉴                            " << sum5 << "원" << endl;
    cout << "  티메뉴                                " << sum6 << "원" << endl;
    cout << "------------------------------------------------" << endl;
    cout << " 일 매출 총합                           "<< total << "원" << endl;
    cout << endl;
}