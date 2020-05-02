#pragma once
#include<string>
using namespace std;

struct Contact
{
	string FullName;
	string phoneNumber;
};

struct user
{
	string email;
	string password;
	string userName;
};

void init();
void addNewContact();
void showAllContacts();
void registrarion();
void login();