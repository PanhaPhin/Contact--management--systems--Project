#pragma once

#include <iostream>
#include "Contact.cpp"
#include "DynamicArray.cpp"
#include <vector>


using namespace std;

//business logics
class ContactService {
private:
    //dynamic array
    vector<Contact*> contacts;
public:

    ContactService() {
        //loadEmployeeFromFile();
    }
    ~ContactService() {
        vector<Contact*>::iterator it;
        for (it = contacts.begin(); it != contacts.end(); it++) {
            delete* it;
        }
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void viewContact() {
        vector<Contact*>::iterator it;
        for (it = contacts.begin(); it != contacts.end(); it++) {
            (*it)->display();
            cout << endl;
        }
    }

    void editContact(string name) {
        vector<Contact*>::iterator it;
        for (it = contacts.begin(); it != contacts.end(); it++) {
            if ((*it)->getName().compare(name)) {
                (*it)->getContact();
                break;
            }

        }

    }
    void deleteContact(string name) {
        vector<Contact*>::iterator it;
        for (it = contacts.begin(); it != contacts.end(); it++) {
            if ((*it)->getName().compare(name) == 0) {
                contacts.erase(it);
                break;
            }
        }
    }

    Contact* getContactByName(string name) {
        vector<Contact*>::iterator it;
        for (it = contacts.begin(); it != contacts.end(); it++) {
            if ((*it)->getName().compare(name) == 0) {
                return *it;
            }
        }
        return nullptr;
    }

    vector<Contact*> getAllContacts() {
        return contacts;
    }



    //Read and write object data into file
    void saveContactToFile() {
        ofstream outputFile;
        outputFile.open("contacts.bin", ios::out | ios::binary | ios::trunc);
        if (!outputFile) {
            cout << "Error in creating file...\n";
            exit(1);
        }
        else {
            vector<Contact*>::iterator it;
            for (it = contacts.begin(); it != contacts.end(); it++) {
                outputFile.write((char*)&it, sizeof(it));
                (*it)->display();
            }
        }

        outputFile.close();
    }
    void loadContactFromFile() {
        Contact contact;
        ifstream inputFile;
        inputFile.open("contacts.bin", ios::in | ios::binary);
        if (!inputFile) {
            cout << "Error in opening file...\n";
            exit(1);
        }
        else {
            while (inputFile.read((char*)(&contact), sizeof(contact))) {
                contacts.push_back(&contact);
                contact.display();
                cout << "H1" << endl;
            }
        }


        cout << "H2" << endl;
        inputFile.close();
    }


};
