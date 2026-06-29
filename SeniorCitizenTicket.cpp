//
// Created by Siam on 29/06/2026.
//

#include "SeniorCitizenTicket.h"

SeniorCitizenTicket::SeniorCitizenTicket(int numberOfTickets) : Ticket(numberOfTickets) {
}

double SeniorCitizenTicket::GetUnitPrice() {
    return 6.50;
}

string SeniorCitizenTicket::GetTicketTypeName() {
    return "Senior Citizen";
}