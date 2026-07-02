#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "MovieManager.h"
#include "Schedule.h"

int main() {
    MovieManager movieManager;
    Movie oceanDrift = *movieManager.FindMovieByTitle("Ocean Drift");
    Screen screenTwo(2, 150, 0, oceanDrift, IMAX, "", "");

    Schedule schedule;
    vector<ScheduleEntry> weekTwoSchedule = schedule.GenerateWeeklySchedule(screenTwo, "2026-07-09", "2026-07-15");

    cout << "Generated " << weekTwoSchedule.size() << " showings for screen 2." << endl;
    schedule.SaveScheduleToFile(weekTwoSchedule);

    cout << endl << "Full schedule file contents:" << endl;
    schedule.DisplayScheduleFromFile();

    return 0;
}