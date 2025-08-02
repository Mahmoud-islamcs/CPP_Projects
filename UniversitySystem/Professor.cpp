#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(string _id, string _name, string _email, string _gender, string _phone,
    string _specialization, int _years)
    : Person(_id, _name, _email, _gender, _phone),
    specialization(_specialization), yearsOfExperience(_years) {
}

void Professor::displayDetails() const {
    cout << "Professor" << endl << "Name: " << name << endl << "ID: " << id
        << endl << "Specialization: " << specialization
        << endl << "Experience: " << yearsOfExperience << " years" << endl << endl;
}
