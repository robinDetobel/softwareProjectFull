#pragma once
#include <string>
#include <iostream>
using namespace std;

class Customer {
private:
	int customerID;
	string name;
	string billingAddress;
	string email;
	string phoneNumber;

public:
	Customer();
	Customer(int, string, string, string, string);
	Customer(string, string, string, string);
	void setCustomerID(int);
	void setName(string);
	void setBillingAddress(string);
	void setEmail(string);
	void setPhoneNumber(string);
	void setId(int);

	Customer make_and_return_customer();
	static void print_info_customer(Customer);

	int getCustomerID();
	std::string getName();
	std::string getBillingAddress();
	std::string getEmail();
	std::string getPhoneNumber();
};

