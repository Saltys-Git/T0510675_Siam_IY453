//
// Created by Siam on 21/05/2026.
//

#include "Screen.h"
#include "ShowtimeGenerator.h"

Screen::Screen() {
    id = 0;
    seatCapacity = 0;
    seatBooked = 0;
    screenFacility = STANDARD;
}

Screen::Screen(int screenId, int screenSeatCapacity, int screenSeatBooked, Movie screenMovieShowing,
               ScreenFacility screenScreenFacility, string screenStartDate, string screenEndDate) {
    id = screenId;
    seatCapacity = screenSeatCapacity;
    seatBooked = screenSeatBooked;
    movieShowing = screenMovieShowing;
    screenFacility = screenScreenFacility;
    startDate = screenStartDate;
    endDate = screenEndDate;
}

int Screen::GetId() {
    return id;
}

int Screen::GetSeatCapacity() {
    return seatCapacity;
}

int Screen::GetSeatBooked() {
    return seatBooked;
}

Movie Screen::GetMovieShowing() {
    return movieShowing;
}

void Screen::ShowScreenInformation() {
    cout << endl << "Screen Information:" << endl;
    cout << "Movie: " << movieShowing.GetTitle() << endl;
    cout << "Seats available: " << (seatCapacity - seatBooked) << endl;
    cout << "Show time: " << startDate << " - " << endDate << endl;
}

bool Screen::BookSeat(int ticketNumber) {
    bool bookingSuccessful = false;

    if (ticketNumber + seatBooked <= seatCapacity) {
        seatBooked += ticketNumber;
        cout << ticketNumber << " seats booked." << endl;
        bookingSuccessful = true;
    } else {
        cout << "Booking failed: not enough seats available." << endl;
    }

    return bookingSuccessful;
}

// Delegates the actual time math to ShowtimeGenerator, keeping this
// function short and Screen focused on representing a screen, not doing time arithmetic.
vector<ShowTime> Screen::GenerateDailyShowtimes() {
    ShowtimeGenerator generator;
    vector<ShowTime> dailyShowtimes = generator.GenerateShowtimesForDay(movieShowing.GetRunningTime());
    return dailyShowtimes;
}