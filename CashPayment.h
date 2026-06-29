//
// Created by Siam on 29/06/2026.
//

#ifndef ASSESMENT_1_CASH_PAYMENT_H
#define ASSESMENT_1_CASH_PAYMENT_H
#include <iostream>
#include "Payment.h"

class CashPayment : public Payment {
private:
    double cashGiven;
    double changeGiven;

public:
    CashPayment(double dueAmount, double cashReceived);

    bool ProcessPayment() override;
    string GetPaymentMethodName() override;
    double GetChangeGiven();
};

#endif //ASSESMENT_1_CASH_PAYMENT_H