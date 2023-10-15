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
    cout << "----- 회원가입-----" << endl;
    while (1)
    {
        cout << "ID: ";
        cin >> id;
        string idcheck = "SELECT id FROM user WHERE id='" + id + "'";

        if (mysql_query(&mysql, idcheck.c_str()))
        {
            cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
        }
        else
        {
            result = mysql_store_result(&mysql);
            int num_rows = mysql_num_rows(result); // 결과셋에 포함된 행의 수 가져오기

            if (num_rows == 0)
            {
                cout << "사용 가능한 ID입니다." << endl;
                break;
            }
            else
            {
                cout << "중복된 ID입니다." << endl;
                continue;
            }
        }
        mysql_free_result(result);
    }
    cout << "PW: ";
    cin >> pw;
    cout << "이름: ";
    cin >> name;
    cout << "연락처: ";
    cin >> phone;

    string insertQuery = "INSERT INTO user (id, pw, name, phone) VALUES ('" + id + "', '" + pw + "', '" + name + "', '" + phone + "')";

    if (mysql_query(&mysql, insertQuery.c_str())) 
    {
        cerr << "데이터 입력에 실패했습니다: " << mysql_error(&mysql) << endl;
    }
    else 
    {
        cout << "회원가입이 완료되었습니다." << endl;
    }
}