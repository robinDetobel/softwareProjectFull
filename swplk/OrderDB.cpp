#include "OrderDB.h"



void OrderDB::addOrder(int customer_id, double width, double length, string datum, bool priority)
{
	try {
		mysqlx::Table tab = xd.getTable("testing_car");
		tab.insert("customer_id", "length", "width", "datum", "priority").values(customer_id, length, width, datum, priority).execute();
		cout << "    Order van " << customer_id << " succesvol toegevoegd." << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void OrderDB::removeOrder(int id)
{
	try {
		std::string temp = string_order_temp(id);
		tab.remove().where("id= :param").bind("param", id).execute();
		cout << endl;
		std::cout << "    " << temp << " werd succesvol verwijdert." << endl << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void OrderDB::changePriorityTrue(int id)
{
	try {
		tab.update().set("priority", 1).where("orderID= :param").bind("param", id).execute();
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void OrderDB::changePriorityFalse(int id)
{
	try {
		tab.update().set("priority", 0).where("name= :param").bind("param", id).execute();
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

string OrderDB::string_order_temp(int id)
{
	try {
		mysqlx::RowResult myResult = tab.select("*").where("id= :param").bind("param", id).execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			return row[1];
		}
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}


OrderDB::OrderDB()
{
}


OrderDB::~OrderDB()
{
}
