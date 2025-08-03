#pragma once
#include <string>
using namespace std;

class Person {
protected:
    string id, name, email, gender, phone;

public:
    Person(string _id, string _name, string _email, string _gender, string _phone);
    virtual void displayDetails() = 0;

    string getId() ;
    string getName() ;
    string getPhone() ;

    void setName(string name);
    void setPhone(string phone);
    virtual ~Person() {}
};