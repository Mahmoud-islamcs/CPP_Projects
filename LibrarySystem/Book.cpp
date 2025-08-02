#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string bookId, string title, string author, string isbn)
    : bookId(bookId), title(title), author(author), isbn(isbn), isAvailable(true), borrowedBy("") {
}

void Book::updateAvailability(bool available, const string& memberId) {
    isAvailable = available;
    borrowedBy = available ? "" : memberId;
}

void Book::displayBookInfo() const {
    cout << "Book [" << bookId << "] Title: " << title
        << ", Author: " << author << ", ISBN: " << isbn
        << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
}

string Book::getId() const { 
    return bookId; 
}
bool Book::available() const {
    return isAvailable; 
}
string Book::getBorrowedBy() const {
    return borrowedBy; 
}
