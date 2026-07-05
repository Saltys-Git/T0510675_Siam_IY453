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
    bool codeEntered = false;

    while (codeEntered == false) {
        cout << "Enter manager access code: ";
        getline(cin, enteredCode);

        if (enteredCode.empty() == true) {
            cout << "Code cannot be empty. Please try again." << endl;
        } else {
            codeEntered = true;
        }
    }

    bool accessGranted = false;
    if (enteredCode == managerAccessCode) {
        accessGranted = true;
    } else {
        cout << "Incorrect code. Returning to main menu." << endl;
    }

    return accessGranted;
}