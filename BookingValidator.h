//
// Created by Siam on 02/07/2026.
//

#ifndef ASSESMENT_1_BOOKING_VALIDATOR_H
#define ASSESMENT_1_BOOKING_VALIDATOR_H
#include <string>
#include "Screen.h"
using namespace std;

class BookingValidator {
public:
    BookingValidator();

    bool IsWithinSeatCapacity(Screen screen, int ticketsRequested);
    bool IsDateWithinCurrentWeek(string requestedDate, string weekStartDate, string weekEndDate);
    bool ConvertDateToComparableNumber(string date, int& comparableNumber);
};

#endif //ASSESMENT_1_BOOKING_VALIDATOR_H