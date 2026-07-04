//
// Created by Siam on 25/06/2026.
//

#ifndef ASSESMENT_1_MOVIE_MANAGER_H
#define ASSESMENT_1_MOVIE_MANAGER_H
#include <vector>
#include <string>
#include "Movie.h"
using namespace std;

class MovieManager {
private:
    vector<Movie> movies;
    string moviesFilePath;

    string BuildCsvLine(Movie movie);
    Movie ParseCsvLine(string csvLine);

public:
    MovieManager();

    void AddMovie(Movie newMovie);
    bool RemoveMovieById(int movieId);
    Movie* FindMovieByTitle(string searchTitle);
    void DisplayAllMovies();
    int GetMovieCount();

    void SaveMoviesToFile();
    void LoadMoviesFromFile();
};

#endif //ASSESMENT_1_MOVIE_MANAGER_HER_H