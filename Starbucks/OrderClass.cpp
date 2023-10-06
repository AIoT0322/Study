#include "OrderClass.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <numeric>

using namespace std;

OrderClass::OrderClass()
{
   //������
}

void OrderClass::Choice(int menunum, int sizenum)
{
    while (1)
    {
        cout << "���ϴ� �޴��� �����ϼ���." << endl;
        cin >> menu;
        if (menu < 1 or menu > menunum)
        {
            cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���" << endl;
            continue;
        }
        else
            break;
    }
    while (1)
    {
        cout << "������ ����� �����ϼ���." << endl;
        cin >> size;
        if (size < 1 or size > sizenum)
        {
            cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���" << endl;
            continue;
        }
        else
            break;
    }
    while (1)
    {
        cout << "�� �� �ֹ��Ͻðڽ��ϱ�?" << endl;
        cin >> num;
        if (num < 1)
        {
            cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���" << endl;
            continue;
        }
        else
            break;
    }
}

void OrderClass::Coffee()
{
    const char* coffeemenu[7] = { "�Ƹ޸�ī��", "ī���", "īǪġ��", "ī��Ḷ���ƶ�", "ȭ��Ʈ���ݸ���ī", "ī���ī", "��ü��" };
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
    cout << "�ֹ� �ݾ�: " << sum1;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum1);
    ordermenu.push_back(coffeemenu[menu - 1]);
}

void OrderClass::Coldbrew()
{
    const char* coldbrewmenu[4] = { "�ݵ����Ʈ��", "��ü�ݵ���", "�ٴҶ�ũ���ݵ���", "�ݵ���" };
    int coldbrew[4][3] = {
        {5800, 6300, 6800},
        {6000, 6500, 7000},
        {5800, 6300, 6800},
        {4900, 5400, 5900}
    };

    sum2 = coldbrew[menu - 1][size - 1] * num;
    cout << "�ֹ� �ݾ�: " << sum2;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum2);
    ordermenu.push_back(coldbrewmenu[menu - 1]);
}

void OrderClass::Frappuccino()
{
    const char* frappuccinomenu[9] = { "������������Ĩ����Ǫġ��", "������������θ���ũ������Ǫġ��", "�ڹ�Ĩ����Ǫġ��", "���ݸ�ũ��Ĩ����Ǫġ��", "ȭ��Ʈ���ݸ���ī����Ǫġ��", "��ī����Ǫġ��", "ī�������Ǫġ��", "��������������Ǫġ��", "�ٴҶ�ũ������Ǫġ��" };
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
    cout << "�ֹ� �ݾ�: " << sum3;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum3);
    ordermenu.push_back(frappuccinomenu[menu - 1]);
}

void OrderClass::Blended()
{
    const char* blendedmenu[5] = { "��Ʈ���ݸ�Ĩ�����", "���������Ʈ���Ʈ�����", "��ġ&��������", "����ٳ��������", "�����м�����Ʈ�����" };
    int blended[5][3] = {
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {6300, 6800, 7300},
        {5400, 5900, 6400}
    };

    sum4 = blended[menu - 1][size - 1] * num;
    cout << "�ֹ� �ݾ�: " << sum4;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum4);
    ordermenu.push_back(blendedmenu[menu - 1]);
}

void OrderClass::Fizzio()
{
    const char* fizziomenu[3] = { "�����������", "��Ƽ������̵�������", "�м��ʰ�Ƽ������̵�������" };
    int fizzio[3][3] = {
        {5900, 6400, 6900},
        {5400, 5900, 6400},
        {5400, 5900, 6400}
    };

    sum5 = fizzio[menu - 1][size - 1] * num;
    cout << "�ֹ� �ݾ�: " << sum5;
    cout << endl;
    menunum.push_back(num);
    total.push_back(sum5);
    ordermenu.push_back(fizziomenu[menu - 1]);   
}

void OrderClass::Tea()
{
    const char* teamenu[8] = { "���̾��Ʈ����Ƽ", "��ü����ũƼ", "���ڹ�ƮƼ", "�м�����ƮƼ", "������������θ����", "����Ƽ��", "�����м�Ƽ", "�ڸ���Ϻ�Ƽ" };
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
    cout << "�ֹ� �ݾ�: " << sum6;
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
    
    cout << "---------------��ٱ���---------------" << endl;
    for (const auto& pair : orderlist) 
    {
        cout << pair.first << " " << pair.second << "��" << endl;
    }
    cout << endl;

    money = accumulate(total.begin(), total.end(), 0);
    cout << "�� �ֹ� �ݾ�: " << money << "��" << endl;
    cout << endl;

    while (1)
    {
        cout << "1. ����� ����  2. ���� ���� ���" << endl;
        cin >> discount;

        if (discount == 1)
        {
            Membership();
            break;
        }
        else if (discount == 2)
        {
            cout << "�� �ֹ� �ݾ�: " << money << "��" << "�����Ǿ����ϴ�." << endl;
            cout << "�����մϴ�." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
            break;
        }
        else
        {
            cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �������ּ���." << endl;
            continue;
        }
    }
}

void OrderClass::Membership()
{
    int member = rand() % 3;
    if (member == 0)
    {
        cout << "����� ����� Silver�Դϴ�!" << endl;
        if (money < 10000)
        {
            cout << "�� �ֹ��ݾ��� �ּ� �ݾ׺��� ���� ������ ������ �� �����ϴ�." << endl;
            cout << "�� �ֹ� �ݾ�: " << money << "��" << "�����Ǿ����ϴ�." << endl;
            cout << "�����մϴ�." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
        else
        {
            cout << "�� �ֹ� �ݾ�: " << money*0.95 << "��" << "�����Ǿ����ϴ�." << endl;
            cout << "�����մϴ�." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
    }
    else if (member == 1)
    {
        cout << "����� ����� Gold�Դϴ�!" << endl;
        if (money < 20000)
        {
            cout << "�� �ֹ��ݾ��� �ּ� �ݾ׺��� ���� ������ ������ �� �����ϴ�." << endl;
            cout << "�� �ֹ� �ݾ�: " << money << "��" << "�����Ǿ����ϴ�." << endl;
            cout << "�����մϴ�." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
        else
        {
            cout << "�� �ֹ� �ݾ�: " << money * 0.85 << "��" << "�����Ǿ����ϴ�." << endl;
            cout << "�����մϴ�." << endl;
            cout << endl;
            ordermenu.clear();
            total.clear();
        }
    }
    else
    {
        cout << "����� ����� Vip�Դϴ�!" << endl;
        cout << "�� �ֹ� �ݾ�: " << money * 0.85 << "��" << "�����Ǿ����ϴ�." << endl;
        cout << "�����մϴ�." << endl;
        cout << endl;
        ordermenu.clear();
        total.clear();
    }
}

void OrderClass::Account()
{
    int total = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;
    cout << "----------------ī�װ� �� ����----------------" << endl;
    cout << "  Ŀ�Ǹ޴�                              " << sum1 << "��" << endl;
    cout << "  �ݵ���޴�                          " << sum2 << "��" << endl;
    cout << "  ����Ǫġ��޴�                        " << sum3 << "��" << endl;
    cout << "  �����޴�                          " << sum4 << "��" << endl;
    cout << "  �������޴�                            " << sum5 << "��" << endl;
    cout << "  Ƽ�޴�                                " << sum6 << "��" << endl;
    cout << "------------------------------------------------" << endl;
    cout << " �� ���� ����                           "<< total << "��" << endl;
    cout << endl;
}