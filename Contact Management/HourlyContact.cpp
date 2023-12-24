
#pragma once

#include <iostream>
#include "Contact.cpp"
#include "Payonilne.cpp"
using namespace std;

class HourlyContact : public Contact, public Payonilne {
private:
    double rate;
    double hour;
public:
    HourlyContact() :Contact(), rate(0), hour(0) {}
    HourlyContact(string name, Address address, double rate, double hour) :Contact(name, address), rate(rate), hour(hour) {}


    double getPayonilne() {
        return rate * hour;
    }

    void display() {
        Contact::display();
        cout << " Rate:" << rate << " Hour:" << hour;
    }
    void getContact() {
        Contact::getContact();
        cout << "Enter rate: ";
        cin >> rate;
        cout << "Enter hour: ";
        cin >> hour;
    }
};
