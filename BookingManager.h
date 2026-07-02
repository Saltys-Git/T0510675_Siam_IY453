//
// Created by Siam on 02/07/2026.
//

#ifndef ASSESMENT_1_BOOKING_MANAGER_H
#define ASSESMENT_1_BOOKING_MANAGER_H
#include <string>
#include <vector>
#include "Booking.h"
using namespace std;

class BookingManager {
private:
    string bookingsFilePath;

    string BuildCsvLine(Booking& booking);

public:
    BookingManager();

    void SaveBookingToFile(Booking& booking);
    void DisplayAllBookingsFromFile();
    void SearchBookingsByCustomerName(string searchName);
    void SearchBookingsByMovieTitle(string searchTitle);
    void SearchBookingsByDate(string searchDate);
};

#endif //ASSESMENT_1_BOOKING_MANAGER_H