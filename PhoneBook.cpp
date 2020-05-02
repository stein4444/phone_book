#include "PhoneBook.h"

#include "PhoneBook.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");

list<Contact> contacts;
const string fileName = "contacts.txt";
const string file = "Users.txt";
user newUser;

list<user> users;
void init()
{
	ifstream fin;
	fin.open(fileName);

	bool isOPen = fin.is_open();

	if (isOPen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		Contact oldContact;
		while (!fin.eof()) {
			currentString++;
			getline(fin, data);

			if (currentString == 1) {
				oldContact.FullName = data;
			}
			else if (currentString == 2)
			{
				oldContact.phoneNumber = data;
				currentString = 0;
				contacts.push_back(oldContact);
				oldContact = Contact();
			}

		}

	}
	fin.close();
}

void addNewContact()
{
	Contact newContact;
	cout << "Enter full name for new contact->_";
	cin.ignore();
	getline(cin, newContact.FullName);

	cout << "Enter phone number for new contact->_";
	cin >> newContact.phoneNumber;

	contacts.push_back(newContact);

	ofstream fout;
	fout.open(fileName, fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else {
		fout << newContact.FullName << endl;
		fout << newContact.phoneNumber << endl;
	}
	fout.close();
	cout << "New contact successful added..." << endl;
	PAUSE
		CLEAR
}

void showAllContacts()
{
	for (Contact item : contacts) {
		cout << item.FullName << " - " << item.phoneNumber << endl;
	}
}

void registrarion()
{
	cout << "Enter your name: ";
	cin >> newUser.userName;
	cout << "Enter your email: ";
	cin >> newUser.email;
	cout << "Enter your password: ";
	cin >> newUser.password;
	users.push_back(newUser);
	ofstream fout;
	fout.open(file, ios::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else {
		//fout << newUser.email << endl;
		fout << newUser.password << endl;
		fout << newUser.userName << endl;
	}
	fout.close();
	cout << "You successfully registered" << endl;
	PAUSE
		CLEAR
}

void login()
{

	string login, password, log, pw;
	ifstream fin;
	fin.open(file, ios::in);
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else
	{
	start:
		cout << "Enter your login: ";
		cin >> login;
		cout << "Enter your password: ";
		cin >> password;
		getline(fin, log);
		getline(fin, pw);
	}

	if (login == log && password == pw) {
		cout << "Hello " << login << endl;
	}
	else
	{

		cout << "Error try again" << endl;
		goto start;
	}





	fin.close();

}







