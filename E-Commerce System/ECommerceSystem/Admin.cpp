#include "Admin.h"
#include <iostream>
#define endl '\n'

using namespace std;

Admin::Admin()
{

}

Admin::Admin(string _username, string _password, string _name, string _email, string _role)
	:User(username, password, name, email), role(_role) { }

void Admin::displayInfo()
{
	cout << "Admin: " << name << endl;
	cout << "Username: " << username << endl;
	cout << "Role: " << role << endl;
}

string Admin::getRole()
{
	return role;
}
