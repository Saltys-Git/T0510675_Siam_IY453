//
// Created by Siam on 29/06/2026.
//

#ifndef ASSESMENT_1_TICKET_H
#define ASSESMENT_1_TICKET_H
#include <string>
using namespace std;

class Ticket {
protected:
    int quantity;

public:
    Ticket();
    Ticket(int numberOfTickets);
    virtual ~Ticket();

    virtual double GetUnitPrice() = 0;
    virtual string GetTicketTypeName() = 0;

    double CalculateTotalPrice();
    int GetQuantity();
};

#endif //ASSESMENT_1_TICKET_H