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
	cout << "1. �뿩 ���� ����" << endl;
	cout << "2. �ݳ��� ����" << endl;
	cout << "3. �� ���� ����" << endl;
	cout << "4. ��ü ���� ��ȸ" << endl;
	cin >> choice;

	while (1)
	{
		if (choice == 1)
		{
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
			mysql_free_result(result);
			break;
		}
		else if (choice == 2)
		{
			string listQuery = "SELECT title, writer, date FROM returnlist WHERE id='" + id + "'";

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
					cout << "�ݳ��� ������ �����ϴ�." << endl;
					break;
				}
				else
				{
					cout << "----- �ݳ� ����Ʈ -----" << endl;
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
			cout << "1. ��й�ȣ ���� 2. ����ó ����" << endl;
			cin >> choice1;
			while (1)
			{
				if (choice1 == 1)
				{
					cout << "�ٲ� ��й�ȣ�� �Է��ϼ���." << endl;
					cin >> pw;
					
					string pwQuery = "UPDATE user SET pw='" + pw + "' WHERE id='" + id + "'";
					
					if (mysql_query(&mysql, pwQuery.c_str()))
					{
						cerr << "������ ���� ����: " << mysql_error(&mysql) << endl;
						break;
					}
					else
					{
						cout << "��й�ȣ ���� �Ϸ�" << endl;
						break;
					}
				}
				else if (choice1 == 2)
				{
					cout << "�ٲ� ����ó�� �Է��ϼ���." << endl;
					cin >> phone;

					string phoneQuery = "UPDATE user SET phone='" + phone + "' WHERE id='" + id + "'";
					
					if (mysql_query(&mysql, phoneQuery.c_str()))
					{
						cerr << "������ ���� ����: " << mysql_error(&mysql) << endl;
						break;
					}
					else
					{
						cout << "����ó ���� �Ϸ�" << endl;
						break;
					}
				}
				else
				{
					cout << "�߸��� ��ȣ�Դϴ�." << endl;
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
				cerr << "������ ��ȸ ����: " << mysql_error(&mysql) << endl;
				break;
			}
			else
			{
				result = mysql_store_result(&mysql);
				num_rows = mysql_num_rows(result);

				if (num_rows == 0)
				{
					cout << "��ü�� ������ �����ϴ�." << endl;
					break;
				}
				else
				{
					cout << "----- ��ü ����Ʈ -----" << endl;
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
			cout << "�߸��� ��ȣ�Դϴ�." << endl;
			continue;
		}
	}
	mysql_close(&mysql);
}
