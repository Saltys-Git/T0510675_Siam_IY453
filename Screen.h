//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_SCREEN_H
#define ASSESMENT_1_SCREEN_H
#include "Movie.h"
#include "ShowTime.h"
#include <vector>

//https://www.geeksforgeeks.org/cpp/enumeration-in-cpp/ (2026)
enum ScreenFacility {
    STANDARD,
    IMAX,
    COUPLE_SEAT,
    SEAT_SERVICE
};

class Screen {
private:
    int id;
    int seatCapacity;
    int seatBooked;
    Movie movieShowing;
    ScreenFacility screenFacility;
    string startDate;
    string endDate;

public:
    Screen();
    Screen(int screenId, int screenSeatCapacity, int screenSeatBooked, Movie screenMovieShowing,
           ScreenFacility screenScreenFacility, string screenStartDate, string screenEndDate);

    int GetId();
    int GetSeatCapacity();
    int GetSeatBooked();
    Movie GetMovieShowing();

    void ShowScreenInformation();
    bool BookSeat(int ticketNumber);
    vector<ShowTime> GenerateDailyShowtimes();
};

#endif //ASSESMENT_1_SCREEN_H