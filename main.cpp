#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "MovieManager.h"

int main() {
    MovieManager movieManager;
    Movie oceanDrift = *movieManager.FindMovieByTitle("Ocean Drift");
    Screen screenTwo(2, 150, 0, oceanDrift, IMAX, "", "");

    vector<ShowTime> todaysShows = screenTwo.GenerateDailyShowtimes();

    cout << "Showtimes for " << oceanDrift.GetTitle()
         << " (" << oceanDrift.GetRunningTime() << " mins):" << endl;

    int index = 0;
    while (index < todaysShows.size()) {
        cout << todaysShows[index].GetStartTime() << " - "
             << todaysShows[index].GetEndTime() << endl;
        index = index + 1;
    }

    return 0;
}