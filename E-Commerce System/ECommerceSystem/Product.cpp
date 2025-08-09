#include "Product.h"
#include <iostream>
using namespace std;

Product::Product()
{
	id = 0;
	name = "";
	price = 0.0;
	quantity = 0;
}

Product::Product(int _id, string _name, double _price, int _quantity)
	:id(_id), name(_name), price(_price), quantity(_quantity) { }

int Product::getId()
{
	return id;
}

string Product::getName()
{
	return name;
}

double Product::getPrice()
{
	return price;
}

int Product::getQuantity()
{
	return quantity;
}

void Product::setQuantity(int _quantity)
{
	quantity = _quantity;
}

void Product::reduceQuantity(int _amount)
{
	if (_amount <= 0) 
		return;
	if (_amount > quantity) 
		quantity = 0;
	else 
		quantity -= _amount;
}

void Product::displayProduct()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Price: $" << price << endl;
	cout << "Stock: " << quantity << endl;
}

