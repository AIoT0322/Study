#include "SearchClass.h"
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

SearchClass::SearchClass()
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
        cout << "Connection error: " << mysql_error(&mysql) << endl;

    mysql_query(&mysql, "set names euckr;");
    result = nullptr;
}

SearchClass::~SearchClass()
{
    if (result != nullptr)
    {
        mysql_free_result(result);
    }
    mysql_close(&mysql);
}

void SearchClass::Search()
{
	while (1)
	{
		cout << "1. 제목 검색 2. 저자검색" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "제목을 입력하세요." << endl;
			cin >> title;

			string FindQuery = "SELECT title, writer FROM book WHERE title='" + title + "'";

            if (mysql_query(&mysql, FindQuery.c_str()))
            {
                cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
                continue;
            }
            else
            {
                result = mysql_store_result(&mysql);
                num_rows = mysql_num_rows(result);

                if (num_rows == 0)
                {
                    cout << "일치하는 도서가 없습니다." << endl;
                    break;
                }
                else
                {
                    while (row = mysql_fetch_row(result))
                    {
                        for (int i = 0; i < mysql_num_fields(result); i++)
                        {
                            cout << row[i] << " ";
                        }
                        cout << "[1. 담기] [2. X]" << endl;
                        cin >> pluscart;

                        if (pluscart == 1)
                        {
                            if (row)
                            {
                                cart.push_back(row[0]);
                                cart.push_back(row[1]);                             
                                cout << "도서가 장바구니에 담겼습니다." << endl;
                            }
                            else
                            {
                                cout << "담기 실패" << endl;
                            }
                        }
                    }
                    break;
                }
                mysql_free_result(result);
            }   
		}
		else if (choice == 2)
		{
            cout << "저자를 입력하세요." << endl;
            cin >> writer;
            string FindQuery = "SELECT title, writer FROM book WHERE writer='" + writer + "'";
            if (mysql_query(&mysql, FindQuery.c_str()))
            {
                cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
                continue;
            }
            else
            {
                result = mysql_store_result(&mysql);
                num_rows = mysql_num_rows(result);

                if (num_rows == 0)
                {
                    cout << "일치하는 도서가 없습니다." << endl;
                    break;
                }
                else
                {
                    while (row = mysql_fetch_row(result))
                    {
                        for (int i = 0; i < mysql_num_fields(result); i++)
                        {
                            cout << row[i] << " ";
                        }
                        cout << "[1. 담기] [2. X]" << endl;
                        cin >> pluscart;

                        if (pluscart == 1)
                        {
                            if (row)
                            {
                                cart.push_back(row[0]);
                                cart.push_back(row[1]);
                                cout << "도서가 장바구니에 담겼습니다." << endl;
                            }
                            else
                            {
                                cout << "담기 실패" << endl;
                            }
                        }
                    }
                    break;
                }
                mysql_free_result(result);
            }
		}
		else
		{
			cout << "잘못된 번호입니다." << endl;
            continue;
		}
	}
}