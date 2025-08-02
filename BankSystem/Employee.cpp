#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string id, string name, string email, string phone, string address,
    string employeeId, string position, double salary, int accessLevel)
    : Person(id, name, email, phone, address), employeeId(employeeId),
    position(position), salary(salary), accessLevel(accessLevel) {
}

void Employee::approveLoan() const {
    cout << "Employee " << name << " approved a loan." << endl;
}

void Employee::manageCustomer() const {
    cout << "Managing customer records..." << endl;
}

void Employee::viewTransactions() const {
    cout << "Viewing transaction history..." << endl;
}

void Employee::displayDetails() const {
    cout << "Employee ID: " << employeeId << ", Name: " << name
        << ", Position: " << position << ", Salary: " << salary << endl;
}
