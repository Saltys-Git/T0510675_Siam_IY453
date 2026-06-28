//
// Created by Siam on 21/05/2026.
//

#include "Movie.h"

// Default constructor gives safe starting values so an uninitialised Movie
// never holds garbage data if used before being properly set.
Movie::Movie() {
    id = 0;
    runningTime = 0;
}

Movie::Movie(int movieId, string movieTitle, string movieDescription, string movieGenre,
             string movieMainStar, string movieFilmDistributor, int movieRunningTime,
             string movieReleaseDate) {
    id = movieId;
    title = movieTitle;
    description = movieDescription;
    genre = movieGenre;
    mainStar = movieMainStar;
    filmDistributor = movieFilmDistributor;
    runningTime = movieRunningTime;
    releaseDate = movieReleaseDate;
}

int Movie::GetId() {
    return id;
}

string Movie::GetTitle() {
    return title;
}

string Movie::GetDescription() {
    return description;
}

string Movie::GetGenre() {
    return genre;
}

string Movie::GetMainStar() {
    return mainStar;
}

string Movie::GetFilmDistributor() {
    return filmDistributor;
}

int Movie::GetRunningTime() {
    return runningTime;
}

string Movie::GetReleaseDate() {
    return releaseDate;
}

void Movie::DisplayMovieInformation() {
    cout << id << " : " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Genre: " << genre << endl;
    cout << "Running Time: " << runningTime << " mins" << endl;
    cout << "Main Star: " << mainStar << endl;
    cout << "Distributor: " << filmDistributor << endl;
    cout << "Release Date: " << releaseDate << endl;
}