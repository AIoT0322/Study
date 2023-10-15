#include "LoginClass.h"
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

LoginClass::LoginClass()
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
        cout << "Connection error: " << mysql_error(&mysql) << endl;

    mysql_query(&mysql, "set names euckr;");
    result = nullptr;
}

LoginClass:: ~LoginClass()
{
    if (result != nullptr)
    {
        mysql_free_result(result);
    }
    mysql_close(&mysql);
}

void LoginClass:: login()
{
    cout << "----- �α��� -----" << endl;
    while (1)
    {
        cout << "ID: ";
        cin >> id;
        cout << "PW: ";
        cin >> pw;

        string loginQuery = "SELECT id, pw FROM user WHERE id='" + id + "' AND pw='" + pw + "'";

        if (mysql_query(&mysql, loginQuery.c_str()))
        {
            cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
            continue;
        }

        result = mysql_store_result(&mysql);
        int num_rows = mysql_num_rows(result); // ����¿� ���Ե� ���� �� ��������

        if (num_rows == 0)
        {
            cout << "�������� �ʴ� ID �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
        }
        else
        {
            cout << "�α��εǾ����ϴ�." << endl;
            break;
        }
        mysql_free_result(result);
    }
}