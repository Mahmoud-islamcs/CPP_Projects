#pragma once
#include "Person.h"

class AdminStaff : public Person {
private:
    string position;

public:
    AdminStaff(string _id, string _name, string _email, string _gender, string _phone,
        string _position);

    void displayDetails() const override;
};