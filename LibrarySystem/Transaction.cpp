#include "Transaction.h"
#include <iostream>
using namespace std;

int Transaction::counter = 0;

Transaction::Transaction(string bookId, string memberId, string type, string date, string dueDate)
    : bookId(bookId), memberId(memberId), type(type), date(date), dueDate(dueDate) {
    transactionId = "TX" + to_string(++counter);
}

void Transaction::displayTransactionDetails() const {
    cout << "Transaction [" << transactionId << "] " << type
        << " Book: " << bookId << ", Member: " << memberId
        << ", Date: " << date;
    if (type == "Borrow")
        cout << ", Due: " << dueDate;
    cout << endl;
}
