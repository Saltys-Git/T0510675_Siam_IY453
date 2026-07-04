//
// Created by Siam on 03/07/2026.
//

#include "ManagerAuth.h"
#include <iostream>

ManagerAuth::ManagerAuth() {
    managerAccessCode = "1234";
}

bool ManagerAuth::VerifyManagerAccess() {
    string enteredCode;
    cout << "Enter manager access code: ";
    cin >> enteredCode;

    bool accessGranted = false;
    if (enteredCode == managerAccessCode) {
        accessGranted = true;
    } else {
        cout << "Incorrect code. Returning to main menu." << endl;
    }

    return accessGranted;
}