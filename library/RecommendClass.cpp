#include "RecommendClass.h"
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

RecommendClass::RecommendClass()
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
        cout << "Connection error: " << mysql_error(&mysql) << endl;

    mysql_query(&mysql, "set names euckr;");
    result = nullptr;
}

RecommendClass::~RecommendClass()
{
    if (result != nullptr)
    {
        mysql_free_result(result);
    }
}

void RecommendClass::Recommend()
{
    if (mysql_query(&mysql, "SELECT title, writer FROM book ORDER BY RAND() LIMIT 3")) 
    {
        cerr << "쿼리 실행 실패: " << mysql_error(&mysql) << endl;
    }
    else
    {
        result = mysql_store_result(&mysql);

        if (result == NULL)
        {
            cerr << "결과셋 가져오기 실패: " << mysql_error(&mysql) << endl;
        }

        row_count = mysql_num_rows(result);
        if (row_count == 0) 
        {
            cerr << "출력 오류" << endl;
        }
        else 
        {
            while (row = mysql_fetch_row(result)) 
            {
                for (int i = 0; i < mysql_num_fields(result); i++) 
                {
                    cout << row[i] << " ";
                }
                cout << endl;
            }
        }
    }
    mysql_free_result(result);
}