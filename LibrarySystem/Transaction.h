#pragma once
#include <string>
using namespace std;

class Transaction {
private:
    static int counter;
    string transactionId, bookId, memberId, type, date, dueDate;

public:
    Transaction(string bookId, string memberId, string type, string date, string dueDate = "");

    void displayTransactionDetails() const;
};
