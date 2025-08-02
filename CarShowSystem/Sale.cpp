#include "Sale.h"
#include <iostream>
using namespace std;

Sale::Sale(string saleId, string carId, string customerId, string employeeId, double salePrice, string saleDate)
    : saleId(saleId), carId(carId), customerId(customerId), employeeId(employeeId), salePrice(salePrice), saleDate(saleDate) {
}

void Sale::displaySaleDetails() const {
    cout << "Sale ID: " << saleId << " | Car ID: " << carId << " | Customer ID: " << customerId
        << " | Employee ID: " << employeeId << " | Price: " << salePrice << " | Date: " << saleDate << endl;
}

string Sale::getCarId() const { 
    return carId; 
}
