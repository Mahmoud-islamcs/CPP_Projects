#pragma once
#include <vector>
#include <string>
#include "Customer.h"
#include "Employee.h"
#include "Car.h"
#include "Sale.h"
using namespace std;

class Showroom {
private:
    string name;
    vector<Person*> customers;
    vector<Person*> employees;
    vector<Car*> cars;
    vector<Sale*> sales;

public:
    Showroom(string name);
    ~Showroom();

    void addCustomer(Person* customer);
    void addEmployee(Person* employee);
    void addCar(Car* car);
    void processSale(string carId, string customerId, string employeeId);
    void displayInventory() const;
    void displayAllSales() const;
};
