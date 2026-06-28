//
// Created by Siam on 21/05/2026.
//

#ifndef ASSESMENT_1_MOVIE_H
#define ASSESMENT_1_MOVIE_H
#include <string>
using namespace std;

class Movie {
private:
    int id;
    string title;
    string description;
    string genre;
    string mainStar;
    string filmDistributor;
    int runningTime;
    string releaseDate;

public:
    Movie();
    Movie(int movieId, string movieTitle, string movieDescription, string movieGenre,
          string movieMainStar, string movieFilmDistributor, int movieRunningTime,
          string movieReleaseDate);

    int GetId();
    string GetTitle();
    string GetDescription();
    string GetGenre();
    string GetMainStar();
    string GetFilmDistributor();
    int GetRunningTime();
    string GetReleaseDate();

    void DisplayMovieInformation();
};

#endif //ASSESMENT_1_MOVIE_H
