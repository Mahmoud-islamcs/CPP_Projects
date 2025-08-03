#include "Bus.h"
#include <iostream>
#include <iomanip>
#include "Ticket.h"


Bus::Bus(string _busID, string _source, string _destination, string _departureTime)
:busID(_busID),source(_source),destination(_destination),departureTime(_departureTime){ }

void Bus::displayBusDetails()
{
    cout << endl << "Bus ID: " << busID << endl;
    cout << "From: " << source << " To: " << destination << endl;
    cout << "Departure Time: " << departureTime << endl;
    cout << "Seats Availability: " << endl;

    for (int i = 0; i < 50; ++i) {
        cout << setw(2) << i + 1 << ": " << (seats[i] ? "[X]" : "[ ]") << "\t";
        if ((i + 1) % 5 == 0) 
            cout << endl;
    }
}

bool Bus::bookSeat(int seatNumber)
{
    if (seatNumber < 1 || seatNumber > 50)
        return false;
    if (seats[seatNumber - 1] == false) {
        seats[seatNumber - 1] = true;
        return true;
    }
    return false;
}

bool Bus::cancelSeat(int seatNumber)
{
    if (seatNumber < 1 || seatNumber > 50)
        return false;
    if (seats[seatNumber - 1] == true) {
        seats[seatNumber - 1] = false;
        return true;
    }
    return false;
}

bool Bus::isSeatAvailable(int seatNumber)
{
    if (seatNumber < 1 || seatNumber > 50)
        return false;
    return !seats[seatNumber - 1];
}

string Bus::getBusID()
{
    return busID;
}

int Ticket::getSeatNumber()
{
    return seatNumber;
}
