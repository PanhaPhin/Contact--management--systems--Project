#pragma once
#include <iostream>
#include <fstream>
#include "Contact.cpp"
#include "Department.cpp"
#include "Payonilne.cpp"
#include "FeeContact.cpp"
#include "HourlyContact.cpp"
#include "ContactService.cpp"

using namespace std;

enum {
    ADD_CONTACT = 1,
    VIEW_CONTACT,
    EDIT_CONTACT,
    DELETE_CONTACT,
    SAVE_CONTACT,
    LOAD_CONTACT,
    EXIT_APPLICATION
};
enum {
    FEE_CONTACT = 1,
    HOURLY_CONTACT
};

class Application {
private:

public:
    void run() {
        int option;
        int choice = 0;
        int count = 0;
        string name;

        FeeContact feeContact;
        HourlyContact hourlyContact;

        ContactService contactService;



        do {
            showMenu();

            int choice = getCommand();

            switch (choice) {
            case ADD_CONTACT:
                cout << "CONTACT TYPES" << endl;
                cout << "1. Salaried Contact" << endl;
                cout << "2. Hourly Contact" << endl;
                cout << "Please enter your option: ";
                cin >> option;
                switch (option) {
                case FEE_CONTACT:
                    feeContact.getContact();
                    contactService.addContact(&feeContact);
                    break;
                case HOURLY_CONTACT:
                    hourlyContact.getContact();
                    contactService.addContact(&hourlyContact);
                    count++;
                    break;
                }
                break;
            case VIEW_CONTACT:
                cout << "Contact Info: " << endl;
                contactService.viewContact();
                cout << endl;
                break;
            case EDIT_CONTACT:
                cout << "Enter name to edit ";
                cin >> name;
                contactService.editContact(name);
                break;

            case DELETE_CONTACT:
                cout << "Enter name to delete ";
                cin >> name;
                contactService.deleteContact(name);
                break;
            case SAVE_CONTACT:
                contactService.saveContactToFile();
                cout << "Data has been saved" << endl;
                break;
            case LOAD_CONTACT:
                contactService.loadContactFromFile();
                cout << "Data has been loaded" << endl;
                break;
            }
        } while (choice != 7);

        cout << "Exit program" << endl;
    }

    void showMenu() {
        cout << "WELCOME TO CONTACT MANAGEMENT SYSTEM 1.0" << endl;
        cout << "MAIN MENU" << endl;
        cout << "1. ADD CONTACT" << endl;
        cout << "2. VIEW CONTACT" << endl;
        cout << "3. EDIT CONTACT" << endl;
        cout << "4. DELETE CONTACT" << endl;
        cout << "5. SAVE CONTACT TO FILE" << endl;
        cout << "6. LOAD CONTACT FROM FILE" << endl;
        cout << "7. EXIT PROGRAM" << endl;
    }

    int getCommand() {
        int choice;
        cout << "Please enter your choice: ";
        cin >> choice;
        while (!isLegal(choice)) {
            cout << "Invalid choice, please enter again(1-7)" << endl;
            showMenu();
            cin >> choice;
        }
        return choice;
    }

    bool isLegal(int c) {
        return ((c == 1) || (c == 2) || (c == 3) || (c == 4) || (c == 5) | (c == 6) | (c == 7));
    }


};
