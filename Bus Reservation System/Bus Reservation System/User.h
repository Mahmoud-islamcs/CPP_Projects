#pragma once
#include "Person.h"

class User : public Person {
private:
	string userName, password;
public:
	User(string _id, string _name, string _email, string _gender, string _phone, string _username, string _password);
	
    void displayDetails()  override;

    string getUsername() ;
    string getPassword() ;

    void setUsername(string _username);
    void setPassword(string _password);

    void bookTicket();  
    void cancelTicket();  
    void viewBookings();   
};

