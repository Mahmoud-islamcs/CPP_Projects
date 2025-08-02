#pragma once
#include "Person.h"

class Employee : public Person {
private:
    string employeeId, position;
    double salary;
    int accessLevel;

public:
    Employee(string _id, string _name, string _email, string _phone, string _address,
        string employeeId, string position, double salary, int accessLevel);

    void approveLoan() const;
    void manageCustomer() const;
    void viewTransactions() const;
    void displayDetails() const override;
};
