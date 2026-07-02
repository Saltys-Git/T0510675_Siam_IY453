//
// Created by Siam on 02/07/2026.
//

#ifndef ASSESMENT_1_SCHEDULE_H
#define ASSESMENT_1_SCHEDULE_H
#include <string>
#include <vector>
#include "Screen.h"
#include "Movie.h"
#include "ShowTime.h"
using namespace std;

class ScheduleEntry {
private:
    int screenId;
    string movieTitle;
    string weekStartDate;
    string weekEndDate;
    ShowTime dailyShowTime;

public:
    ScheduleEntry();
    ScheduleEntry(int entryScreenId, string entryMovieTitle, string entryWeekStartDate,
                  string entryWeekEndDate, ShowTime entryShowTime);

    int GetScreenId();
    string GetMovieTitle();
    string GetWeekStartDate();
    string GetWeekEndDate();
    ShowTime GetDailyShowTime();
};

class Schedule {
private:
    string scheduleFilePath;

    string BuildCsvLine(ScheduleEntry entry);

public:
    Schedule();

    vector<ScheduleEntry> GenerateWeeklySchedule(Screen screen, string weekStartDate, string weekEndDate);
    void SaveScheduleToFile(vector<ScheduleEntry> weeklyEntries);
    void DisplayScheduleFromFile();
};

#endif //ASSESMENT_1_SCHEDULE_H