#pragma once
#include <string>
#include <mysql.h>
#include <vector>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class SearchClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	string title;
	string writer;
	int choice;
	int num_rows;
	int pluscart;

public:
	SearchClass();
	~SearchClass();
	void Search();
	vector<string> cart;
};

