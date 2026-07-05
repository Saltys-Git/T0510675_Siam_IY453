//
// Created by Siam on 25/06/2026.
//

#include "MovieManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

MovieManager::MovieManager() {
    moviesFilePath = "movies.csv";
    LoadMoviesFromFile();
}

void MovieManager::AddMovie(Movie newMovie) {
    movies.push_back(newMovie);
    SaveMoviesToFile();
}

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

    if (movieRemoved == true) {
        SaveMoviesToFile();
    }

    return movieRemoved;
}

string ConvertToLowercase(string text) {
    string lowercaseText = text;
    int index = 0;
    while (index < lowercaseText.length()) {
        lowercaseText[index] = (char)tolower(lowercaseText[index]);
        index = index + 1;
    }
    return lowercaseText;
}

Movie* MovieManager::FindMovieByTitle(string searchTitle) {
    Movie* foundMovie = nullptr;
    int index = 0;
    string searchTitleLower = ConvertToLowercase(searchTitle);

    while (index < movies.size() && foundMovie == nullptr) {
        if (ConvertToLowercase(movies[index].GetTitle()) == searchTitleLower) {
            foundMovie = &movies[index];
        }
        index = index + 1;
    }

    return foundMovie;
}

Movie* MovieManager::FindMovieById(int movieId) {
    Movie* foundMovie = nullptr;
    int index = 0;

    while (index < movies.size() && foundMovie == nullptr) {
        if (movies[index].GetId() == movieId) {
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


string MovieManager::BuildCsvLine(Movie movie) {
    ostringstream csvLine;
    csvLine << movie.GetId() << ","
            << movie.GetTitle() << ","
            << movie.GetDescription() << ","
            << movie.GetGenre() << ","
            << movie.GetCertificate() << ","
            << movie.GetMainStar() << ","
            << movie.GetFilmDistributor() << ","
            << movie.GetRunningTime() << ","
            << movie.GetReleaseDate();

    string finishedLine = csvLine.str();
    return finishedLine;
}

Movie MovieManager::ParseCsvLine(string csvLine) {
    stringstream lineStream(csvLine);
    string field;
    vector<string> fields;
    bool moreFields = true;

    while (moreFields == true) {
        moreFields = (bool)getline(lineStream, field, ',');
        if (moreFields == true) {
            fields.push_back(field);
        }
    }

    Movie parsedMovie;
    if (fields.size() == 9) {
        parsedMovie = Movie(stoi(fields[0]), fields[1], fields[2], fields[3], fields[4],
                             fields[5], fields[6], stoi(fields[7]), fields[8]);
    } else {
        cout << "Warning: skipped a corrupted movie record in the file." << endl;
    }

    return parsedMovie;
}

void MovieManager::SaveMoviesToFile() {
    ofstream outputFile;
    outputFile.open(moviesFilePath, ios::trunc);

    if (outputFile.is_open() == true) {
        int index = 0;
        while (index < movies.size()) {
            outputFile << BuildCsvLine(movies[index]) << endl;
            index = index + 1;
        }
        outputFile.close();
    } else {
        cout << "Error: could not save movies to file." << endl;
    }
}

void MovieManager::LoadMoviesFromFile() {
    ifstream inputFile;
    inputFile.open(moviesFilePath);

    if (inputFile.is_open() == true) {
        string currentLine;
        bool moreLines = true;

        while (moreLines == true) {
            moreLines = (bool)getline(inputFile, currentLine);
            if (moreLines == true && currentLine.empty() == false) {
                Movie loadedMovie = ParseCsvLine(currentLine);
                if (loadedMovie.GetId() != 0) {
                    movies.push_back(loadedMovie);
                }
            }
        }
        inputFile.close();
    }
}