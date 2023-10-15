#pragma once
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class RecommendClass
{
private:
	MYSQL mysql;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int row_count;

public:
	RecommendClass();
	~RecommendClass();
	void Recommend();
};

