#pragma once
#include "Person.h"
#include <vector>

class Customer : public Person {
private:
    vector<string> purchasedCars;
    double creditLimit;

public:
    Customer(string id, string name, string email, string phone, string address, double creditLimit);

    void buyCar(const string& carId);
    void viewPurchaseHistory() const;
    void requestFinancing() const;
    void displayDetails() const override;
};