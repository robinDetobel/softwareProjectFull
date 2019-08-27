#pragma once
#include <iostream>
#include "BaseDB.h"
#include "Order.h"
#include <string>
class OrderDB
{
private:
	const std::string x = "1819WEBADV050";
	mysqlx::Session ses = BaseDB::connect_to_session();
	mysqlx::Schema xd = ses.getSchema(x);
	mysqlx::Table tab = xd.getTable("Order");
public:
	void addOrder(int, double, double, string, bool);
	void removeOrder(int);
	void changePriorityTrue(int);
	void changePriorityFalse(int);
	string string_order_temp(int);
	OrderDB();
	~OrderDB();
};

