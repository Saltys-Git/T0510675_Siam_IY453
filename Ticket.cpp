//
// Created by Siam on 29/06/2026.
//

#include "Ticket.h"

Ticket::Ticket() {
    quantity = 0;
}

Ticket::Ticket(int numberOfTickets) {
    quantity = numberOfTickets;
}

Ticket::~Ticket() {
}

double Ticket::CalculateTotalPrice() {
    double totalPrice = quantity * GetUnitPrice();
    return totalPrice;
}

int Ticket::GetQuantity() {
    return quantity;
}
