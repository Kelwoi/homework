#include <iostream>
#include "VendingMachine.h"
int main()
{
    VendingMachine machine;
    int mode;

    while (true) {
        cout << "\n=== Wending machine ===\n";
        cout << "1. Admin-mode\n";
        cout << "2. user-mode\n";
        cout << "3. quit\n";
        cout << "choice: ";
        cin >> mode;

        if (mode == 1) {
            machine.adminMode();
        }
        else if (mode == 2) {
            machine.userMode();
        }
        else if (mode == 3) {
            cout << "goodbye!\n";
            break;
        }
        else {
            cout << "Wrong choice, try again.\n";
        }
    }
}


