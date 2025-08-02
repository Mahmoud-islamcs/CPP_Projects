#include "Member.h"
#include <iostream>
using namespace std;

Member::Member(string id, string name, string email, string phone, string address, string membershipId)
    : Person(id, name, email, phone, address), membershipId(membershipId), fineAmount(0.0) {
}

void Member::borrowBook(const string& bookId) {
    borrowedBooks.push_back(bookId);
}

void Member::returnBook(const string& bookId) {
    borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
}

void Member::viewBorrowedBooks() const {
    cout << "Borrowed books by " << name << ":" << endl;
    for (const auto& book : borrowedBooks)
        cout << " - " << book << endl;
}

void Member::payFine(double amount) {
    fineAmount -= amount;
    if (fineAmount < 0) fineAmount = 0;
    cout << "Fine paid: " << amount << ". Remaining fine: " << fineAmount << endl;
}

void Member::displayDetails() const {
    cout << "Member ID: " << id << ", Name: " << name << ", Membership ID: " << membershipId
        << ", Fine: " << fineAmount << endl;
    viewBorrowedBooks();
}

string Member::getMembershipId() const {
    return membershipId;
}

bool Member::hasBook(const string& bookId) const {
    return find(borrowedBooks.begin(), borrowedBooks.end(), bookId) != borrowedBooks.end();
}
