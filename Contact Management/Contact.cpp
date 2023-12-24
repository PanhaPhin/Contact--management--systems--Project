// Contact Managaement Systems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once

#include <iostream>
#include <fstream>
#include "Address.cpp"
using namespace std;

//concrete class
class Contact {
private:
    //data memb*ers
    string name;
    Address address; //composition

public:
    //constructors
    Contact() :name("unknown") {}
    Contact(string name) :name(name) {}
    Contact(string name, Address address) :name(name), address(address) {}
    Contact(string name, string street, string city) :name(name), address(street, city) {}

    ~Contact() {

    }
    //setter and getter methods
    Address getAddress() {
        return address;
    }
    void setAddress(Address address) {
        this->address = address;
    }
    void setAddress(string street, string city) {
        address.setStreet(street);
        address.setCity(city);
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    //method members
    virtual void display() {
        cout << "Name:" << name;
        address.display();
    }

    virtual void getContact() {
        cout << "Enter name: ";
        cin >> name;
        address.getAddress();

    }



};
