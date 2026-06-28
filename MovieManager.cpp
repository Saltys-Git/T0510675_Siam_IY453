//
// Created by Siam on 25/06/2026.
//

#include "MovieManager.h"

// Seeds three starter films so bookings are possible immediately,
// meeting the stage 2 requirement for a minimum of 3 available films.
MovieManager::MovieManager() {
    Movie filmOne(1, "The Great Escape", "A group of prisoners plan a daring breakout.",
                  "Adventure", "Steve McQueen", "MGM", 172, "1963-07-04");
    Movie filmTwo(2, "Ocean Drift", "A fictional heist crew targets a floating casino.",
                  "Thriller", "Jane Carter", "Kaplan Films", 128, "2025-11-20");
    Movie filmThree(3, "Starlight Diner", "A comedy about a small town diner reunion.",
                     "Comedy", "Tom Reyes", "Bright Pictures", 101, "2026-02-14");

    movies.push_back(filmOne);
    movies.push_back(filmTwo);
    movies.push_back(filmThree);
}

void MovieManager::AddMovie(Movie newMovie) {
    movies.push_back(newMovie);
}

// Single return variable used so there is only one exit point from the function.
bool MovieManager::RemoveMovieById(int movieId) {
    bool movieRemoved = false;
    int index = 0;

    while (index < movies.size() && movieRemoved == false) {
        if (movies[index].GetId() == movieId) {
            movies.erase(movies.begin() + index);
            movieRemoved = true;
        }
        index = index + 1;
    }

    return movieRemoved;
}

// Returns a pointer so the caller can act on the actual stored movie.
// nullptr signals "not found" without needing a second return statement.
Movie* MovieManager::FindMovieByTitle(string searchTitle) {
    Movie* foundMovie = nullptr;
    int index = 0;

    while (index < movies.size() && foundMovie == nullptr) {
        if (movies[index].GetTitle() == searchTitle) {
            foundMovie = &movies[index];
        }
        index = index + 1;
    }

    return foundMovie;
}

void MovieManager::DisplayAllMovies() {
    int index = 0;

    while (index < movies.size()) {
        movies[index].DisplayMovieInformation();
        cout << "----------------------" << endl;
        index = index + 1;
    }
}

int MovieManager::GetMovieCount() {
    return (int)movies.size();
}