#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "Booking.h"

int main() {
    Movie testMovie(1, "Test Film", "A test description", "Action", "Actor Name",
                     "Studio", 120, "2026-01-01");
    testMovie.DisplayMovieInformation();

    Screen testScreen(1, 150, 0, testMovie, IMAX, "10:00", "12:00");
    testScreen.ShowScreenInformation();
    testScreen.BookSeat(50);

    Booking testBooking;

    return 0;
}