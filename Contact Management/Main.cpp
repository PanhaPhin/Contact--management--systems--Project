#include <iostream>
#include "Application.cpp"
#include "Login.cpp"


using namespace std;


int main() {

    Login l1;
    while (true)
    {
        string username, password;
        int ch;
        int role;
        cout << " ********  Welcome to Conatact Management System *********";
        cout << "\n 1. Login \n 2. Register \n 3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << " Username : ";
            cin >> username;
            cout << " Password : ";
            cin >> password;
            role = l1.login(username, password);
            if (role == 1) {
                Application application;
                application.run();
            }
            else if (role == 2) {
                Application application;
                application.run();
            }
            else {

            }

            break;
        case 2:
            l1.Register();
            break;
        case 3:
            exit(1);
        }

    }

    return 0;
}