#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class MyinfoClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num_rows;
	int choice;
	int choice1;
	string pw;
	string phone;

public:
	MyinfoClass();
	~MyinfoClass();
	void Info(string id);
};

