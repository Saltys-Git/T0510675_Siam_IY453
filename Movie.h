//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_MOVIE_H
#define ASSESMENT_1_MOVIE_H
#include <string>
#include <iostream>

using namespace std;


class Movie {
private:
    string title, description, genre, mainStar, filmDistributor,releaseDate;
    int id, runningTime;

public:
    Movie();

    Movie(int id, string tempTitle, string tempDescription, string tempGenre, string tempMainStar, string tempFilmDistributor,
          int tempRunningTime, string tempReleaseDate);

    string getTitle();

    int getRunningTime();


    void addMovie(string tempTitle, string tempDescription, string tempGenre, string tempMainStar, string tempFilmDistributor,
                  int tempRunningTime, string tempReleaseDate);

    void displayMovieInformation();

    void removeMovie(int id);
};


#endif //ASSESMENT_1_MOVIE_H
