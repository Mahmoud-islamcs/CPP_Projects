#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank(string name) : name(name) {}

Bank::~Bank() {
    for (auto c : customers) delete c;
    for (auto e : employees) delete e;
    for (auto a : accounts) delete a;
}

void Bank::addCustomer(Person* customer) {
    customers.push_back(customer);
}

void Bank::addEmployee(Person* employee) {
    employees.push_back(employee);
}

void Bank::createAccount(Account* account) {
    accounts.push_back(account);
}

void Bank::processTransaction(const string& accId, double amount, bool isDeposit) {
    for (auto acc : accounts) {
        if (acc->getId() == accId) {
            if (isDeposit)
                acc->deposit(amount);
            else
                acc->withdraw(amount);
            return;
        }
    }
    cout << "Account not found." << endl;
}

void Bank::displayAll() const {
    cout << "Bank: " << name << endl;

    cout << endl << "Customers:" << endl;
    for (auto c : customers) c->displayDetails();

    cout << endl << "Employees:" << endl;
    for (auto e : employees) e->displayDetails();

    cout << endl << "Accounts:" << endl;
    for (auto a : accounts) a->getTransactionHistory();
}
