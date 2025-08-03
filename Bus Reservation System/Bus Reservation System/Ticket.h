#pragma once
#include <string>

using namespace std;

class Ticket
{
private:
    string ticketID, userID, busID;
    int seatNumber;
public:
    Ticket(string _ticketID, string _userID, string _busID, int _seatNumber);

    void displayTicketInfo();

    string getTicketID() ;
    string getUserID() ;
    string getBusID() ;
    int getSeatNumber() ;
};

    