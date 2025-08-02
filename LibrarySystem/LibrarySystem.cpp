#include "Library.h"
#include <iostream>

#define endl '\n'

using namespace std;

int main() {
    Library library("Minia University Library");
    int choice;

    while (true) {
        cout << endl << "========= Library System =========" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Add Librarian" << endl;
        cout << "3. Add Book" << endl;
        cout << "4. Borrow Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Display Inventory" << endl;
        cout << "7. Display Transactions" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            string id, name, email, phone, address, membershipId;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Membership ID: "; getline(cin, membershipId);
            library.addMember(new Member(id, name, email, phone, address, membershipId));
            cout << "✅ Member added successfully!" << endl;

        }
        else if (choice == 2) {
            string id, name, email, phone, address, empId, role;
            double salary;
            int accessLevel;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Employee ID: "; getline(cin, empId);
            cout << "Enter Role: "; getline(cin, role);
            cout << "Enter Salary: "; cin >> salary;
            cout << "Enter Access Level: "; cin >> accessLevel;
            cin.ignore();
            library.addLibrarian(new Librarian(id, name, email, phone, address, empId, role, salary, accessLevel));
            cout << "✅ Librarian added successfully!\n";

        }
        else if (choice == 3) {
            string bookId, title, author, isbn;
            cout << "Enter Book ID: "; getline(cin, bookId);
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Author: "; getline(cin, author);
            cout << "Enter ISBN: "; getline(cin, isbn);
            library.addBook(new Book(bookId, title, author, isbn));
            cout << "✅ Book added successfully!" << endl;

        }
        else if (choice == 4) {
            string bookId, memberId;
            cout << "Enter Book ID: "; getline(cin, bookId);
            cout << "Enter Member ID: "; getline(cin, memberId);
            library.processBorrow(bookId, memberId);

        }
        else if (choice == 5) {
            string bookId, memberId;
            cout << "Enter Book ID: "; getline(cin, bookId);
            cout << "Enter Member ID: "; getline(cin, memberId);
            library.processReturn(bookId, memberId);

        }
        else if (choice == 6) {
            library.displayInventory();

        }
        else if (choice == 7) {
            library.displayAllTransactions();

        }
        else {
            cout << "❌ Invalid choice. Try again." << endl;
        }
    }

    cout << "👋 Exiting Library System. Goodbye!" << endl;
    return 0;
}
