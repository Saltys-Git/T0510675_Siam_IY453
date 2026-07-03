//
// Created by Siam on 02/07/2026.
//

#include "BookingValidator.h"
#include <iostream>

BookingValidator::BookingValidator() {
}

// Checks the screen's own booked/capacity numbers
bool BookingValidator::IsWithinSeatCapacity(Screen screen, int ticketsRequested) {
    bool withinCapacity = false;
    int seatsRemaining = screen.GetSeatCapacity() - screen.GetSeatBooked();

    if (ticketsRequested <= seatsRemaining) {
        withinCapacity = true;
    } else {
        cout << "Booking rejected: only " << seatsRemaining << " seats remaining." << endl;
    }

    return withinCapacity;
}

// expects dates in YYYY-MM-DD format.
bool BookingValidator::ConvertDateToComparableNumber(string date, int& comparableNumber) {
    bool conversionSuccessful = false;

    if (date.length() == 10) {
        string yearPart = date.substr(0, 4);
        string monthPart = date.substr(5, 2);
        string dayPart = date.substr(8, 2);
        comparableNumber = (stoi(yearPart) * 10000) + (stoi(monthPart) * 100) + stoi(dayPart);
        conversionSuccessful = true;
    } else {
        cout << "Date format invalid. Expected YYYY-MM-DD." << endl;
    }

    return conversionSuccessful;
}

// The current week's start (Thursday) and end (Wednesday) dates are passed in by the caller, so this function only handles the comparison logic itself.
bool BookingValidator::IsDateWithinCurrentWeek(string requestedDate, string weekStartDate, string weekEndDate) {
    bool withinCurrentWeek = false;
    int requestedNumber = 0;
    int startNumber = 0;
    int endNumber = 0;

    bool allDatesValid = ConvertDateToComparableNumber(requestedDate, requestedNumber);
    if (allDatesValid == true) {
        allDatesValid = ConvertDateToComparableNumber(weekStartDate, startNumber);
    }
    if (allDatesValid == true) {
        allDatesValid = ConvertDateToComparableNumber(weekEndDate, endNumber);
    }

    if (allDatesValid == true && requestedNumber >= startNumber && requestedNumber <= endNumber) {
        withinCurrentWeek = true;
    } else if (allDatesValid == true) {
        cout << "Booking rejected: date is outside the current booking week." << endl;
    }

    return withinCurrentWeek;
}