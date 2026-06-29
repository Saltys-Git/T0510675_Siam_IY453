//
// Created by Siam on 29/06/2026.
//

#include "StudentTicket.h"

StudentTicket::StudentTicket(int numberOfTickets) : Ticket(numberOfTickets) {
}

double StudentTicket::GetUnitPrice() {
    return 7.00;
}

string StudentTicket::GetTicketTypeName() {
    return "Student";
}