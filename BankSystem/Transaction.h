#pragma once
#include <string>
using namespace std;

class Transaction {
private:
    static int counter;
    string transactionId, accountId, type;
    double amount;

public:
    Transaction(string accountId, string type, double amount);
    void displayTransaction() const;
};
