#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Login
{

private:
    string username;
    string password;
    int role;
public:
    void Register()
    {
        ofstream fs("logindata.dat", ios::app);
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Press 1. Contact 2. Administrator" << endl;
        cin >> role;
        fs << username << " " << password << " " << role << " ";
        fs.close();
    }
    int login(string username, string password)
    {
        ifstream fs("logindata.dat", ios::in);
        while (!fs.eof())
        {
            fs >> username >> password >> role;

            if (username.compare(this->username) == 0 && password.compare(this->password) == 0)
            {
                return role;
            }

        }
        fs.close();
        return -1;
    }
};
