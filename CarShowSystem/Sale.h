#pragma once
#include <string>
using namespace std;

class Sale {
private:
    string saleId, carId, customerId, employeeId, saleDate;
    double salePrice;

public:
    Sale(string saleId, string carId, string customerId, string employeeId, double salePrice, string saleDate);

    void displaySaleDetails() const;
    string getCarId() const;
};
