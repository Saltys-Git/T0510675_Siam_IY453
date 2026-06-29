//
// Created by Siam on 29/06/2026.
//

#include "AdultTicket.h"

AdultTicket::AdultTicket(int numberOfTickets) : Ticket(numberOfTickets) {
}

double AdultTicket::GetUnitPrice() {
    return 9.50;
}

string AdultTicket::GetTicketTypeName() {
    return "Adult";
}