#include "Librarian.h"
#include <iostream>
using namespace std;

Librarian::Librarian(string id, string name, string email, string phone, string address,
    string employeeId, string role, double salary, int accessLevel)
    : Person(id, name, email, phone, address),
    employeeId(employeeId), role(role), salary(salary), accessLevel(accessLevel) {
}

void Librarian::displayDetails() const {
    cout << "Librarian ID: " << id << ", Name: " << name
        << ", Role: " << role << ", Salary: " << salary << endl;
}
