#pragma once

#include <iostream>
#include "Contact.cpp"
using namespace std;

class DepartmentMediaContacts {
private:
    string name;
    Contact* contact; //aggregation

    //Employee* employees=new Employee[20];

public:
    DepartmentMediaContacts() :name("unknown"), contact(nullptr) {}
    DepartmentMediaContacts(string name, Contact* contact) :name(name), contact(contact) {}

    //    ~Department(){
    //        cout<<"Destroyed department"<<endl;
    //    }
        //setter and getter
    void setContact(Contact* contact) {
        if (this->contact != nullptr) {
            delete contact;
        }
        this->contact = contact;
    }
    void setContact(string name, Address address) {
        if (this->contact != nullptr) {
            delete contact;
        }
        this->contact = new Contact(name, address);
    }

    void display() {
        cout << "Name:" << name << endl;
        contact->display();

    }

};

