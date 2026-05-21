//
// Created by Siam on 21/05/2026.
//

#include "Screen.h"


Screen::Screen(int tempId, int tempSeatCapacity, int tempSeatBooked, Movie tempMovieShowing, screenFacilityEnum tempScreenFacility, string tempStartDate, string tempEndDate) {
    id = tempId;
    seatCapacity = tempSeatCapacity;
    seatBooked = tempSeatBooked;
    movieShowing = tempMovieShowing;
    startDate = tempStartDate;
    endDate = tempEndDate;
}


void Screen::showScreenInformation() {
    cout << endl << "Screen Information:" << endl;
    cout << endl;
    cout << "Movie:" << movieShowing.getTitle() << endl;
    cout << "Seats available" << seatCapacity-seatBooked << endl;
    cout << "Show time" << startDate << " - " << endDate << endl;
}


void Screen::addShows() {
    Screen()
}


void Screen::bookSeat(int ticketNumber) {
    seatBooked += ticketNumber;
    cout << ticketNumber << " seats booked." << endl;
}
