#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace std;

class DonateClass
{
private:
	MYSQL mysql;
	string title;
	string writer;

public:
	DonateClass();
	~DonateClass();
	void Donation();
};

