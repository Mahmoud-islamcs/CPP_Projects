#pragma once
#include "User.h"
#include <vector>
#include <string> 
using namespace std;

struct CartItem {
    int productId;
    int quantity;
};

class Customer : public User
{
private:
    vector<CartItem> cart;

public:
    Customer();
    Customer(string _username, string _password,
        string _name, string _email);

    void displayInfo() override;

    void addToCart(int productId, int quantity);
    void removeFromCart(int productId);
    vector<CartItem>getCart();
    void clearCart();
};

