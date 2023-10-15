#include "ReturnClass.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

ReturnClass::ReturnClass()
{
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "1234", "userdata", 3306, NULL, 0))
		cout << "Connection error: " << mysql_error(&mysql) << endl;

	mysql_query(&mysql, "set names euckr;");
	result = nullptr;
}

ReturnClass::~ReturnClass()
{
	if (result != nullptr)
	{
		mysql_free_result(result);
	}
}

string ReturnClass::Date()
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

void ReturnClass::Return(string id)
{
	while (1)
	{
		Date();
		cout << "[" << date << "]" << endl;

		string listQuery = "SELECT title, writer, date FROM rentlist WHERE id='" + id + "'";

		if (mysql_query(&mysql, listQuery.c_str()))
		{
			cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
			break;
		}
		else
		{
			result = mysql_store_result(&mysql);
			num_rows = mysql_num_rows(result);

			if (num_rows == 0)
			{
				cout << "�뿩 ���� ������ �����ϴ�." << endl;
				break;
			}
			else
			{
				cout << "----- �뿩 ����Ʈ -----" << endl;
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
		cout << "�ݳ��� ���������� �Է����ּ���." << endl;   
		cin >> title;
		string AddQuery = "INSERT INTO returnlist (id, title, writer) SELECT id, title, writer FROM rentlist WHERE title='" + title + "'";
		
		if (mysql_query(&mysql, AddQuery.c_str()))
		{
			cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
			break;
		}
		else
		{
			cout << "�ݳ�����Ʈ ����Ϸ�" << endl;
		}

		string dateQuery = "UPDATE returnlist SET date = '" + date + "' WHERE title = '" + title + "'";
		
		if (mysql_query(&mysql, dateQuery.c_str()))
		{
			cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
			break;
		}
		else
		{
			cout << "�ݳ�����Ʈ ��¥ ����Ϸ�" << endl;
		}

		string overdueQuery = "SELECT r.id, r.title, r.writer, r.date AS rent_date, rr.date AS return_date "
			"FROM rentlist AS r "
			"INNER JOIN returnlist AS rr ON r.id = rr.id AND r.title = rr.title "
			"WHERE DATEDIFF(rr.date, r.date) >= 8;";

		if (mysql_query(&mysql, overdueQuery.c_str()))
		{
			cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
			break;
		}

		result = mysql_store_result(&mysql);
		num_rows = mysql_num_rows(result);

		if (!result)
		{
			cerr << "����� ���� ����: " << mysql_error(&mysql) << endl;
			break;
		}

		if (num_rows)
		{
			string NQuery = "UPDATE user SET rentable='N' WHERE id='" + id + "'";

			if (mysql_query(&mysql, NQuery.c_str()))
			{
				cerr << "������ ���� ����: " << mysql_error(&mysql) << endl;
			}
			else
			{
				cout << "�뿩�� 2�ְ� �����˴ϴ�." << endl;
			}
		}

		while (row = mysql_fetch_row(result))
		{
			string id = row[0];
			string title = row[1];
			string writer = row[2];
			string rent_date = row[3];
			string return_date = row[4];

			string insertQuery = "INSERT INTO overduelist (id, title, writer, rentdate, returndate) "
				"VALUES ('" + id + "', '" + title + "', '" + writer + "', '" + rent_date + "', '" + return_date + "');";

			if (mysql_query(&mysql, insertQuery.c_str()))
			{
				cerr << "������ ���� ����: " << mysql_error(&mysql) << endl;
			}
		}

		string deleteQuery = "DELETE FROM rentlist WHERE title='" + title + "'";

		if (mysql_query(&mysql, deleteQuery.c_str()))
		{
			cerr << "������ ���� ����: " << mysql_error(&mysql) << endl;
			break;
		}
		else
		{
			cout << "�ݳ��� �Ϸ�Ǿ����ϴ�." << endl;
			break;
		}
	}
	mysql_close(&mysql);
}