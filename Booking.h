//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_BOOKING_H
#define ASSESMENT_1_BOOKING_H
#include <string>
#include "Ticket.h"
#include "Payment.h"
using namespace std;

class Booking {
private:
    int id;
    string customerName;
    string movieTitle;
    int screenId;
    string showDate;
    string showTime;
    Ticket* ticket;
    Payment* payment;

public:
    Booking(int bookingId, string bookingCustomerName, string bookingMovieTitle,
            int bookingScreenId, string bookingShowDate, string bookingShowTime,
            Ticket* bookingTicket, Payment* bookingPayment);
    ~Booking();

    double CalculateTotalCost();
    void DisplayBookingInformation();

    int GetId();
    string GetCustomerName();
    string GetMovieTitle();
    string GetShowDate();
};

#endif //ASSESMENT_1_BOOKING_H