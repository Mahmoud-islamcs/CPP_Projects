#pragma once
#include "Person.h"

class Employee : public Person {
private:
    string employeeId, role;
    double salary;
    int accessLevel;

public:
    Employee(string id, string name, string email, string phone, string address,
        string employeeId, string role, double salary, int accessLevel);

    void sellCar();
    void addCarToInventory();
    void viewSalesReport();
    void displayDetails() const override;
};