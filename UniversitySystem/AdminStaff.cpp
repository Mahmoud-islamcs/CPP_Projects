#include "AdminStaff.h"
#include <iostream>
using namespace std;

AdminStaff::AdminStaff(string _id, string _name, string _email, string _gender, string _phone,
    string _position)
    : Person(_id, _name, _email, _gender, _phone), position(_position) {
}

void AdminStaff::displayDetails() const {
    cout << "Admin Staff" << endl << "Name: " << name << endl << "ID: " << id
        << endl << "Position: " << position << endl << endl;
}
