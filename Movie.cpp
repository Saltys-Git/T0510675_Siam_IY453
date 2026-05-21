//
// Created by Siam on 21/05/2026.
//

#include "Movie.h"


Movie :: Movie(int tempId, string tempTitle, string tempDescription, string tempGenre, string tempMainStar, string tempFilmDistributor,
          int tempRunningTime, string tempReleaseDate) {
    id = tempId;
    title = tempTitle;
    description = tempDescription;
    genre = tempGenre;
    mainStar = tempMainStar;
    filmDistributor = tempFilmDistributor;
    runningTime = tempRunningTime;
    releaseDate = tempReleaseDate;
}

string Movie::getTitle() {
    return title;
}

int Movie::getRunningTime() {
    return runningTime;
}

void Movie::displayMovieInformation() {
    cout << id << " : " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Running Time: " << runningTime << endl;
    cout << "Main Star: " << mainStar << endl;
}

void Movie::addMovie(string tempTitle, string tempDescription, string tempGenre, string tempMainStar, string tempFilmDistributor,
                  int tempRunningTime, string tempReleaseDate) {
    // need file handling for that
}


void Movie::removeMovie(int id) {
    // will do after file handling
}
