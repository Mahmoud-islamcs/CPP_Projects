#pragma once
#include "Person.h"

class Professor : public Person {
private:
    string specialization;
    int yearsOfExperience;

public:
    Professor(string _id, string _name, string _email, string _gender, string _phone,
        string _specialization, int _years);

    void displayDetails() const override;
};