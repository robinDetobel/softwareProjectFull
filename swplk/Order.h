#pragma once
#include <string>
using namespace std;
class Order
{
public:
public:
	int id;
	int customer_id;
	double length;
	double width;
	string datum;
	bool priority;

public:
	Order();
	~Order();
	Order( int,double, double ,string , bool);
	Order(int, int, double, double, string, bool);
};

