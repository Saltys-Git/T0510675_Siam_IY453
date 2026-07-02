#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "Booking.h"
#include "MovieManager.h"
#include "Ticket.h"
#include "AdultTicket.h"
#include "Payment.h"
#include "CashPayment.h"
#include "BookingValidator.h"
#include "BookingManager.h"

int main() {
    MovieManager movieManager;
    BookingManager bookingManager;

    Ticket* ticketOne = new AdultTicket(2);
    Payment* paymentOne = new CashPayment(ticketOne->CalculateTotalPrice(), 25.00);
    paymentOne->ProcessPayment();
    Booking bookingOne(1, "Alex Rahman", "Ocean Drift", 2, "2026-07-09", "18:30",
                        ticketOne, paymentOne);
    bookingOne.DisplayBookingInformation();
    bookingManager.SaveBookingToFile(bookingOne);

    Ticket* ticketTwo = new AdultTicket(1);
    Payment* paymentTwo = new CashPayment(ticketTwo->CalculateTotalPrice(), 10.00);
    paymentTwo->ProcessPayment();
    Booking bookingTwo(2, "Priya Singh", "Starlight Diner", 3, "2026-07-10", "20:00",
                        ticketTwo, paymentTwo);
    bookingManager.SaveBookingToFile(bookingTwo);

    cout << endl << "All bookings in file:" << endl;
    bookingManager.DisplayAllBookingsFromFile();

    cout << endl << "Search by customer name 'Priya Singh':" << endl;
    bookingManager.SearchBookingsByCustomerName("Priya Singh");

    cout << endl << "Search by film title 'Ocean Drift':" << endl;
    bookingManager.SearchBookingsByMovieTitle("Ocean Drift");

    cout << endl << "Search by date '2026-07-10':" << endl;
    bookingManager.SearchBookingsByDate("2026-07-10");

    return 0;
}