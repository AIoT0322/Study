#pragma once
#include <list>
#include <string>
using namespace std;

class OrderClass
{
public:
	OrderClass();
	void Choice(int menunum, int sizenum);
	void Coffee();
	void Coldbrew();
	void Frappuccino();
	void Blended();
	void Fizzio();
	void Tea();
	void Calculate();
	void Account();
	void Membership();

private:
	int menu;
	int size;
	int num;
	int money;
	int sum1;
	int sum2;
	int sum3;
	int sum4;
	int sum5;
	int sum6;
	list<int> total;
	list<int> menunum;
	list<string> ordermenu;
};

