#include "Person.h"
#include <iostream>

Person::Person(string _id, string _name, string _email, string _gender, string _phone)
	: id(_id), name(_name), email(_email),gender(_gender),phone(_phone){}

string Person::getId()  {
    return id;
}

string Person::getName()  {
    return name;
}

string Person::getPhone()  {
    return phone;
}
void Person::setName(string name) {
    this->name = name;
}

void Person::setPhone(string phone) {
    this->phone = phone;
}