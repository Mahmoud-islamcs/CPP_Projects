#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string id, string name, string email, string phone, string address,
    string employeeId, string role, double salary, int accessLevel)
    : Person(id, name, email, phone, address), employeeId(employeeId), role(role), salary(salary), accessLevel(accessLevel) {
}

void Employee::sellCar() {
    cout << name << " sold a car." << endl;;
}

void Employee::addCarToInventory() {
    if (accessLevel >= 1)
        cout << name << " added a car to inventory.\n";
    else
        cout << "Access denied.\n";
}

void Employee::viewSalesReport() {
    cout << "Sales report viewed by " << name << endl;
}

void Employee::displayDetails() const {
    cout << "Employee: " << name << " | Role: " << role << " | Salary: " << salary << endl;
}