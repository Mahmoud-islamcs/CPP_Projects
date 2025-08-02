#include "Person.h"

Person::Person(string id, string name, string email, string phone, string address)
    : id(id), name(name), email(email), phone(phone), address(address) {
}

string Person::getId() const { 
    return id; 
}
string Person::getName() const {
    return name; 
}

void Person::setEmail(const string& email) {
    this->email = email; 
}
void Person::setPhone(const string& phone) {
    this->phone = phone;
}
void Person::setAddress(const string& address) { 
    this->address = address; 
}
