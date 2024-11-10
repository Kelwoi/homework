#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	phoneBook phonebook;
	int choice;
	char name[500];
	size_t worknumber;
	size_t homenumber;
	size_t number;
	char extra_info[500];
	while (true)
	{
		cout << "Phone Book Menu!\n1. add contact\n2.show all contacts\n3.delete contact by pib\n4.find contact by pib\n5.exit\nchoice: ";
		cin >> choice;
		if (choice == 1) {
			cin.ignore();
			cout << "Enter pib(name surname byfather): ";
			cin.getline(name, 50);
			cout << "Enter work number: ";
			cin >> worknumber;
			cout << "Enter home number: ";
			cin >> homenumber;
			cout << "Enter personal number: ";
			cin >> number;
			cin.ignore();
			cout << "Enter extra info:  ";
			cin.getline(extra_info, 50);
			phonebook.add_contact(name, worknumber, homenumber, number, extra_info);
		}
		else if (choice == 2) {
			phonebook.show_contacts();
		}
		else if (choice == 3) {
			cin.ignore();
			cout << "Enter pib(name surname byfather): ";
			cin.getline(name, 50);
			phonebook.delete_cont(name);
		}
		else if (choice == 4) {
			cin.ignore();
			cout << "Enter pib(name surname byfather): ";
			cin.getline(name, 50);
			phonebook.find(name);
		}
		else if (choice == 5) {
			break;
		}
	}



}