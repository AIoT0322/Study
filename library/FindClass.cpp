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
        cout << "이름: ";
        cin >> name;
        cout << "연락처: ";
        cin >> phone;
        string FindQuery = "SELECT id FROM user WHERE name='" + name + "' AND phone='" + phone + "'";

        if (mysql_query(&mysql, FindQuery.c_str()))
        {
            cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
            continue;
        }

        result = mysql_store_result(&mysql);
        int num_rows = mysql_num_rows(result); // 결과셋에 포함된 행의 수 가져오기

        if (num_rows == 0)
        {
            cout << "일치하는 ID가 없습니다." << endl;
            break;
        }
        else
        {
            while ((row = mysql_fetch_row(result)))
            {
                string retrievedId = row[0]; 
                cout << "검색된 ID: " << retrievedId << endl;
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
        cout << "이름: ";
        cin >> name;

        string FindQuery = "SELECT pw FROM user WHERE id='" + id + "' AND name='" + name + "'";

        if (mysql_query(&mysql, FindQuery.c_str()))
        {
            cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
            continue;
        }

        result = mysql_store_result(&mysql);
        int num_rows = mysql_num_rows(result); // 결과셋에 포함된 행의 수 가져오기

        if (num_rows == 0)
        {
            cout << "존재하지 않는 ID입니다." << endl;
            break;
        }
        else
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result)))
            {
                string retrievedpw = row[0];
                cout << "검색된 PW: " << retrievedpw << endl;
            }
            break;
        }
        mysql_free_result(result);
    }
}
