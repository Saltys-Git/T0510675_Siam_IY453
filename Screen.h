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

public:
    Screen();
    Screen(int screenId, int screenSeatCapacity, int screenSeatBooked, Movie screenMovieShowing,
           ScreenFacility screenScreenFacility);

    int GetId();
    void SetId(int newId);
    int GetSeatCapacity();
    int GetSeatBooked();
    Movie GetMovieShowing();
    string GetFacilityName();
    void ShowScreenInformation();
    bool BookSeat(int ticketNumber);
    vector<ShowTime> GenerateDailyShowtimes();
    ScreenFacility GetScreenFacility();
    void SetMovieShowing(Movie newMovie);
};

#endif //ASSESMENT_1_SCREEN_H