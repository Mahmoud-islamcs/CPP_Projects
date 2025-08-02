#pragma once
#include <string>
using namespace std;

class Car {
private:
    string carId, brand, model;
    int year;
    double price;
    bool isSold;

public:
    Car(string carId, string brand, string model, int year, double price);

    void updatePrice(double newPrice);
    void markAsSold();
    void displayCarInfo() const;

    string getId() const;
    bool sold() const;
};