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

int main() {
    MovieManager movieManager;
    cout << "All available films:" << endl;
    movieManager.DisplayAllMovies();

    Movie oceanDrift = *movieManager.FindMovieByTitle("Ocean Drift");
    Screen screenTwo(2, 150, 148, oceanDrift, IMAX, "18:30", "20:38");

    BookingValidator validator;

    cout << endl << "Testing seat capacity check:" << endl;
    bool capacityOk = validator.IsWithinSeatCapacity(screenTwo, 5);
    cout << "5 tickets allowed? " << capacityOk << endl;

    cout << endl << "Testing current week check:" << endl;
    bool dateOk = validator.IsDateWithinCurrentWeek("2026-07-09", "2026-07-09", "2026-07-15");
    cout << "Date within week? " << dateOk << endl;

    bool dateTooLate = validator.IsDateWithinCurrentWeek("2026-07-20", "2026-07-09", "2026-07-15");
    cout << "Later date within week? " << dateTooLate << endl;

    return 0;
}