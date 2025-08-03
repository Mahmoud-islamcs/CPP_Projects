#include "User.h"
#include <iostream>

User::User(string _id, string _name, string _email, string _gender, string _phone, string _username, string _password)
	:Person(_id, _name, _email, _gender,_phone),userName(_username),password(_password){ }

void User::displayDetails()
{
    cout << "User Details:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Username: " << userName << endl;
}

string User::getUsername()
{
    return userName;
}

string User::getPassword()
{
    return password;
}

void User::setUsername(string _username)
{
    this->userName = _username;
}

void User::setPassword(string _password)
{
    this->password = _password;
}

void User::bookTicket()
{
    cout << "Booking ticket... " << endl;
}

void User::cancelTicket()
{
    cout << "Cancelling ticket... " << endl;
}

void User::viewBookings()
{
    cout << "Viewing bookings... " << endl;
}

