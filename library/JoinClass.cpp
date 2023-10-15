#include "JoinClass.h"
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

JoinClass::JoinClass()
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
        cout << "Connection error: " << mysql_error(&mysql) << endl;

    mysql_query(&mysql, "set names euckr;");
    result = nullptr;
}

JoinClass::~JoinClass()
{
    if (result != nullptr) 
    {
        mysql_free_result(result); 
    }
    mysql_close(&mysql);
}

void JoinClass::Input()
{
    cout << "----- ȸ������-----" << endl;
    while (1)
    {
        cout << "ID: ";
        cin >> id;
        string idcheck = "SELECT id FROM user WHERE id='" + id + "'";

        if (mysql_query(&mysql, idcheck.c_str()))
        {
            cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
        }
        else
        {
            result = mysql_store_result(&mysql);
            int num_rows = mysql_num_rows(result); // ����¿� ���Ե� ���� �� ��������

            if (num_rows == 0)
            {
                cout << "��� ������ ID�Դϴ�." << endl;
                break;
            }
            else
            {
                cout << "�ߺ��� ID�Դϴ�." << endl;
                continue;
            }
        }
        mysql_free_result(result);
    }
    cout << "PW: ";
    cin >> pw;
    cout << "�̸�: ";
    cin >> name;
    cout << "����ó: ";
    cin >> phone;

    string insertQuery = "INSERT INTO user (id, pw, name, phone) VALUES ('" + id + "', '" + pw + "', '" + name + "', '" + phone + "')";

    if (mysql_query(&mysql, insertQuery.c_str())) 
    {
        cerr << "������ �Է¿� �����߽��ϴ�: " << mysql_error(&mysql) << endl;
    }
    else 
    {
        cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
    }
}