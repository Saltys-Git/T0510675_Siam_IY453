//
// Created by Siam on 29/06/2026.
//

#ifndef ASSESMENT_1_PAYMENT_H
#define ASSESMENT_1_PAYMENT_H
#include <string>
using namespace std;

class Payment {
protected:
    double amountDue;

public:
    Payment();
    Payment(double dueAmount);
    virtual ~Payment();

    // Pure virtual function forces every subclass to define its own processing logic.
    virtual bool ProcessPayment() = 0;
    virtual string GetPaymentMethodName() = 0;

    double GetAmountDue();
};

#endif //ASSESMENT_1_PAYMENT_H