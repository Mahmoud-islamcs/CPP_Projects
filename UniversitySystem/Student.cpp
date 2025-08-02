#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string _id, string _name, string _email, string _gender, string _phone,
    string _department, int _level)
    : Person(_id, _name, _email, _gender, _phone), department(_department), level(_level) {
}

void Student::displayDetails() const {
    cout << "Student -- > " << endl << "Name: " << name << endl << "ID : " << id
        << endl << "Department: " << department << endl << "Level: " << level << endl << endl;
}
