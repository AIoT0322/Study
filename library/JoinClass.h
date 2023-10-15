#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class JoinClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	string id;
	string pw;
	string name;
	string phone;

public:
	JoinClass();
	~JoinClass();
	void Input();
};