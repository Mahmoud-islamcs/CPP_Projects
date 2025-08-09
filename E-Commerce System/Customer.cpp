#include "Customer.h"
#include <iostream>

#define endl '\n'

Customer::Customer()
{

}

Customer::Customer(string _username, string _password, string _name, string _email)
	:User(username, password, name, email) { }

void Customer::displayInfo()
{
	cout << "Customer: " << name << endl;
	cout << "Username: " << username << endl;
}

void Customer::addToCart(int productId, int quantity)
{
    if (quantity <= 0) 
        return;
    for (auto item : cart) {
        if (item.productId == productId) {
            item.quantity += quantity;
            return;
        }
    }
    cart.push_back({ productId, quantity });
}

void Customer::removeFromCart(int productId)
{
    for (auto it = cart.begin(); it != cart.end(); ++it) {
        if (it->productId == productId) {
            cart.erase(it);
            break; 
        }
    }
}

vector<CartItem> Customer::getCart()
{
    return cart;
}

void Customer::clearCart()
{
    cart.clear();
}
