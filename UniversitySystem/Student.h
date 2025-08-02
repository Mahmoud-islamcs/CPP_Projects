#pragma once
#include "Person.h"

class Student : public Person {
private:
    string department;
    int level;

public:
    Student(string _id, string _name, string _email, string _gender, string _phone,
        string _department, int _level);

    void displayDetails() const override;
};