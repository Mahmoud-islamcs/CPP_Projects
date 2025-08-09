#include "User.h"
User::User(string _username, string _password,
    string _name, string _email)
    : username(_username), password(_password), name(_name), email(_email) { }

User::~User()
{

}

string User::getUsername() 
{ 
    return username; 
}

bool User::checkPassword(string pw)  
{ 
    return password == pw;
}

string User::getName()
{
    return name;
}