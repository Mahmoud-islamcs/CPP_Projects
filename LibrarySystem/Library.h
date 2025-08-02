#pragma once
#include <vector>
#include "Member.h"
#include "Librarian.h"
#include "Book.h"
#include "Transaction.h"

class Library {
private:
    string name;
    vector<Person*> members;
    vector<Person*> librarians;
    vector<Book*> books;
    vector<Transaction*> transactions;

public:
    Library(string name);
    ~Library();

    void addMember(Person* member);
    void addLibrarian(Person* librarian);
    void addBook(Book* book);

    void processBorrow(const string& bookId, const string& memberId);
    void processReturn(const string& bookId, const string& memberId);

    void displayInventory() const;
    void displayAllTransactions() const;
};
