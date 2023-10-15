#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class RentClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	string title;
	int num_rows;
	string date;
	int choice;
	time_t timer;
	struct tm t;
	string Date();

public:
	RentClass();
	~RentClass();
	void Rent(string id, vector<string>cart);
	void Rentable(string id);
};

