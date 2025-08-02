#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string id, string name, string email, string phone, string address, double creditLimit)
    : Person(id, name, email, phone, address), creditLimit(creditLimit) {
}

void Customer::buyCar(const string& carId) {
    purchasedCars.push_back(carId);
}

void Customer::viewPurchaseHistory() const {
    cout << "Purchase history for " << name << ":" << endl;
    for (const auto& id : purchasedCars)
        cout << " - " << id << endl;
}

void Customer::requestFinancing() const {
    cout << "Requested financing up to: " << creditLimit << endl;
}

void Customer::displayDetails() const {
    cout << "Customer: " << name << " | Email: " << email << " | Credit Limit: " << creditLimit << endl;
    viewPurchaseHistory();
}
