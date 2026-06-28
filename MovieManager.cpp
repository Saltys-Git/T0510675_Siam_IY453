//
// Created by Siam on 25/06/2026.
//

#include "MovieManager.h"


Movie* MovieManager::getMovies() {
    return movies.data();
}

void MovieManager::addMovie(Movie movie) {
    movies.push_back(movie);
}

void MovieManager::removeMovie(int movieId) {
    
}

