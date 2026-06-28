//
// Created by Siam on 25/06/2026.
//

#ifndef ASSESMENT_1_MOVIEMANAGER_H
#define ASSESMENT_1_MOVIEMANAGER_H
#include <vector>

#include "Movie.h"


class MovieManager {
private:
    vector<Movie> movies;
    public:
    void addMovie(Movie movie);
    void removeMovie(int movieId);
    Movie* getMovies();


};



#endif //ASSESMENT_1_MOVIEMANAGER_H
