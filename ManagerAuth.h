//
// Created by Siam on 03/07/2026.
//

#ifndef ASSESMENT_1_MANAGER_AUTH_H
#define ASSESMENT_1_MANAGER_AUTH_H
#include <string>
using namespace std;

class ManagerAuth {
private:
    string managerAccessCode;

public:
    ManagerAuth();

    bool VerifyManagerAccess();
};

#endif //ASSESMENT_1_MANAGER_AUTH_H