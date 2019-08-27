#pragma once
#include "BaseDB.h"
#include "Customer.h"
#include <vector>

class CustomerDB {
private:
	const std::string x = "1819WEBADV050";
	mysqlx::Session ses = BaseDB::connect_to_session();
	mysqlx::Schema xd = ses.getSchema(x);
	mysqlx::Table my_table = xd.getTable("Customer");

public:
	CustomerDB();
	void add_customer(std::string, std::string, std::string, std::string);
	void add_customer(Customer*);
	void show_customer(int);
	void update_customer(std::string);
	void remove_customer(std::string);
	void show_all_customers();
	vector <Customer> get_customers();
	Customer get_customer(std::string);
	Customer get_customer_on_id(int);
	bool klant_bestaat(std::string);
};
