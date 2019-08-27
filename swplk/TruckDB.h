#pragma once
#include "BaseDB.h"
#include "Truck.h"
class TruckDB
{
	private:
		const std::string x = "1819WEBADV050";
		mysqlx::Session ses = BaseDB::connect_to_session();
		mysqlx::Schema xd = ses.getSchema(x);
		mysqlx::Table tab = xd.getTable("Truck");
public:
	TruckDB();
	~TruckDB();
	vector <Truck> get_trucks_in_vector();
	Truck get_truck_by_id(int);
	Truck get_truck_by_name(std::string);
	void add_truck(std::string, double, double);
	void show_all_trucks_ids();
	std::string string_truck_name(int);
	void remove_truck_by_id(int);
	vector<int> possible_choices();
};

