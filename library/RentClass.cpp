#include "RentClass.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

RentClass::RentClass()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
		cout << "Connection error: " << mysql_error(&mysql) << endl;

	mysql_query(&mysql, "set names euckr;");
	result = nullptr;
}

RentClass::~RentClass()
{
	if (result != nullptr)
	{
		mysql_free_result(result);
	}
}

string RentClass::Date()
{
	timer = time(NULL);

	if (localtime_s(&t, &timer) == 0)
	{
		int year = t.tm_year + 1900;
		int month = t.tm_mon + 1;
		int day = t.tm_mday;
		date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
	}
	else
	{
		cout << "날짜를 불러오지 못했습니다." << endl;
	}

	return date;
}

void RentClass::Rentable(string id)
{
	string Query = "SELECT title FROM overduelist WHERE id = '" + id + "' AND DATEDIFF(NOW(), returndate) >= 14 ORDER BY num DESC LIMIT 1";

	if (mysql_query(&mysql, Query.c_str()))
	{
		cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
	}
	else
	{
		result = mysql_store_result(&mysql);
		if (result)
		{
			string YQuery = "UPDATE user SET rentable='Y' WHERE id='" + id + "'";
			if (mysql_query(&mysql, YQuery.c_str()))
			{
				cerr << "데이터 업데이트 실패: " << mysql_error(&mysql) << endl;
			}
		}
	}
}

void RentClass::Rent(string id, vector<string>cart)
{
	Date();

	while (1)
	{
		cout << "[" << date << "]" << endl;
		if (cart.empty())
		{
			cout << "장바구니에 담긴 도서가 없습니다." << endl;
			break;
		}
		else
		{
			cout << "----- 장바구니 -----" << endl;
			for (const string& element : cart)
			{
				cout << element << " ";
			}
			cout << endl;
			cout << "장바구니에 담긴 도서를 대여하시겠습니까? 1.YES 2. NO" << endl;
			cin >> choice;

			if (choice == 1)
			{
				string rentableQuery = "SELECT rentable FROM user WHERE id = '" + id + "';";

				if (mysql_query(&mysql, rentableQuery.c_str()))
				{
					cerr << "데이터 조회 실패: " << mysql_error(&mysql) << endl;
				}
				else
				{
					result = mysql_store_result(&mysql);
					if (result)
					{
						row = mysql_fetch_row(result);
						if (row && row[0] && strcmp(row[0], "N") == 0)
						{
							cout << "대여가 불가능합니다." << endl;
							break;
						}
						else
						{
							cout << "대여가 가능합니다." << endl;
						}

						mysql_free_result(result);
					}
				}

				for (int i = 0; i < cart.size(); i += 2)
				{
					string bookTitle = cart[i];
					string bookWriter = cart[i + 1];

					string insertQuery = "INSERT INTO rentlist (id, title, writer, date) VALUES ('" + id + "', '" + bookTitle + "', '" + bookWriter + "', '" + date + "')";

					if (mysql_query(&mysql, insertQuery.c_str()))
					{
						cerr << "데이터 입력에 실패했습니다: " << mysql_error(&mysql) << endl;
					}
					else
					{
						cout << "----- 대여 완료 -----" << endl;
						cout << "대여 기간은 일주일입니다." << endl;
						cout << "연체 시 2주간 대여가 불가하니 주의해주세요." << endl;
						cart.clear();
						break;
					}
				}
				break;
			}
			else if (choice == 2)
			{
				break;
			}
			else
			{
				cout << "잘못된 번호입니다." << endl;
			}
		}
	}
	mysql_close(&mysql);
}