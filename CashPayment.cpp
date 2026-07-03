//
// Created by Siam on 29/06/2026.
//

#include "CashPayment.h"

CashPayment::CashPayment(double dueAmount, double cashReceived) : Payment(dueAmount) {
    cashGiven = cashReceived;
    changeGiven = 0.0;
}

bool CashPayment::ProcessPayment() {
    bool paymentSuccessful = false;

    if (cashGiven >= amountDue) {
        changeGiven = cashGiven - amountDue;
        paymentSuccessful = true;
    } else {
        cout << "Payment failed: cash given is less than amount due." << endl;
    }

    return paymentSuccessful;
}

string CashPayment::GetPaymentMethodName() {
    return "Cash";
}

double CashPayment::GetChangeGiven() {
    return changeGiven;
}