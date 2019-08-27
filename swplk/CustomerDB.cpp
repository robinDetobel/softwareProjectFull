#include "CustomerDB.h"
#include <iostream>
using namespace std;

CustomerDB::CustomerDB() {
}

void CustomerDB::add_customer(std::string name, std::string address, std::string email, std::string phone_number) {
	try {
		mysqlx::Table my_table = xd.getTable("testing_customer");
		my_table.insert("name", "billingAddress", "email", "phoneNumber").values(name, address, email, phone_number).execute();
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void CustomerDB::add_customer(Customer* customer) {
	try {
		my_table.insert("name", "billingAddress", "email", "phoneNumber").values(customer->getName(), customer->getBillingAddress(), customer->getEmail(), customer->getPhoneNumber()).execute();
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void CustomerDB::show_customer(int id) {
	try {
		mysqlx::RowResult myResult = my_table.select("*").where("id = :param").bind("param", id).execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			cout << "    ID " << row[0] << " behoort tot " << row[1] << " woonachtend te " << row[2] << " met email: " << row[3] << " en gsm nummer: " << row[4] << "." << endl;
		}
		cout << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void CustomerDB::update_customer(string name) {
	try {
		cout << "    Welke veld wil je wijzigen?    " << endl << endl;
		cout << "    1. Naam" << endl;
		cout << "    2. Billing_address" << endl;
		cout << "    3. Email" << endl;
		cout << "    4. Phone_number" << endl << endl;
		cout << "    Type je keuze in: ";
		int keuze;
		cin >> keuze;
		cin.ignore();
		cout << endl;
		string data;
		if (keuze > 0 && keuze < 5) {

			switch (keuze) {
			case 1: {
				cout << "    Geef een nieuwe naam in: ";
				getline(cin, data);
				my_table.update().set("name", data).where("name = :param").bind("param", name).execute();
			} break;
			case 2: {
				cout << "    Geef een nieuwe address in: ";
				getline(cin, data);
				my_table.update().set("billingAddress", data).where("name = :param").bind("param", name).execute();
			} break;
			case 3: {
				cout << "    Geef een nieuwe email in: ";
				getline(cin, data);
				my_table.update().set("email", data).where("name = :param").bind("param", name).execute();
			} break;
			case 4: {
				cout << "    Geef een nieuwe phone_number in: ";
				getline(cin, data);
				my_table.update().set("phoneNumber", data).where("name = :param").bind("param", name).execute();
			} break;

			default: std::cout << "    De user " << name << " werd succesvol bijgewerkt." << endl;
			}
		}
		else cout << "    Dat veld bestaat niet." << endl << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void CustomerDB::remove_customer(std::string name) {
	try {
		my_table.remove().where("name = :param").bind("param", name).execute();
		std::cout << "    De user " << name << " werd succesvol verwijdert." << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

void CustomerDB::show_all_customers() {
	try {

		mysqlx::RowResult myResult = my_table.select("id", "name", "billingAddress", "email", "phoneNumber").execute();
		for (mysqlx::Row row : myResult.fetchAll())
		{
			cout << "    " << row[1] << " woont in " << row[2] << " met email: " << row[3] << " en gsm nummer: " << row[4] << "." << endl;
		}
		cout << endl;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

vector<Customer> CustomerDB::get_customers() {
	try {
		vector<Customer> my_customers;
		Customer* temp_customer;
		mysqlx::RowResult myResult = my_table.select("id", "name", "billingAddress", "email", "phoneNumber").execute();
		for (mysqlx::Row row : myResult.fetchAll())
		{
			temp_customer = new Customer(row[0], row[1], row[2], row[3], row[4]);
			my_customers.push_back(*temp_customer);
			delete temp_customer;
		}
		temp_customer = nullptr;
		return my_customers;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

Customer CustomerDB::get_customer(std::string naam) {
	try {
		mysqlx::RowResult myResult = my_table.select("id", "name", "billingAddress", "email", "phoneNumber").where("name = :param").bind("param", naam).execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			return Customer(row[0], row[1], row[2], row[3], row[4]);
		}
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

Customer CustomerDB::get_customer_on_id(int id) {
	try {
		mysqlx::RowResult myResult = my_table.select("id", "name", "billingAddress", "email", "phoneNumber").where("id = :param").bind("param", id).execute();
		for (mysqlx::Row row : myResult.fetchAll()) {
			return Customer(row[0], row[1], row[2], row[3], row[4]);
		}
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}

bool CustomerDB::klant_bestaat(std::string name) {
	try {
		mysqlx::RowResult myResult = my_table.select("name").where("name= :param").bind("param", name).execute();
		if (myResult.fetchOne()) {
			return true;
		}
		else return false;
	}
	catch (mysqlx::Error e) {
		std::cout << "    " << e.what() << std::endl;
	}
}
