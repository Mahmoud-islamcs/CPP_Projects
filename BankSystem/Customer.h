#pragma once
#include "Person.h"
#include <vector>

class Customer : public Person {
private:
    vector<string> accounts;
    int creditScore;

public:
    Customer(string _id, string _name, string _email, string _phone, string _address, int _creditScore);
    void openAccount(const string& accountId);
    void viewAccountDetails() const;
    void requestLoan() const;
    void displayDetails() const override;
    vector<string> getAccounts() const;
};
