#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class LoginClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	string pw;

public:
	LoginClass();
	~LoginClass();
	void login();
	string id;
};

