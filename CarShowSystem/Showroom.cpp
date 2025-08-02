#include "Showroom.h"
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

Showroom::Showroom(string name) : name(name) {}

Showroom::~Showroom() {
    for (auto c : customers) delete c;
    for (auto e : employees) delete e;
    for (auto c : cars) delete c;
    for (auto s : sales) delete s;
}

void Showroom::addCustomer(Person* customer) {
    customers.push_back(customer);
}

void Showroom::addEmployee(Person* employee) {
    employees.push_back(employee);
}

void Showroom::addCar(Car* car) {
    cars.push_back(car);
}

void Showroom::processSale(string carId, string customerId, string employeeId) {
    Car* selectedCar = nullptr;
    for (auto c : cars) {
        if (c->getId() == carId && !c->sold()) {
            selectedCar = c;
            break;
        }
    }
    if (!selectedCar) {
        cout << "❌ Car not found or already sold." << endl;
        return;
    }

    Customer* customer = nullptr;
    for (auto p : customers) {
        if (p->getId() == customerId)
            customer = dynamic_cast<Customer*>(p);
    }

    Employee* employee = nullptr;
    for (auto p : employees) {
        if (p->getId() == employeeId)
            employee = dynamic_cast<Employee*>(p);
    }

    if (!customer || !employee) {
        cout << "❌ Invalid customer or employee ID." << endl;
        return;
    }

    stringstream ss;
    ss << "S" << sales.size() + 1;
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    string date(buffer);
    date.pop_back();


    selectedCar->markAsSold();
    customer->buyCar(carId);
    employee->sellCar();

    sales.push_back(new Sale(ss.str(), carId, customerId, employeeId, selectedCar->sold() ? 0 : selectedCar->sold(), date));
    cout << "✅ Sale recorded successfully." << endl;
}

void Showroom::displayInventory() const {
    cout << endl << "Available Cars:" << endl;
    for (auto car : cars)
        if (!car->sold())
            car->displayCarInfo();
}

void Showroom::displayAllSales() const {
    cout << endl << "All Sales:" << endl;
    for (auto s : sales)
        s->displaySaleDetails();
}
