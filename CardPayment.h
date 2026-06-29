//
// Created by Siam on 29/06/2026.
//

#ifndef ASSESMENT_1_CARD_PAYMENT_H
#define ASSESMENT_1_CARD_PAYMENT_H
#include <iostream>
#include "Payment.h"

class CardPayment : public Payment {
public:
    CardPayment(double dueAmount);

    // Card details are passed in here only, checked, then discarded.
    // They are never assigned to a class field, so nothing card-related is stored.
    bool ProcessPayment(string cardNumber, string cardCvc, string cardExpiryDate);
    bool ProcessPayment() override;
    string GetPaymentMethodName() override;
};

#endif //ASSESMENT_1_CARD_PAYMENT_H