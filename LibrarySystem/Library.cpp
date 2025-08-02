#include "Library.h"
#include <iostream>
#include <ctime>
using namespace std;

Library::Library(string name) : name(name) {}

Library::~Library() {
    for (auto p : members) delete p;
    for (auto p : librarians) delete p;
    for (auto b : books) delete b;
    for (auto t : transactions) delete t;
}

void Library::addMember(Person* member) {
    members.push_back(member);
}

void Library::addLibrarian(Person* librarian) {
    librarians.push_back(librarian);
}

void Library::addBook(Book* book) {
    books.push_back(book);
}

void Library::processBorrow(const string& bookId, const string& memberId) {
    Book* book = nullptr;
    Member* member = nullptr;

    for (auto b : books)
        if (b->getId() == bookId) book = b;

    for (auto p : members)
        if (p->getId() == memberId)
            member = dynamic_cast<Member*>(p);

    if (book && member && book->available()) {
        book->updateAvailability(false, memberId);
        member->borrowBook(bookId);

        time_t now = time(0);
        string date = ctime(&now);
        string dueDate = "1 week later"; 

        transactions.push_back(new Transaction(bookId, memberId, "Borrow", date, dueDate));
        cout << "Book borrowed successfully!" << endl;
    }
    else {
        cout << "Borrow failed (book not available or member not found)." << endl;
    }
}

void Library::processReturn(const string& bookId, const string& memberId) {
    Book* book = nullptr;
    Member* member = nullptr;

    for (auto b : books)
        if (b->getId() == bookId) book = b;

    for (auto p : members)
        if (p->getId() == memberId)
            member = dynamic_cast<Member*>(p);

    if (book && member && member->hasBook(bookId)) {
        book->updateAvailability(true);
        member->returnBook(bookId);

        time_t now = time(0);
        string date = ctime(&now);

        transactions.push_back(new Transaction(bookId, memberId, "Return", date));
        cout << "Book returned successfully!" << endl;
    }
    else {
        cout << "Return failed (book not found or wasn't borrowed)." << endl;
    }
}

void Library::displayInventory() const {
    cout << "Library Inventory:" << endl;
    for (auto b : books)
        b->displayBookInfo();
}

void Library::displayAllTransactions() const {
    cout << "All Transactions:" << endl;
    for (auto t : transactions)
        t->displayTransactionDetails();
}
