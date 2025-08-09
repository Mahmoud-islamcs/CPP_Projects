#include <iostream>
#include <vector>
#include <string>
#include "Product.h"
#include "User.h"
#include "Customer.h"
#include "Admin.h"
#include "Order.h"
#define endl '\n'
using namespace std;

vector<Product> products;
vector<Customer> customers;
vector<Admin> admins;
vector<Order> orders;
int productIdCounter = 1;
int orderIdCounter = 1;

void addProduct(string name, double price, int quantity) {
    products.push_back(Product(productIdCounter++, name, price, quantity));
    cout << "Product added successfully." << endl;
}

void viewProducts() {
    if (products.empty()) {
        cout << "No products available." << endl;
        return;
    }
    for (auto p : products) {
        p.displayProduct();
    }
}

void removeProduct(int id) {
    for (auto it = products.begin(); it != products.end(); it++) {
        if (it->getId() == id) {
            products.erase(it);
            cout << "Product removed successfully." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void placeOrder(Customer customer, int productId, int quantity) {
    for (auto p : products) {
        if (p.getId() == productId) {
            if (p.getQuantity() >= quantity) {
                p.setQuantity(p.getQuantity() - quantity);
                orders.push_back(Order(orderIdCounter++, customer.getUsername(), p.getName(), quantity, p.getPrice()));
                cout << "Order placed successfully." << endl;
                return;
            }
            else {
                cout << "Not enough stock." << endl;
                return;
            }
        }
    }
    cout << "Product not found." << endl;
}

void viewOrders() {
    if (orders.empty()) {
        cout << "No orders found." << endl;
        return;
    }
    for (auto o : orders) {
        o.displayOrder();
    }
}

Admin* loginAdmin(string username,string password) {
    for (auto a : admins) {
        if (a.getUsername() == username && a.getPassword() == password) {
            return &a;
        }
    }
    return nullptr;
}

Customer* loginCustomer(string username,string password) {
    for (auto c : customers) {
        if (c.getUsername() == username && c.getPassword() == password) {
            return &c;
        }
    }
    return nullptr;
}

void Customer::removeFromCart(int productId) {
    for (auto it = cart.begin(); it != cart.end(); it++) {
        if (it->productId == productId) {
            cart.erase(it);
            break; 
        }
    }
}

int main() {
    admins.push_back(Admin("admin", "1234"));
    customers.push_back(Customer("customer", "1234"));

    int choice;
    while (true) {
        cout << endl << "=== E-Commerce System ===" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Customer Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string user, pass;
            cout << "Username: "; cin >> user;
            cout << "Password: "; cin >> pass;
            Admin* admin = loginAdmin(user, pass);
            if (admin) {
                int adminChoice;
                while (true) {
                    cout << endl << "--- Admin Menu ---" << endl;
                    cout << "1. Add Product" << endl;
                    cout << "2. View Products" << endl;
                    cout << "3. Remove Product" << endl;
                    cout << "4. View Orders" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Enter choice: ";
                    cin >> adminChoice;
                    if (adminChoice == 1) {
                        string name; double price; int qty;
                        cout << "Product name: "; cin >> name;
                        cout << "Price: "; cin >> price;
                        cout << "Quantity: "; cin >> qty;
                        addProduct(name, price, qty);
                    }
                    else if (adminChoice == 2) {
                        viewProducts();
                    }
                    else if (adminChoice == 3) {
                        int id;
                        cout << "Enter product ID to remove: ";
                        cin >> id;
                        removeProduct(id);
                    }
                    else if (adminChoice == 4) {
                        viewOrders();
                    }
                    else if (adminChoice == 5) {
                        break;
                    }
                }
            }
            else {
                cout << "Invalid admin credentials." << endl;
            }
        }
        else if (choice == 2) {
            string user, pass;
            cout << "Username: "; cin >> user;
            cout << "Password: "; cin >> pass;
            Customer* customer = loginCustomer(user, pass);
            if (customer) {
                int custChoice;
                while (true) {
                    cout << endl << "--- Customer Menu ---" << endl;
                    cout << "1. View Products" << endl;
                    cout << "2. Place Order" << endl;
                    cout << "3. Remove from Cart" << endl;
                    cout << "4. Logout" << endl;
                    cout << "Enter choice: ";
                    cin >> custChoice;
                    if (custChoice == 1) {
                        viewProducts();
                    }
                    else if (custChoice == 2) {
                        int id, qty;
                        cout << "Enter product ID: "; cin >> id;
                        cout << "Quantity: "; cin >> qty;
                        placeOrder(*customer, id, qty);
                    }
                    else if (custChoice == 3) {
                        int id;
                        cout << "Enter product ID to remove from cart: "; cin >> id;
                        customer->removeFromCart(id);
                        cout << "Product removed from cart." << endl;
                    }
                    else if (custChoice == 4) {
                        break;
                    }
                }
            }
            else {
                cout << "Invalid customer credentials." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting system..." << endl;
            break;
        }
    }
    return 0;
}