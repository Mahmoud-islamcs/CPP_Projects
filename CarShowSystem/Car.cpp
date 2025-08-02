#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(string carId, string brand, string model, int year, double price)
    : carId(carId), brand(brand), model(model), year(year), price(price), isSold(false) {
}

void Car::updatePrice(double newPrice) {
    price = newPrice;
}

void Car::markAsSold() {
    isSold = true;
}

void Car::displayCarInfo() const {
    cout << "Car: " << brand << " " << model << " | Year: " << year
        << " | Price: " << price << " | Status: " << (isSold ? "Sold" : "Available") << endl;
}

string Car::getId() const { 
    return carId; 
}
bool Car::sold() const {
    return isSold;
}
