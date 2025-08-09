#pragma once
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
    string name;
    string email;

public:
    User();
    User(string _username, string _password,
        string _name, string _email);

    virtual ~User();

    string getUsername() ;
    bool checkPassword(string _pw);
    string getName();

    virtual void displayInfo() = 0;
};