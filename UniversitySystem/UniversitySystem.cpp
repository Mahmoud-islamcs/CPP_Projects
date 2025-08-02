#include <iostream>
#include <vector>
#include "Student.h"
#include "Professor.h"
#include "AdminStaff.h"

#define endl '\n'

using namespace std;
int main() {
    vector<Student> students;
    vector<Professor> professors;
    vector<AdminStaff> admins;

    int choice;
    while (true) {
        cout << "===== University Management System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Professor" << endl;
        cout << "3. Add Admin Staff" << endl;
        cout << "4. Display All People" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string id, name, email, gender, phone, dept;
            int level;
            cout << "Enter your ID : "; cin >> id;
            cout << "Enter your Name : "; cin >> name;
            cout << "Enter your Email : "; cin >> email;
            cout << "Enter your Gender : "; cin >> gender;
            cout << "Enter your Phone : "; cin >> phone;
            cout << "Enter your Department : "; cin >> dept;
            cout << "Enter your Level : "; cin >> level;
            students.push_back(Student(id, name, email, gender, phone, dept, level));
            cout << "✅ Student added..." << endl << endl;

        }
        else if (choice == 2) {
            string id, name, email, gender, phone, spec;
            int years;
            cout << "Enter your ID : "; cin >> id;
            cout << "Enter your Name : "; cin >> name;
            cout << "Enter your Email : "; cin >> email;
            cout << "Enter your Gender : "; cin >> gender; 
            cout << "Enter your Phone : "; cin >> phone; 
            cout << "Enter your Specialization : "; cin >> spec; 
            cout << "Enter your Years : "; cin >> years; 
            professors.push_back(Professor(id, name, email, gender, phone, spec, years));
            cout << "✅ Professor added..." << endl << endl;

        }
        else if (choice == 3) {
            string id, name, email, gender, phone, pos;
            cout << "Enter your ID : "; cin >> id;
            cout << "Enter your Name : "; cin >> name;
            cout << "Enter your Email : "; cin >> email;
            cout << "Enter your Gender : "; cin >> gender;
            cout << "Enter your Phone : "; cin >> phone;
            cout << "Enter your Position : "; cin >> pos;
            admins.push_back(AdminStaff(id, name, email, gender, phone, pos));
            cout << "✅ Admin staff added..." << endl << endl;

        }
        else if (choice == 4) {
            cout << endl << "===== Students =====" << endl;
            for (const Student& s : students)
                s.displayDetails();

            cout << endl << "===== Professors =====" << endl;
            for (const Professor& p : professors)
                p.displayDetails();

            cout << endl << "===== Admins =====" << endl;
            for (const AdminStaff& a : admins)
                a.displayDetails();

        }
        else if (choice == 5) {
            cout << "👋 Exiting program. Goodbye!" << endl;
            break;

        }
        else {
            cout << "❌ Invalid option. Try again!" << endl;
        }
    }

    return 0;
}