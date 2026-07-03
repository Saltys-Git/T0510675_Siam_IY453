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

    bool ProcessPayment(string cardNumber, string cardCvc, string cardExpiryDate);
    bool ProcessPayment() override;
    string GetPaymentMethodName() override;
};

#endif //ASSESMENT_1_CARD_PAYMENT_H