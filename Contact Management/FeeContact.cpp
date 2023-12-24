
#pragma once

#include <iostream>
#include "Contact.cpp"
#include "Payonilne.cpp"
using namespace std;

class FeeContact : public Contact, Payonilne {
private:
    double fee;
public:
    FeeContact() :Contact(), fee(0) {}
    FeeContact(string name, Address address, double fee) :Contact(name, address), fee(fee) {}

    //setter and getter
    double getFee() {
        return fee;
    }

    double getPayonilne() {
        return fee;
    }

    void display() {
        Contact::display();
        cout << " Fee:" << fee;
    }
    void getContact() {
        Contact::getContact();
        cout << "Enter Contact fee: ";
        cin >> fee;
    }
};

