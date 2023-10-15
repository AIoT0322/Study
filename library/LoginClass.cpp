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
    cout << "----- 로그인 -----" << endl;
    while (1)
    {
        cout << "ID: ";
        cin >> id;
        cout << "PW: ";
        cin >> pw;

        string loginQuery = "SELECT id, pw FROM user WHERE id='" + id + "' AND pw='" + pw + "'";

        if (mysql_query(&mysql, loginQuery.c_str()))
        {
            cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
            continue;
        }

        result = mysql_store_result(&mysql);
        int num_rows = mysql_num_rows(result); // 결과셋에 포함된 행의 수 가져오기

        if (num_rows == 0)
        {
            cout << "존재하지 않는 ID 또는 비밀번호가 틀렸습니다." << endl;
        }
        else
        {
            cout << "로그인되었습니다." << endl;
            break;
        }
        mysql_free_result(result);
    }
}