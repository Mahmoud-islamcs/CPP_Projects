#pragma once
#include "Person.h"

class Librarian : public Person {
private:
    string employeeId, role;
    double salary;
    int accessLevel;

public:
    Librarian(string id, string name, string email, string phone, string address,
        string employeeId, string role, double salary, int accessLevel);

    void displayDetails() const override;
};
