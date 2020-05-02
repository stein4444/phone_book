#include<iostream>
#include<string>
#include "PhoneBook.h"

using namespace std;

int main() {
	init();
	int action = 0;
	start:
		cout << "If you want register press - 1" << endl;
		cout << "If you want logn press - 2" << endl;
		cout << "action>_";
		cin >> action;
		if (action == 1) {
			registrarion();
			login();
		}
		else if(action == 2)
		{
			login();
		}
		else if (action < 1 || action > 2)
		{

			cout << "Error try again" << endl;
			goto start;
		}
			
			

	do
	{
		cout << "\tMENU:" << endl;
		cout << "1. Add new contact" << endl;
		cout << "2. Show all contacts" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "Select action ->_";
		cin >> action;

		switch (action)
		{
		case 1: {
			cout << "ADD NEW CONTACT:" << endl;
			addNewContact();
		}break;

		case 2: {
			cout << "LIST ALL CONTACTS:" << endl;
			showAllContacts();
		}break;

		case 3: {
			cout << "Bye" << endl;
		}break;
		default: {
			cout << "Please select action (1 - 3)" << endl;
		}
		}

	} while (action != 3);

	return 0;
}