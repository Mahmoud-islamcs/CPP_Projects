#pragma once
#include <string>
using namespace std;

class Person {
protected:
    string id, name, email, phone, address;

public:
    Person(string id, string name, string email, string phone, string address);
    virtual void displayDetails() const = 0;
    virtual ~Person() {}

    string getId() const;
    string getName() const;
    void setEmail(const string& email);
    void setPhone(const string& phone);
    void setAddress(const string& address);
};
