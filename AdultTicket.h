//
// Created by Siam on 29/06/2026.
//

#ifndef ASSESMENT_1_ADULT_TICKET_H
#define ASSESMENT_1_ADULT_TICKET_H
#include "Ticket.h"

class AdultTicket : public Ticket {
public:
    AdultTicket(int numberOfTickets);

    double GetUnitPrice() override;
    string GetTicketTypeName() override;
};

#endif //ASSESMENT_1_ADULT_TICKET_H