#include "Order.h"



Order::Order()
{
}


Order::~Order()
{
}

Order::Order(int customer_id, double length, double width, string datum, bool priority)
{
	this->customer_id = customer_id;
	this->length = length;
	this->width = width;
	this->datum = datum;
	this->priority = priority;
}

Order::Order(int id, int customer_id, double length, double width, string datum, bool priority)
{
	this->id = id;
	this->customer_id = customer_id;
	this->length = length;
	this->width = width;
	this->datum = datum;
	this->priority = priority;
}
