#include "Bank.h"
#include <iostream>

#define endl '\n'

using namespace std;

int main() {
    Bank bank("Smart Bank");
    int choice;

    while (true) {
        cout << endl << "========= Smart Bank System =========" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Add Employee" << endl;
        cout << "3. Create Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Display All" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            string id, name, email, phone, address;
            int creditScore;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Credit Score: "; cin >> creditScore;
            cin.ignore();
            bank.addCustomer(new Customer(id, name, email, phone, address, creditScore));
            cout << "✅ Customer added successfully!" << endl;

        }
        else if (choice == 2) {
            string id, name, email, phone, address, empId, position;
            double salary;
            int accessLevel;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Employee ID: "; getline(cin, empId);
            cout << "Enter Position: "; getline(cin, position);
            cout << "Enter Salary: "; cin >> salary;
            cout << "Enter Access Level: "; cin >> accessLevel;
            cin.ignore();
            bank.addEmployee(new Employee(id, name, email, phone, address, empId, position, salary, accessLevel));
            cout << "✅ Employee added successfully!" << endl;

        }
        else if (choice == 3) {
            string accId, custId, type;
            cout << "Enter Account ID: "; getline(cin, accId);
            cout << "Enter Customer ID: "; getline(cin, custId);
            cout << "Enter Account Type: "; getline(cin, type);
            bank.createAccount(new Account(accId, custId, type));
            cout << "✅ Account created successfully!" << endl;

        }
        else if (choice == 4 || choice == 5) {
            string accId;
            double amount;
            cout << "Enter Account ID: "; getline(cin, accId);
            cout << "Enter Amount: "; cin >> amount;
            cin.ignore();
            bank.processTransaction(accId, amount, choice == 4);

        }
        else if (choice == 6) {
            bank.displayAll();

        }
        else {
            cout << "❌ Invalid choice. Try again." << endl;
        }
    }

    cout << "👋 Exiting Smart Bank. Goodbye!" << endl;
    return 0;
}
