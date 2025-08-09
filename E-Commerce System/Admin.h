#pragma once
#include "User.h"

using namespace std;

class Admin : public User {
private:
    string role; 
public:
    Admin();
    Admin(string _username, string _password, string _name, string _email, string _role = "Administrator");

    void displayInfo() override;
    string getRole();
};