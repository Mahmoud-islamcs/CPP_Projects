#include "Transaction.h"
#include <iostream>
using namespace std;

int Transaction::counter = 0;

Transaction::Transaction(string accountId, string type, double amount)
    : accountId(accountId), type(type), amount(amount) {
    transactionId = "TXN" + to_string(++counter);
}

void Transaction::displayTransaction() const {
    cout << "Transaction [" << transactionId << "] " << type << " of " << amount
        << " on account " << accountId << endl;
}
