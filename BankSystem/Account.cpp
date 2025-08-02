#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(string accountId, string customerId, string accountType)
    : accountId(accountId), customerId(customerId), accountType(accountType), balance(0.0) {
}

void Account::deposit(double amount) {
    balance += amount;
    transactions.emplace_back(accountId, "Deposit", amount);
    cout << "Deposited: " << amount << " to " << accountId << endl;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        transactions.emplace_back(accountId, "Withdrawal", amount);
        cout << "Withdrawn: " << amount << " from " << accountId << endl;
    }
    else {
        cout << "Insufficient balance." << endl;
    }
}

void Account::getTransactionHistory() const {
    for (const auto& t : transactions)
        t.displayTransaction();
}

string Account::getId() const {
    return accountId;
}
