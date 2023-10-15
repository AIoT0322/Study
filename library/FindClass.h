#pragma once
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class FindClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	string id;
	string name;
	string phone;

public:
	FindClass();
	~FindClass();
	void FindID();
	void FindPW();
};

