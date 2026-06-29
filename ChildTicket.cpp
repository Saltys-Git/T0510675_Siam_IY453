//
// Created by Siam on 29/06/2026.
//

#include "ChildTicket.h"

ChildTicket::ChildTicket(int numberOfTickets) : Ticket(numberOfTickets) {
}

double ChildTicket::GetUnitPrice() {
    return 5.50;
}

string ChildTicket::GetTicketTypeName() {
    return "Child";
}