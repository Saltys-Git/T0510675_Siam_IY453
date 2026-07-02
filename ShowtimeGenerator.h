//
// Created by Siam on 02/07/2026.
//

#ifndef ASSESMENT_1_SHOWTIME_GENERATOR_H
#define ASSESMENT_1_SHOWTIME_GENERATOR_H
#include <vector>
#include <string>
#include "ShowTime.h"
using namespace std;

class ShowtimeGenerator {
private:
    int earliestStartMinutes;
    int closingTimeMinutes;
    int cleaningGapMinutes;

    string ConvertMinutesToTimeString(int totalMinutes);

public:
    ShowtimeGenerator();

    vector<ShowTime> GenerateShowtimesForDay(int movieRunningTimeMinutes);
};

#endif //ASSESMENT_1_SHOWTIME_GENERATOR_H