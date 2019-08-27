#include "Customer.h"

Customer::Customer() {
}

Customer::Customer(int id, string name, string billing_address, string email, string phonenumber) {
	setCustomerID(id);
	setName(name);
	setBillingAddress(billing_address);
	setEmail(email);
	setPhoneNumber(phonenumber);
}

Customer::Customer(string name, string billing_address, string email, string phonenumber) {
	setName(name);
	setBillingAddress(billing_address);
	setEmail(email);
	setPhoneNumber(phonenumber);
}

void Customer::setCustomerID(int value) {
	customerID = value;
}

void Customer::setName(string value) {
	name = value;
}

void Customer::setBillingAddress(string value) {
	billingAddress = value;
}

void Customer::setEmail(string value) {
	email = value;
}

void Customer::setPhoneNumber(string value) {
	phoneNumber = value;
}

void Customer::setId(int value) {
	this->customerID = value;
}


Customer Customer::make_and_return_customer() {
	cout << "    Nieuwe klant aanmaken: " << endl;
	std::cout << "    Geef de naam vd klant in: ";
	std::string naam;
	getline(cin, naam);
	std::cout << "    Geef de leeftijd vd klant in: ";
	std::cout << "    Geef de billingAddress vd klant in: ";
	std::string billingAddress;
	getline(cin, billingAddress);
	std::cout << "    Geef de email vd klant in: ";
	std::string email;
	getline(cin, email);
	std::cout << "    Geef de phonenumber vd klant in: ";
	std::string phoneNumber;
	getline(cin, phoneNumber);
	return Customer(naam, billingAddress, email, phoneNumber);
}

void Customer::print_info_customer(Customer customer) {
	cout << "    Customer id: " << customer.getCustomerID() << endl;
	cout << "    Naam: " << customer.getName() << endl;
	cout << "    Leveradress : " << customer.getBillingAddress() << endl;
	cout << "    Email: " << customer.getEmail() << endl;
	cout << "    Phone number: " << customer.getPhoneNumber() << endl << endl;
}

int Customer::getCustomerID() {
	return customerID;
}

std::string Customer::getName() {
	return name;
}

std::string Customer::getBillingAddress() {
	return billingAddress;
}

std::string Customer::getEmail() {
	return email;
}

std::string Customer::getPhoneNumber() {
	return phoneNumber;
}
