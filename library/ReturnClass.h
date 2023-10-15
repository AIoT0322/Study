#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class ReturnClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num_rows;
	string title;
	string Date();
	string date;
	time_t timer;
	struct tm t;

public:
	ReturnClass();
	~ReturnClass();
	void Return(string id);
};

