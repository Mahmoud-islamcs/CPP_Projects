#pragma once
#include"Person.h"

class Admin :public Person
{
private:
	string role;
public:
	Admin(string _id, string _name, string _email, string _gender, string _phone, string _role = "Administrator");

	void displayDetails()  override;

	void setRole(string _role);

	string getRole();

	void addBus();
	void removeBus();     
	void viewAllBookings();
};

