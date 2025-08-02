#include "Showroom.h"
#include <iostream>

#define endl '\n'

using namespace std;


int main() {
    Showroom showroom("AutoMax");
    int choice;
    cout << "Test";
    do {
        cout << endl << "========== Car Showroom Management ==========" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Add Employee" << endl;
        cout << "3. Add Car to Inventory" << endl;
        cout << "4. Process Car Sale" << endl;
        cout << "5. View Available Cars" << endl;
        cout << "6. View All Sales" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string id, name, email, phone, address;
            double creditLimit;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Credit Limit: "; cin >> creditLimit;
            cin.ignore();
            showroom.addCustomer(new Customer(id, name, email, phone, address, creditLimit));
            cout << "✅ Customer added." << endl;

        }
        else if (choice == 2) {
            string id, name, email, phone, address, empId, role;
            double salary;
            int access;
            cout << "Enter ID: "; getline(cin, id);
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter Address: "; getline(cin, address);
            cout << "Enter Employee ID: "; getline(cin, empId);
            cout << "Enter Role: "; getline(cin, role);
            cout << "Enter Salary: "; cin >> salary;
            cout << "Enter Access Level (0 or 1): "; cin >> access;
            cin.ignore();
            showroom.addEmployee(new Employee(id, name, email, phone, address, empId, role, salary, access));
            cout << "✅ Employee added." << endl;

        }
        else if (choice == 3) {
            string carId, brand, model;
            int year;
            double price;
            cout << "Enter Car ID: "; getline(cin, carId);
            cout << "Enter Brand: "; getline(cin, brand);
            cout << "Enter Model: "; getline(cin, model);
            cout << "Enter Year: "; cin >> year;
            cout << "Enter Price: "; cin >> price;
            cin.ignore();
            showroom.addCar(new Car(carId, brand, model, year, price));
            cout << "✅ Car added to inventory." << endl;

        }
        else if (choice == 4) {
            string carId, custId, empId;
            cout << "Enter Car ID to sell: "; getline(cin, carId);
            cout << "Enter Customer ID: "; getline(cin, custId);
            cout << "Enter Employee ID: "; getline(cin, empId);
            showroom.processSale(carId, custId, empId);

        }
        else if (choice == 5) {
            showroom.displayInventory();

        }
        else if (choice == 6) {
            showroom.displayAllSales();

        }
        else if (choice == 0) {
            cout << "👋 Exiting system." << endl;

        }
        else {
            cout << "❌ Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
