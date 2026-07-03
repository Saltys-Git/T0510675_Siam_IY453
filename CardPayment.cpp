//
// Created by Siam on 29/06/2026.
//

#include "CardPayment.h"


CardPayment::CardPayment(double dueAmount) : Payment(dueAmount) {
}

bool CardPayment::ProcessPayment(string cardNumber, string cardCvc, string cardExpiryDate) {
    bool paymentSuccessful = false;

    if (cardNumber.length() == 16 && cardCvc.length() == 3 && cardExpiryDate.length() == 5) {
        paymentSuccessful = true;
    } else {
        cout << "Payment failed: card details are invalid." << endl;
    }

    return paymentSuccessful;
}

bool CardPayment::ProcessPayment() {
    cout << "Card payment requires card details. Use the other ProcessPayment method." << endl;
    return false;
}

string CardPayment::GetPaymentMethodName() {
    return "Card";
}