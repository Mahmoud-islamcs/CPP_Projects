#include "Admin.h"
#include <iostream>

Admin::Admin(string _id, string _name, string _email, string _gender, string _phone, string _role)
	:Person(_id, _name, _email, _gender, _phone),role(_role){ }

void Admin::displayDetails()  {
    cout << "Admin Details:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Role: " << role << endl;
}

void Admin::setRole(string _role)
{
    this->role = _role;
}

string Admin::getRole()
{
    return role;
}

void Admin::addBus()
{
    cout << "Removing bus... " << endl;
}

void Admin::removeBus()
{
    cout << "Removing bus... " << endl;
}

void Admin::viewAllBookings()
{
    cout << "Viewing all bookings... " << endl;
}
    