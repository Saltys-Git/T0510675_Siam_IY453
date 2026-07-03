//
// Created by Siam on 03/07/2026.
//

#include "ManagerAuth.h"
#include <iostream>

// A single shared access code is used here rather than full user accounts,
// since the brief excludes login/password security as in-scope for this project.
// This still satisfies the tutor's request to separate manager-only actions.
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