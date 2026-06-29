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

    AdultTicket adultTicket(2);
    double totalDue = adultTicket.CalculateTotalPrice();
    cout << "Total due: " << totalDue << endl;

    CashPayment cashPayment(totalDue, 25.00);
    if (cashPayment.ProcessPayment() == true) {
        cout << "Cash payment successful. Change: " << cashPayment.GetChangeGiven() << endl;
    }

    CardPayment cardPayment(totalDue);
    if (cardPayment.ProcessPayment("1234567812345678", "123", "12/28") == true) {
        cout << "Card payment successful." << endl;
    }

    return 0;
}