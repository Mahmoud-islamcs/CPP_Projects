#pragma once
#include <string>
#include <vector>
using namespace std;

struct OrderItem {
    int productId;
    string productName;
    double unitPrice;
    int quantity;
};

class Order {
private:
    int orderId;
    string customerUsername;
    vector<OrderItem> items;
    double totalPrice;

public:
    Order();
    Order(int _orderId, string _customerUsername, vector<OrderItem> _items);

    int getOrderId() ;
    string getCustomerUsername() ;
    double getTotalPrice() ;

    void displayOrder() ;
};