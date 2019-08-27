#include <iostream>
#include <ctime>
#include "CustomerDB.h"
#include "Customer.h"
#include "TruckDB.h"
#include "Truck.h"
#include "OrderDB.h"
#include "Order.h"


using namespace std;

void clrscr() {
	for(int i; i < 20; i++) {
		cout << "\n";
	}
}

void gotoxy(int x, int y) {
	printf("%c[%d;%df", 0x1B, y, x);
}


void intro()
{
		clrscr();
		gotoxy(36, 11);
		cout << "COURIER";
		gotoxy(35, 14);
		cout << "MANAGEMENT";
		gotoxy(36, 17);
		cout << "SYSTEM";
}


int truckMenu() {
	cout << "    JE BENT IN DE AUTO MENU    " << endl << endl;
	int keuze;
	do {
		keuze = truckMenuLoop();
		switch (keuze) {
		case 1: {
			TruckDB db;
			string name;
			double length, width;
			cout << "    Geef de naam van de truck in: ";
			getline(cin, name);
			cout << "    Geef de lengte van de truck in: ";
			cin >> length;
			cin.ignore();
			cout << "    Geef de breedte van de truck in: ";
			cin >> width;
			cin.ignore();
			db.add_truck(name, length, width);
		} break;

		case 2: {
			TruckDB db;
			db.show_all_trucks_ids();
			cout << "    Geef de ID in die je wilt verwijderen: ";
			vector<int> possible_choices = db.possible_choices();
			int keuze;
			while (!(find(possible_choices.begin(), possible_choices.end(), keuze) != possible_choices.end())) {
				cout << "    Dat getal behoort niet tot de mogelijkheden, probeer opnieuw: ";
			}
			db.remove_truck_by_id(keuze);
		} break;

		case 3: {
			TruckDB db;
			cout << "    Alle trucks: " << endl;
			vector<Truck> camion = db.get_trucks_in_vector();
			for (int i = 0; i < camion.size(); i++) {
				cout << "    ID: " << camion[i].get_id() << " , naam: " << camion[i].get_name() << " heeft als lengte: " << camion[i].get_length << " en als breedte: " << camion[i].get_width<< endl;
			}
			cout << endl;
		} break;
		}
	} while (keuze != 0);
	return keuze;
}

int truckMenuLoop() 
{		int keuze;
		do {
			cout << "    1. truck toevoegen" << endl;
			cout << "    2. truck verwijderen" << endl;
			cout << "    3. Lijst met trucks weergeven" << endl;
			cout << "    0. Terug" << endl;
			cout << "    Type je keuze in: ";
			cout << endl;
			if ((keuze < 0) || (keuze > 3)) {
				printf("\033c");
				cout << "    Ongeldige invoer, kies 1 vd menu items." << endl << endl;
			}
		} while ((keuze < 0) || (keuze > 3));
		printf("\033c");
		return keuze;
}

int customerMenu() {
	cout << "    JE BENT IN DE CUSTOMER MENU    " << endl << endl;
	int keuze;
	do {
		keuze = customerMenuLoop();
		switch (keuze) {
		case 1: {
			Customer user = user.make_and_return_customer();
			CustomerDB db;
			db.add_customer(&user);
			cout << "    Klant " << user.getName() << " succesvol opgeslagen in de database!" << endl << endl;
		} break;
		case 2: {
			CustomerDB db;
			vector<Customer> data = db.get_customers();
			vector<int> possible_choices;
			cout << "    Klanten in de database: " << endl << endl;
			for (int i = 0; i < data.size(); i++) {
				cout << "    Klant " << i + 1 << " " << data[i].getName() << endl;
				possible_choices.push_back(i + 1);
			}
			cout << "    Geef de nummer in horende bij de klant waarvan je in meer details wilt zien: ";
			int getal;
			while (!(find(possible_choices.begin(), possible_choices.end(), getal) != possible_choices.end())) {
				cout << "    Dat getal behoort niet tot de mogelijkheden, probeer opnieuw: ";
			}
			cout << endl << endl;
			Customer::print_info_customer(data[getal - 1]);
			cout << endl;
		} break;

		case 3: {
			CustomerDB db;
			vector<Customer> data = db.get_customers();
			cout << "    Klanten in de database: " << endl;
			for (int i = 0; i < data.size(); i++) {
				cout << "    " << data[i].getName() << endl;
			}
			std::cout << "    Geef de naam in van wie je wilt updaten: ";
			std::string nameCustomer;
			getline(cin, nameCustomer);
			db.update_customer(nameCustomer);

		} break;
		case 4: {
			std::cout << "    Geef de naam vd klant in: ";
			std::string naam;
			std::getline(cin, naam);
			CustomerDB db;
			db.remove_customer(naam);
		} break;

		case 5: {
			CustomerDB db;
			db.show_all_customers();
		} break;
		}
	} while (keuze != 0);
	return keuze;
}

int customerMenuLoop() {
	int keuze;
	do {
		cout << "    1. Customer toevoegen" << endl;
		cout << "    2. Customer weergeven" << endl;
		cout << "    3. Customer aanpassen" << endl;
		cout << "    4. Customer verwijderen" << endl;
		cout << "    5. Alle customers weergeven" << endl;
		cout << "    0. Terug" << endl << endl;
		cout << "    Type je keuze in: ";
		cout << endl;
		if ((keuze < 0) || (keuze > 5)) {
			printf("\033c");
			cout << "    Ongeldige invoer, kies 1 vd menu items." << endl << endl;
		}
	} while ((keuze < 0) || (keuze > 5));
	printf("\033c");
	return keuze;
}

int toonOrderMenu() {
	cout << "    JE BENT IN HET ORDER MENU    " << endl << endl;
	int keuze;
	do {
		keuze = orderMenuLoop();
		switch (keuze) {
		case 1: {
			OrderDB db;
			string date;
			int id;
			double length, width;
			bool prio;
			cout << endl << "    Geef de uw klantennummer in aub : ";
			cin >> id;
			cout << "\ngeef de lengte van uw paket in: ";
			cin >> length;
			cout << "\ngeef de breedte can uw paket in: ";
			cin >> width;
			cout << "\nheeft dit paket prioriteit? (1 = hoog, 0 = laag): ";
			cin >> prio;
			//de huidige dag maken als een string
			time_t rawtime;
			struct tm * timeinfo;
			char buffer[80];

			time(&rawtime);
			timeinfo = localtime(&rawtime);

			strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
			string date(buffer);

			db.addOrder(id,width,length,date,prio);
		} break;

		case 2: {
			int order_id;
			int prio;
			OrderDB db;
			cout << "    Geef de ID in om dat transactie waarvan u de prioriteit wilt veranderen: ";
			cin >> order_id;
			cout << "wilt u de prioriteit op hoog (1) of laag (0) zetten : ";
			if (prio == 1) {
				db.changePriorityTrue(order_id);
				break;
			}
			else if (prio == 0)
			{
				db.changePriorityFalse(order_id);
				break;
			}
			else
			{
				cout << "foutieve invoer, probeer het opneiuw";
				break;
			}
		} 

		case 3: {
			OrderDB db;
			cout << "    Geef de ID in van de order die u wilt verwijderen: ";
			int keuze;
			db.removeOrder(keuze);
		} break;
		}
	} while (keuze != 0);
	return keuze;
}

int orderMenuLoop() {
	int keuze;
	do {
		cout << "    1. Nieuw order maken." << endl;
		cout << "    2. de prioriteit van een bestaand order aanpassen " << endl;
		cout << "    3. Bestaande transactie verwijderen" << endl;
		cout << "    0. Terug" << endl << endl;
		cout << "    Type je keuze in: ";
		cout << endl;
		if ((keuze < 0) || (keuze > 3)) {
			printf("\033c");
			cout << "    Ongeldige invoer, kies 1 vd menu items." << endl << endl;
		}
	} while ((keuze < 0) || (keuze > 3));
	printf("\033c");
	return keuze;
}


void main()
{
		char ch;
		intro();
		do
		{
				clrscr();
				cout << "\n\n\n\tMAIN MENU";
				cout << "\n\n\t01. truck menu";
				cout << "\n\n\t02. pakage menu";
				cout << "\n\n\t03. customer menu";
				cout << "\n\n\t04. EXIT";
				cout << "\n\n\tPlease Select Your Option (1-4) ";
				cin >>ch;
				switch (ch)
				{
				case '1':truckMenu();
						break;
				case '2':break;
				case '3':customerMenu();
						break;
				case '4':exit(0);
				default:cout << "\a";
				}
		}while (ch != '4');
}

