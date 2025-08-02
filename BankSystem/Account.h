#pragma once
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class Account {
private:
    string accountId, customerId, accountType;
    double balance;
    vector<Transaction> transactions;

public:
    Account(string accountId, string customerId, string accountType);

    void deposit(double amount);
    void withdraw(double amount);
    void getTransactionHistory() const;
    string getId() const;
};
