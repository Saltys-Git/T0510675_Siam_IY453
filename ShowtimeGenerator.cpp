//
// Created by Siam on 05/07/2026.
//

#include "ShowtimeGenerator.h"

// Cinema rules from the brief: earliest show 10:15 (615 mins after midnight),
// closes 23:30 (1410 mins), 25 minute cleaning gap required between shows.
ShowtimeGenerator::ShowtimeGenerator() {
    earliestStartMinutes = 615;
    closingTimeMinutes = 1410;
    cleaningGapMinutes = 25;
}

// Converts a minute count (e.g. 630) into a display string (e.g. "10:30").
string ShowtimeGenerator::ConvertMinutesToTimeString(int totalMinutes) {
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    string hoursText = to_string(hours);
    string minutesText = to_string(minutes);

    if (minutes < 10) {
        minutesText = "0" + minutesText;
    }

    string timeText = hoursText + ":" + minutesText;
    return timeText;
}

// Keeps adding shows starting at earliestStartMinutes, moving forward by
// running time plus the cleaning gap, until a show would end after closing.
// A show does not need to fit exactly into the day, it just cannot end late.
vector<ShowTime> ShowtimeGenerator::GenerateShowtimesForDay(int movieRunningTimeMinutes) {
    vector<ShowTime> dailyShowtimes;
    int currentStartMinutes = earliestStartMinutes;
    bool moreShowsFit = true;

    while (moreShowsFit == true) {
        int currentEndMinutes = currentStartMinutes + movieRunningTimeMinutes;

        if (currentEndMinutes <= closingTimeMinutes) {
            string startText = ConvertMinutesToTimeString(currentStartMinutes);
            string endText = ConvertMinutesToTimeString(currentEndMinutes);
            ShowTime newShow(startText, endText);
            dailyShowtimes.push_back(newShow);

            currentStartMinutes = currentEndMinutes + cleaningGapMinutes;
        } else {
            moreShowsFit = false;
        }
    }

    return dailyShowtimes;
}