//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_SCREEN_H
#define ASSESMENT_1_SCREEN_H
#include "Movie.h"


//https://www.geeksforgeeks.org/cpp/enumeration-in-cpp/ (2026)
enum screenFacilityEnum
{
    STANDARD,
    IMAX,
    COUPLE_SEAT,
    SEAT_SERVICE
};

class Screen {
    private:
    int id, seatCapacity, seatBooked;
    Movie movieShowing;
    screenFacilityEnum screenFacility;
    string startDate, endDate;
    public:
    Screen();
    Screen(int tempId,int tempSeatCapacity, int tempSeatBooked, Movie tempMovieShowing, screenFacilityEnum tempScreenFacility, string tempStartDate, string tempEndDate);
    void showScreenInformation();
    void bookSeat(int ticketNumber);
};



#endif //ASSESMENT_1_SCREEN_H
