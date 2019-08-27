#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Truck
{
private:
	int id;
	std::string name;
	double length;
	double width; 
public:
	Truck();
	~Truck();
	Truck(int, std::string, double, double);
	int get_id();
	std::string get_name();
	double get_length();
	double get_width();
};

