#include "Order.h"
#include <iostream>
#include <iomanip>
#define endl '\n'

Order::Order()
{
	orderId = 0;
	customerUsername = "";
	totalPrice = 0.0;
}

Order::Order(int _orderId, string _customerUsername, vector<OrderItem> _items) 
	:orderId(_orderId), customerUsername(_customerUsername), items(_items) { 
	totalPrice = 0;
	for (auto it : items) 
		totalPrice += it.unitPrice * it.quantity;
}

int Order::getOrderId()
{
	return orderId;
}

string Order::getCustomerUsername()
{
	return customerUsername;
}

double Order::getTotalPrice()
{
	return totalPrice;
}

void Order::displayOrder()
{
	cout << "Order ID: " << orderId << " | Customer: " << customerUsername << endl;
	cout << "Items: ";
	cout << left << setw(6) << "Product Id" << setw(20) << "Name" << setw(10) << "Unit" << setw(6) << "Quantity" << setw(10) << "Subtotal" << endl;
	for (auto it : items) {
		double sub = it.unitPrice * it.quantity;
		cout << left << setw(6) << it.productId << setw(20) << it.productName
			<< setw(10) << it.unitPrice << setw(6) << it.quantity << setw(10) << sub << endl;
	}                                                 
	cout << "Total: $" << totalPrice << endl;
}
