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
    cout << "������ �Է��ϼ���." << endl;
    cin >> title;
    cin.ignore();
    cout << "���ڸ� �Է��ϼ���." << endl;
    cin >> writer;
    cin.ignore();
  
    string AddQuery = "INSERT INTO book (title, writer) VALUES ('" + title + "', '" + writer + "')";
   
    if (mysql_query(&mysql, AddQuery.c_str()))
    {
        cerr << "���� ���� �Է¿� �����߽��ϴ�: " << mysql_error(&mysql) << endl;
    }
    else
    {
        cout << "�������ּż� �����մϴ�." << endl;
    }
}