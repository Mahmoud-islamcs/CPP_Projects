#pragma once
#include <string>
#include <vector>
#include "Book.h"
using namespace std;
class User
{
private:
	string name;
	int memberID;
	vector<string>borrowed_books;
public:
	void displayMemberInfo();
	void borrowBook(string isbn);
	void returnBook(string isbn);
};

