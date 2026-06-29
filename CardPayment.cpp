//
// Created by Siam on 29/06/2026.
//

#include "CardPayment.h"


CardPayment::CardPayment(double dueAmount) : Payment(dueAmount) {
}

// Basic validation only: correct lengths for card number, CVC and expiry format.
// None of these values are saved anywhere after this function ends.
bool CardPayment::ProcessPayment(string cardNumber, string cardCvc, string cardExpiryDate) {
    bool paymentSuccessful = false;

    if (cardNumber.length() == 16 && cardCvc.length() == 3 && cardExpiryDate.length() == 5) {
        paymentSuccessful = true;
    } else {
        cout << "Payment failed: card details are invalid." << endl;
    }

    return paymentSuccessful;
}

// Required to satisfy the pure virtual function from Payment, but card payments
// must always go through the detailed overload above, so this version fails safely.
bool CardPayment::ProcessPayment() {
    cout << "Card payment requires card details. Use the other ProcessPayment method." << endl;
    return false;
}

string CardPayment::GetPaymentMethodName() {
    return "Card";
}