#pragma once
#include <string>

using namespace std;
class Product
{
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Product();
    Product(int _id, string _name, double _price, int _quantity);

    int getId() ;
    string getName() ;
    double getPrice() ;
    int getQuantity() ;

    void setQuantity(int _quantity);
    void reduceQuantity(int _amount); 

    void displayProduct();
};
