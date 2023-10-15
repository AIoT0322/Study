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
		cout << "��¥�� �ҷ����� ���߽��ϴ�." << endl;
	}

	return date;
}

void RentClass::Rentable(string id)
{
	string Query = "SELECT title FROM overduelist WHERE id = '" + id + "' AND DATEDIFF(NOW(), returndate) >= 14 ORDER BY num DESC LIMIT 1";

	if (mysql_query(&mysql, Query.c_str()))
	{
		cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
	}
	else
	{
		result = mysql_store_result(&mysql);
		if (result)
		{
			string YQuery = "UPDATE user SET rentable='Y' WHERE id='" + id + "'";
			if (mysql_query(&mysql, YQuery.c_str()))
			{
				cerr << "������ ������Ʈ ����: " << mysql_error(&mysql) << endl;
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
			cout << "��ٱ��Ͽ� ��� ������ �����ϴ�." << endl;
			break;
		}
		else
		{
			cout << "----- ��ٱ��� -----" << endl;
			for (const string& element : cart)
			{
				cout << element << " ";
			}
			cout << endl;
			cout << "��ٱ��Ͽ� ��� ������ �뿩�Ͻðڽ��ϱ�? 1.YES 2. NO" << endl;
			cin >> choice;

			if (choice == 1)
			{
				string rentableQuery = "SELECT rentable FROM user WHERE id = '" + id + "';";

				if (mysql_query(&mysql, rentableQuery.c_str()))
				{
					cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
				}
				else
				{
					result = mysql_store_result(&mysql);
					if (result)
					{
						row = mysql_fetch_row(result);
						if (row && row[0] && strcmp(row[0], "N") == 0)
						{
							cout << "�뿩�� �Ұ����մϴ�." << endl;
							break;
						}
						else
						{
							cout << "�뿩�� �����մϴ�." << endl;
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
						cerr << "������ �Է¿� �����߽��ϴ�: " << mysql_error(&mysql) << endl;
					}
					else
					{
						cout << "----- �뿩 �Ϸ� -----" << endl;
						cout << "�뿩 �Ⱓ�� �������Դϴ�." << endl;
						cout << "��ü �� 2�ְ� �뿩�� �Ұ��ϴ� �������ּ���." << endl;
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
				cout << "�߸��� ��ȣ�Դϴ�." << endl;
			}
		}
	}
	mysql_close(&mysql);
}