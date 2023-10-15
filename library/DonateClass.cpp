#include "DonateClass.h"
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

DonateClass::DonateClass()
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
        cout << "Connection error: " << mysql_error(&mysql) << endl;

    mysql_query(&mysql, "set names euckr;");
}

DonateClass::~DonateClass()
{
    mysql_close(&mysql);
}

void DonateClass::Donation()
{
    cout << "도서명 입력하세요." << endl;
    cin >> title;
    cin.ignore();
    cout << "저자를 입력하세요." << endl;
    cin >> writer;
    cin.ignore();
  
    string AddQuery = "INSERT INTO book (title, writer) VALUES ('" + title + "', '" + writer + "')";
   
    if (mysql_query(&mysql, AddQuery.c_str()))
    {
        cerr << "기증 정보 입력에 실패했습니다: " << mysql_error(&mysql) << endl;
    }
    else
    {
        cout << "기증해주셔서 감사합니다." << endl;
    }
}