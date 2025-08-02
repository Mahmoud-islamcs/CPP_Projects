#pragma once
#include <vector>
#include "Customer.h"
#include "Employee.h"
#include "Account.h"

class Bank {
private:
    string name;
    vector<Person*> customers;
    vector<Person*> employees;
    vector<Account*> accounts;

public:
    Bank(string name);
    ~Bank();
    void addCustomer(Person* customer);
    void addEmployee(Person* employee);
    void createAccount(Account* account);
    void processTransaction(const string& accId, double amount, bool isDeposit);
    void displayAll() const;
};
