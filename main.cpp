#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "Booking.h"
#include "MovieManager.h"

int main() {
    MovieManager movieManager;

    cout << "All available films:" << endl;
    movieManager.DisplayAllMovies();

    Movie* searchResult = movieManager.FindMovieByTitle("Ocean Drift");
    if (searchResult != nullptr) {
        cout << "Found film:" << endl;
        searchResult->DisplayMovieInformation();
    }

    return 0;
}