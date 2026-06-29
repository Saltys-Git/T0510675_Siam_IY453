//
// Created by Siam on 29/06/2026.
//

#include "Payment.h"

Payment::Payment() {
    amountDue = 0.0;
}

Payment::Payment(double dueAmount) {
    amountDue = dueAmount;
}

Payment::~Payment() {
}

double Payment::GetAmountDue() {
    return amountDue;
}