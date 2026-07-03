//
// Created by Siam on 02/07/2026.
//

#include "Schedule.h"
#include "ShowtimeGenerator.h"
#include <iostream>
#include <fstream>
#include <sstream>

ScheduleEntry::ScheduleEntry() {
    screenId = 0;
}

ScheduleEntry::ScheduleEntry(int entryScreenId, string entryMovieTitle, string entryWeekStartDate,
                              string entryWeekEndDate, ShowTime entryShowTime) {
    screenId = entryScreenId;
    movieTitle = entryMovieTitle;
    weekStartDate = entryWeekStartDate;
    weekEndDate = entryWeekEndDate;
    dailyShowTime = entryShowTime;
}

int ScheduleEntry::GetScreenId() {
    return screenId;
}

string ScheduleEntry::GetMovieTitle() {
    return movieTitle;
}

string ScheduleEntry::GetWeekStartDate() {
    return weekStartDate;
}

string ScheduleEntry::GetWeekEndDate() {
    return weekEndDate;
}

ShowTime ScheduleEntry::GetDailyShowTime() {
    return dailyShowTime;
}

Schedule::Schedule() {
    scheduleFilePath = "schedule.csv";
}

// One line per showing slot: screenId,movieTitle,weekStartDate,weekEndDate,startTime,endTime
string Schedule::BuildCsvLine(ScheduleEntry entry) {
    ostringstream csvLine;
    csvLine << entry.GetScreenId() << ","
            << entry.GetMovieTitle() << ","
            << entry.GetWeekStartDate() << ","
            << entry.GetWeekEndDate() << ","
            << entry.GetDailyShowTime().GetStartTime() << ","
            << entry.GetDailyShowTime().GetEndTime();

    string finishedLine = csvLine.str();
    return finishedLine;
}

// Uses the screen's own showtime generator (built in Phase 8) to work out
// how many showings fit in a day, then creates one ScheduleEntry per showing.
vector<ScheduleEntry> Schedule::GenerateWeeklySchedule(Screen screen, string weekStartDate, string weekEndDate) {
    vector<ScheduleEntry> weeklyEntries;
    vector<ShowTime> dailyShowtimes = screen.GenerateDailyShowtimes();

    int index = 0;
    while (index < dailyShowtimes.size()) {
        ScheduleEntry newEntry(screen.GetId(), screen.GetMovieShowing().GetTitle(),
                                weekStartDate, weekEndDate, dailyShowtimes[index]);
        weeklyEntries.push_back(newEntry);
        index = index + 1;
    }

    return weeklyEntries;
}

void Schedule::SaveScheduleToFile(vector<ScheduleEntry> weeklyEntries) {
    ofstream outputFile;
    outputFile.open(scheduleFilePath, ios::app);

    if (outputFile.is_open() == true) {
        int index = 0;
        while (index < weeklyEntries.size()) {
            outputFile << BuildCsvLine(weeklyEntries[index]) << endl;
            index = index + 1;
        }
        outputFile.close();
        cout << "Schedule saved to file." << endl;
    } else {
        cout << "Error: could not open schedule file for writing." << endl;
    }
}

void Schedule::DisplayScheduleFromFile() {
    ifstream inputFile;
    inputFile.open(scheduleFilePath);

    if (inputFile.is_open() == true) {
        string currentLine;
        bool moreLines = true;

        while (moreLines == true) {
            moreLines = (bool)getline(inputFile, currentLine);
            if (moreLines == true) {
                cout << currentLine << endl;
            }
        }
        inputFile.close();
    } else {
        cout << "No schedule file found yet." << endl;
    }
}

void Schedule::ClearScheduleFile() {
    ofstream outputFile;
    outputFile.open(scheduleFilePath, ios::trunc);

    if (outputFile.is_open() == true) {
        outputFile.close();
        cout << "Schedule cleared." << endl;
    } else {
        cout << "Error: could not clear schedule file." << endl;
    }
}