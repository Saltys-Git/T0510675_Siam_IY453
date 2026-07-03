//
// Created by Siam on 25/06/2026.
//

#include "MovieManager.h"

// Seeds three starter films so bookings are possible immediately,
// meeting the stage 2 requirement for a minimum of 3 available films.
MovieManager::MovieManager() {
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


