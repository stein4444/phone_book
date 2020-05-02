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
	string login;
	string password;
};

void init();
void addNewContact();
void showAllContacts();
void registrarion();
void login();