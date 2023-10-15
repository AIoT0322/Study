#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <mysql.h>
#include "JoinClass.h"
#include "LoginClass.h"
#include "FindClass.h"
#include "RecommendClass.h"
#include "SearchClass.h"
#include "RentClass.h"
#include "DonateClass.h"
#include "ReturnClass.h"
#include "MyinfoClass.h"
#pragma comment(lib, "libmySQL.lib")

using namespace std;

int main()
{
    int choice;
    int choice1;
    LoginClass login;

    while (1)
    {
        cout << "1. 회원가입  2. 로그인 3. ID/PW 찾기" << endl;
        cin >> choice;

        if (choice == 1)
        {
            JoinClass join;
            join.Input();
            continue;
        }
        else if (choice == 2)
        {
            login.login();
            break;
        }
        else if (choice == 3)
        {
            int IDorPW;
            FindClass find;
            cout << "----- ID/PW 찾기 -----" << endl;
            cout << "1. ID 찾기 2. PW 찾기" << endl;
            cin >> IDorPW;
            if (IDorPW == 1)
            {
                find.FindID();
                continue;
            }
            else
            {
                find.FindPW();
                continue;
            }
        }
        else
        {
            cout << "잘못된 번호입니다." << endl;
            continue;
        }
    }
    Sleep(500);
    system("cls");
    RecommendClass recommend;
    SearchClass search;
    string id = login.id;
    cout << "----- 추천도서 -----" << endl;
    recommend.Recommend();

    while (1)
    {
        cout << "1. 조회 2. 대여 3. 반납 4. 기증 5. 나의 정보 6. 종료" << endl;
        cin >> choice1;

        if (choice1 == 1)
        {
            search.Search();
            continue;
        }
        else if (choice1 == 2)
        {
            RentClass rent;
            vector <string>cart = search.cart;
            rent.Rentable(id);
            rent.Rent(id, cart);
            continue;
        }
        else if (choice1 == 3)
        {
            ReturnClass rebook;
            rebook.Return(id);
            continue;
        }
        else if (choice1 == 4)
        {
            DonateClass donate;
            donate.Donation();
            continue;
        }
        else if (choice1 == 5)
        {
            Sleep(500);
            system("cls");
            cout << "----- 나의 정보 -----" << endl;
            MyinfoClass info;
            info.Info(id);
        }
        else if (choice1 == 6)
        {
            cout << "종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 번호입니다." << endl;
            continue;
        }
    }
    return 0;
}