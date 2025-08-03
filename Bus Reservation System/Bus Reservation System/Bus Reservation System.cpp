#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "Bus.h"
#include "User.h"

#include "Ticket.h"

vector<Bus> buses;
vector<User> users;
vector<Ticket> tickets;

void addDummyData() {
    buses.push_back(Bus("BUS100", "Cairo", "Alex", "08:00 AM"));
    buses.push_back(Bus("BUS200", "Minia", "Cairo", "10:30 AM"));
    buses.push_back(Bus("BUS300", "Assiut", "Sohag", "06:45 PM"));
}
User* loginUser() {
    string username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    for (User& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            cout << "Login successful. Welcome " << user.getName() << "!" << endl;
            return &user;
        }
    }
    cout << "Invalid credentials." << endl;
    return nullptr;
}
Bus* findBusByID(string& busID) {
    for (Bus& bus : buses) {
        if (bus.getBusID() == busID)
            return &bus;
    }
    return nullptr;
}
void showAvailableBuses() {
    for (Bus& bus : buses) {
        bus.displayBusDetails();
        cout << "-----------------------" << endl;
    }
}
void bookTicket(User* user) {
    string busID;
    int seatNumber;

    showAvailableBuses();

    cout << "Enter Bus ID to book: "; cin >> busID;
    Bus* bus = findBusByID(busID);

    if (!bus) {
        cout << "Bus not found!" << endl;
        return;
    }

    cout << "Enter seat number (1-50): ";
    cin >> seatNumber;

    if (bus->bookSeat(seatNumber)) {
        ostringstream oss;
        oss << "T" << tickets.size() + 1;
        string ticketID = oss.str();

        tickets.push_back(Ticket(ticketID, user->getId(), busID, seatNumber));
        cout << "Ticket booked successfully! Ticket ID: " << ticketID << endl;
    }
    else {
        cout << "Seat already booked or invalid number." << endl;
    }
}

void cancelTicket(User* user) {
    string ticketID;
    cout << "Enter Ticket ID to cancel: ";
    cin >> ticketID;

    auto it = std::find_if(tickets.begin(), tickets.end(), [&](Ticket& t) {
        return t.getTicketID() == ticketID && t.getUserID() == user->getId();
        });

    if (it != tickets.end()) {
        Bus* bus = findBusByID(it->getBusID());
        if (bus) {
            bus->cancelSeat(it->getSeatNumber());
            tickets.erase(it);
            cout << "Ticket cancelled successfully." << endl;
        }
    }
    else {
        cout << "Ticket not found or not yours." << endl;
    }
}

void viewUserTickets(User* user) {
    for (Ticket& ticket : tickets) {
        if (ticket.getUserID() == user->getId()) {
            ticket.displayTicketInfo();
            std::cout << "--------------------------\n";
        }
    }
}
int main() {
    addDummyData();
    int choice;
    do {
        cout << endl << "=== Bus Reservation System ===" << endl;
        cout << "1. Register" << endl << "2. Login" << endl << "0. Exit";
        cout << "Choice :";
        cin >> choice;

        if (choice == 1) {
            string id, name, phone, username, password, email, gender;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Phone: "; getline(cin, phone);
            cout << "Enter E-mail: "; cin >> email;
            cout << "Enter Gender: "; cin >> gender;
            cout << "Choose Username: "; getline(cin, username);
            cout << "Choose Password: "; getline(cin, password);

            users.push_back(User(id, name, email, gender, phone, username, password));
            cout << "Registration successful!" << endl;
        }
        else if (choice == 2) {
            User* loggedUser = loginUser();
            if (loggedUser) {
                int userChoice;
                do {
                    cout << endl << "--- User Menu ---" << endl;
                    cout << "1. Show Available Buses" << endl;
                    cout << "2. Book Ticket" << endl;
                    cout << "3. Cancel Ticket" << endl;
                    cout << "4. View My Tickets" << endl;
                    cout << "0. Logout" << endl;
                    cout << "Choice :";
                    cin >> userChoice;

                    if (userChoice == 1) 
                        showAvailableBuses();
                    else if (userChoice == 2) 
                        bookTicket(loggedUser);
                    else if (userChoice == 3) 
                        cancelTicket(loggedUser);
                    else if (userChoice == 4) 
                        viewUserTickets(loggedUser);
                } while (userChoice != 0);
            }
        }
    } while (choice != 0);

    return 0;
}