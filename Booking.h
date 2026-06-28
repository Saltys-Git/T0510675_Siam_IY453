//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_BOOKING_H
#define ASSESMENT_1_BOOKING_H
#include <string>
using namespace std;

enum TicketType {
    ADULT,
    CHILD,
    STUDENT,
    SENIOR_CITIZEN
};

enum PaymentMethod {
    CASH,
    CARD
};

class Booking {
private:
    int id;
    int ticketsNumber;
    double amountPaid;
    double changeDue;
    TicketType ticketType;
    PaymentMethod paymentMethod;
    string showTime;
    string showDate;

public:
    Booking();
};

#endif //ASSESMENT_1_BOOKING_H
