#pragma once
#include "Person.h"
#include <vector>

class Member : public Person {
private:
    string membershipId;
    vector<string> borrowedBooks;
    double fineAmount;

public:
    Member(string id, string name, string email, string phone, string address, string membershipId);

    void borrowBook(const string& bookId);
    void returnBook(const string& bookId);
    void viewBorrowedBooks() const;
    void payFine(double amount);
    void displayDetails() const override;

    string getMembershipId() const;
    bool hasBook(const string& bookId) const;
};
