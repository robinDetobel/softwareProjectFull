#include "Truck.h"



Truck::Truck()
{
}


Truck::~Truck()
{
}

Truck::Truck(int id, std::string name, double length, double width)
{
	this->id = id;
	this->name = name;
	this->length = length;
	this->width = width;
}

int Truck::get_id()
{
	return id;
}

std::string Truck::get_name()
{
	return name;
}

double Truck::get_length()
{
	return length;
}

double Truck::get_width()
{
	return width;
}
