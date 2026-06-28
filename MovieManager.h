//
// Created by Siam on 25/06/2026.
//

#ifndef ASSESMENT_1_MOVIE_MANAGER_H
#define ASSESMENT_1_MOVIE_MANAGER_H
#include <vector>
#include "Movie.h"
using namespace std;

class MovieManager {
private:
    vector<Movie> movies;

public:
    MovieManager();

    void AddMovie(Movie newMovie);
    bool RemoveMovieById(int movieId);
    Movie* FindMovieByTitle(string searchTitle);
    void DisplayAllMovies();
    int GetMovieCount();
};

#endif //ASSESMENT_1_MOVIE_MANAGER_H