#include "FindClass.h"
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

FindClass::FindClass()
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
        cout << "Connection error: " << mysql_error(&mysql) << endl;

    mysql_query(&mysql, "set names euckr;");
    result = nullptr;
}

FindClass::~FindClass()
{
    if (result != nullptr)
    {
        mysql_free_result(result);
    }
    mysql_close(&mysql);
}

void FindClass::FindID()
{
    while (1)
    {
        cout << "�̸�: ";
        cin >> name;
        cout << "����ó: ";
        cin >> phone;
        string FindQuery = "SELECT id FROM user WHERE name='" + name + "' AND phone='" + phone + "'";

        if (mysql_query(&mysql, FindQuery.c_str()))
        {
            cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
            continue;
        }

        result = mysql_store_result(&mysql);
        int num_rows = mysql_num_rows(result); // ����¿� ���Ե� ���� �� ��������

        if (num_rows == 0)
        {
            cout << "��ġ�ϴ� ID�� �����ϴ�." << endl;
            break;
        }
        else
        {
            while ((row = mysql_fetch_row(result)))
            {
                string retrievedId = row[0]; 
                cout << "�˻��� ID: " << retrievedId << endl;
            }
            break;
        }
        mysql_free_result(result);
    }
}

void FindClass::FindPW()
{
    while (1)
    {
        cout << "ID: ";
        cin >> id;
        cout << "�̸�: ";
        cin >> name;

        string FindQuery = "SELECT pw FROM user WHERE id='" + id + "' AND name='" + name + "'";

        if (mysql_query(&mysql, FindQuery.c_str()))
        {
            cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
            continue;
        }

        result = mysql_store_result(&mysql);
        int num_rows = mysql_num_rows(result); // ����¿� ���Ե� ���� �� ��������

        if (num_rows == 0)
        {
            cout << "�������� �ʴ� ID�Դϴ�." << endl;
            break;
        }
        else
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result)))
            {
                string retrievedpw = row[0];
                cout << "�˻��� PW: " << retrievedpw << endl;
            }
            break;
        }
        mysql_free_result(result);
    }
}
