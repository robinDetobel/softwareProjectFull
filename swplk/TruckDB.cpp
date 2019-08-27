#include "TruckDB.h"



TruckDB::TruckDB()
{
}


TruckDB::~TruckDB()
{
}

vector<Truck> TruckDB::get_trucks_in_vector()
{
	try {
		vector<Truck> my_trucks;
		Truck* temp_Truck;
		mysqlx::Table tab = xd.getTable("Truck");
		mysqlx::RowResult myResult = tab.select("id", "name", "lengte", "breedte").execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			temp_Truck = new Truck(row[0], row[1], row[2], row[3]);
			my_trucks.push_back(*temp_Truck);
			delete temp_Truck;
		}
		temp_Truck = nullptr;
		return my_trucks;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

Truck TruckDB::get_truck_by_id(int id)
{
	try {
		mysqlx::Table tab = xd.getTable("Truck");
		mysqlx::RowResult myResult = tab.select("id", "name", "lengte", "breedte").where("id= :param").bind("param", id).execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			return Truck(row[0], row[1], row[2], row[3]);
		}
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

Truck TruckDB::get_truck_by_name(std::string name)
{
	try {
		mysqlx::Table tab = xd.getTable("testing_car");
		std::string q = "name LIKE '%";
		q += name;
		q += "%'";
		mysqlx::RowResult myResult = tab.select("id", "name", "price", "stock").where(q).execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			return Truck(row[0], row[1], row[2], row[3]);
		}
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void TruckDB::add_truck(std::string name, double width, double length)
{
	try {
		mysqlx::Table tab = xd.getTable("Truck");
		tab.insert("name", "lengte", "breedte").values(name, length, width).execute();
		cout << "    " << name << " succesvol toegevoegd." << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void TruckDB::show_all_trucks_ids()
{
	try {
		TruckDB db;
		vector<Truck> data = db.get_trucks_in_vector();
		cout << "    alle vrachtwagens:" << endl << endl;
		for (int i = 0; i < data.size(); i++) {
			cout << "    ID: " << data[i].get_id() << " : " << data[i].get_name() << "." << endl;
		}
		cout << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}


std::string TruckDB::string_truck_name(int id)
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


void TruckDB::remove_truck_by_id(int id)
{
	try {
		std::string temp = string_truck_name(id);
		tab.remove().where("id= :param").bind("param", id).execute();
		cout << endl;
		std::cout << "    " << temp << " werd succesvol verwijdert." << endl << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

vector<int> TruckDB::possible_choices()
{
	try {
		vector<int> possible_choices;
		mysqlx::RowResult myResult = tab.select("id").execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			possible_choices.push_back(row[0]);
		} return possible_choices;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}
