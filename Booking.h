//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_BOOKING_H
#define ASSESMENT_1_BOOKING_H
#include <string>

using namespace std;

enum ticketTypeEnum {
    ADULT,
    CHILD,
    STUDENT,
    SENIOR_CITIZEN
};

enum paymentMethodEnum {
    CASH,
    CARD
};

class Booking {
private:
    int id, ticketsNumber, paid, changes;
    ticketTypeEnum ticketType;
    paymentMethodEnum paymentMethod;
    string time, date, cardNumber, cardCVC, cardExpirationDate;
public:
    Booking();
    
};


#endif //ASSESMENT_1_BOOKING_H
