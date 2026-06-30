#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "Booking.h"
#include "MovieManager.h"
#include "Ticket.h"
#include "AdultTicket.h"
#include "ChildTicket.h"
#include "StudentTicket.h"
#include "SeniorCitizenTicket.h"
#include "Payment.h"
#include "CashPayment.h"
#include "CardPayment.h"

int main() {
    MovieManager movieManager;
    cout << "All available films:" << endl;
    movieManager.DisplayAllMovies();

    Ticket* customerTicket = new AdultTicket(2);
    double amountDue = customerTicket->CalculateTotalPrice();
    Payment* customerPayment = new CashPayment(amountDue, 25.00);
    customerPayment->ProcessPayment();

    Booking firstBooking(1, "Alex Rahman", "Ocean Drift", 2, "2026-07-09", "18:30",
                          customerTicket, customerPayment);
    firstBooking.DisplayBookingInformation();

    return 0;
}