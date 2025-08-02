#pragma once
#include <string>
using namespace std;

class Book {
private:
    string bookId, title, author, isbn;
    bool isAvailable;
    string borrowedBy;

public:
    Book(string bookId, string title, string author, string isbn);

    void updateAvailability(bool available, const string& memberId = "");
    void displayBookInfo() const;

    string getId() const;
    bool available() const;
    string getBorrowedBy() const;
};
