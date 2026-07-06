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
               ScreenFacility screenScreenFacility) {
    id = screenId;
    seatCapacity = screenSeatCapacity;
    seatBooked = screenSeatBooked;
    movieShowing = screenMovieShowing;
    screenFacility = screenScreenFacility;
}

int Screen::GetId() {
    return id;
}

void Screen::SetId(int newId) {
    id = newId;
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

string Screen::GetFacilityName() {
    string facilityName;

    if (screenFacility == STANDARD) {
        facilityName = "Standard";
    } else if (screenFacility == IMAX) {
        facilityName = "IMAX";
    } else if (screenFacility == COUPLE_SEAT) {
        facilityName = "Couple Seat";
    } else {
        facilityName = "Seat Service";
    }

    return facilityName;
}

void Screen::ShowScreenInformation() {
    cout << endl << "Screen ID: " << id << endl;
    cout << "Facility: " << GetFacilityName() << endl;

    if (movieShowing.GetTitle().empty() == true) {
        cout << "Movie: No movie currently assigned" << endl;
    } else {
        cout << "Movie: " << movieShowing.GetTitle() << endl;
    }

    cout << "Total Capacity: " << seatCapacity << endl;
    cout << "Seats Booked: " << seatBooked << endl;
    cout << "Seats Available: " << (seatCapacity - seatBooked) << endl;
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

vector<ShowTime> Screen::GenerateDailyShowtimes() {
    ShowtimeGenerator generator;
    vector<ShowTime> dailyShowtimes = generator.GenerateShowtimesForDay(movieShowing.GetRunningTime());
    return dailyShowtimes;
}


ScreenFacility Screen::GetScreenFacility() {
    return screenFacility;
}

void Screen::SetMovieShowing(Movie newMovie) {
    movieShowing = newMovie;
}