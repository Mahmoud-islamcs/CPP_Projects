#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string id, string name, string email, string phone, string address, int creditScore)
    : Person(id, name, email, phone, address), creditScore(creditScore) {
}

void Customer::openAccount(const string& accountId) {
    accounts.push_back(accountId);
}

void Customer::viewAccountDetails() const {
    cout << "Accounts for " << name << ":" << endl;
    for (const auto& acc : accounts)
        cout << " - " << acc << endl;
}

void Customer::requestLoan() const {
    cout << "Loan requested by " << name << " with credit score: " << creditScore << endl;
}

void Customer::displayDetails() const {
    cout << "Customer ID: " << id << ", Name: " << name << ", Email: " << email << endl;
    viewAccountDetails();
}

vector<string> Customer::getAccounts() const {
    return accounts;
}
