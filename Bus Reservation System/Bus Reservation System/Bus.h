#pragma once
#include <string>
using namespace std;
class Bus
{
private:
	string  busID, source, destination, departureTime;
	bool seats[50];
public:
	Bus(string _busID, string _source, string _destination, string _departureTime);
	void displayBusDetails() ;

	bool bookSeat(int seatNumber);
	bool cancelSeat(int seatNumber);
	bool isSeatAvailable(int seatNumber) ;

	string getBusID() ;
};

