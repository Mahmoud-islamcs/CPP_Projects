#include "Ticket.h"
#include<iostream>

Ticket::Ticket(string _ticketID, string _userID, string _busID, int _seatNumber)
	:ticketID(_ticketID),userID(_userID),busID(_busID),seatNumber(_seatNumber){ }

void Ticket::displayTicketInfo()
{
    cout << endl << "--- Ticket Info ---" << endl;
    cout << "Ticket ID : " << ticketID << endl;
    cout << "User ID   : " << userID << endl;
    cout << "Bus ID    : " << busID << endl;
    cout << "Seat No.  : " << seatNumber << endl;
}

string Ticket::getTicketID()
{
    return ticketID;
}

string Ticket::getUserID()
{
    return userID;
}
	
