#include "MyinfoClass.h"
#include <iostream>
#include <string>
#include <vector>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

MyinfoClass::MyinfoClass()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
		cout << "Connection error: " << mysql_error(&mysql) << endl;

	mysql_query(&mysql, "set names euckr;");
	result = nullptr;
}

MyinfoClass::~MyinfoClass()
{
	if (result != nullptr)
	{
		mysql_free_result(result);
	}
}

void MyinfoClass::Info(string id)
{
	cout << "1. 대여 중인 도서" << endl;
	cout << "2. 반납한 도서" << endl;
	cout << "3. 내 정보 변경" << endl;
	cout << "4. 연체 정보 조회" << endl;
	cin >> choice;

	while (1)
	{
		if (choice == 1)
		{
			string listQuery = "SELECT title, writer, date FROM rentlist WHERE id='" + id + "'";

			if (mysql_query(&mysql, listQuery.c_str()))
			{
				cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
				break;
			}
			else
			{
				result = mysql_store_result(&mysql);
				num_rows = mysql_num_rows(result);

				if (num_rows == 0)
				{
					cout << "대여 중인 도서가 없습니다." << endl;
					break;
				}
				else
				{
					cout << "----- 대여 리스트 -----" << endl;
					while (row = mysql_fetch_row(result))
					{
						for (int i = 0; i < mysql_num_fields(result); i++)
						{
							cout << row[i] << " ";
						}
					}
					cout << endl;
				}
			}
			mysql_free_result(result);
			break;
		}
		else if (choice == 2)
		{
			string listQuery = "SELECT title, writer, date FROM returnlist WHERE id='" + id + "'";

			if (mysql_query(&mysql, listQuery.c_str()))
			{
				cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
				break;
			}
			else
			{
				result = mysql_store_result(&mysql);
				num_rows = mysql_num_rows(result);

				if (num_rows == 0)
				{
					cout << "반납한 도서가 없습니다." << endl;
					break;
				}
				else
				{
					cout << "----- 반납 리스트 -----" << endl;
					while (row = mysql_fetch_row(result))
					{
						for (int i = 0; i < mysql_num_fields(result); i++)
						{
							cout << row[i] << " ";
						}
					}
					cout << endl;
				}
			}
			mysql_free_result(result);
			break;
		}
		else if (choice == 3)
		{
			cout << "1. 비밀번호 변경 2. 연락처 변경" << endl;
			cin >> choice1;
			while (1)
			{
				if (choice1 == 1)
				{
					cout << "바꿀 비밀번호를 입력하세요." << endl;
					cin >> pw;
					
					string pwQuery = "UPDATE user SET pw='" + pw + "' WHERE id='" + id + "'";
					
					if (mysql_query(&mysql, pwQuery.c_str()))
					{
						cerr << "데이터 변경 실패: " << mysql_error(&mysql) << endl;
						break;
					}
					else
					{
						cout << "비밀번호 변경 완료" << endl;
						break;
					}
				}
				else if (choice1 == 2)
				{
					cout << "바꿀 연락처를 입력하세요." << endl;
					cin >> phone;

					string phoneQuery = "UPDATE user SET phone='" + phone + "' WHERE id='" + id + "'";
					
					if (mysql_query(&mysql, phoneQuery.c_str()))
					{
						cerr << "데이터 변경 실패: " << mysql_error(&mysql) << endl;
						break;
					}
					else
					{
						cout << "연락처 변경 완료" << endl;
						break;
					}
				}
				else
				{
					cout << "잘못된 번호입니다." << endl;
					continue;
				}
			}
			break;
		}
		else if (choice == 4)
		{
			string listQuery = "SELECT title, writer, rentdate, returndate FROM overduelist WHERE id='" + id + "'";

			if (mysql_query(&mysql, listQuery.c_str()))
			{
				cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
				break;
			}
			else
			{
				result = mysql_store_result(&mysql);
				num_rows = mysql_num_rows(result);

				if (num_rows == 0)
				{
					cout << "연체한 도서가 없습니다." << endl;
					break;
				}
				else
				{
					cout << "----- 연체 리스트 -----" << endl;
					while (row = mysql_fetch_row(result))
					{
						for (int i = 0; i < mysql_num_fields(result); i++)
						{
							cout << row[i] << " ";
						}
					}
					cout << endl;
				}
			}
			mysql_free_result(result);
			break;
		}
		else
		{
			cout << "잘못된 번호입니다." << endl;
			continue;
		}
	}
	mysql_close(&mysql);
}
