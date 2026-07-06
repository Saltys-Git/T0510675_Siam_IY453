//
// Created by Siam on 05/07/2026.
//

#include "ScreenManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

ScreenManager::ScreenManager() {
    screensFilePath = "screens.csv";
    nextScreenId = 1;
    LoadScreensFromFile();
}

void ScreenManager::DisplayAllScreens() {
    int index = 0;
    while (index < screens.size()) {
        screens[index].ShowScreenInformation();
        cout << "----------------------" << endl;
        index = index + 1;
    }
}

Screen* ScreenManager::FindScreenById(int screenId) {
    Screen* foundScreen = nullptr;
    int index = 0;

    while (index < screens.size() && foundScreen == nullptr) {
        if (screens[index].GetId() == screenId) {
            foundScreen = &screens[index];
        }
        index = index + 1;
    }

    return foundScreen;
}

bool ScreenManager::BookSeatsOnScreen(int screenId, int ticketQuantity) {
    bool bookingSuccessful = false;
    Screen* targetScreen = FindScreenById(screenId);

    if (targetScreen == nullptr) {
        cout << "Screen not found." << endl;
    } else {
        bookingSuccessful = targetScreen->BookSeat(ticketQuantity);
        if (bookingSuccessful == true) {
            SaveScreensToFile();
        }
    }

    return bookingSuccessful;
}

void ScreenManager::AssignMovieToScreen(int screenId, Movie movieToShow) {
    Screen* targetScreen = FindScreenById(screenId);
    if (targetScreen != nullptr) {
        targetScreen->SetMovieShowing(movieToShow);
        SaveScreensToFile();
    }
}

string ScreenManager::BuildCsvLine(Screen screen) {
    ostringstream csvLine;
    csvLine << screen.GetId() << ","
            << screen.GetSeatCapacity() << ","
            << screen.GetSeatBooked() << ","
            << screen.GetMovieShowing().GetTitle() << ","
            << (int)screen.GetScreenFacility();

    string finishedLine = csvLine.str();
    return finishedLine;
}

Screen ScreenManager::ParseCsvLine(string csvLine, Movie placeholderMovie) {
    stringstream lineStream(csvLine);
    string field;
    vector<string> fields;
    bool moreFields = true;

    while (moreFields == true) {
        if (getline(lineStream, field, ',')) {
            fields.push_back(field);
        } else {
            moreFields = false;
        }
    }

    Screen parsedScreen;
    if (fields.size() == 5) {
        int facilityNumber = stoi(fields[4]);
        ScreenFacility facility;

        if (facilityNumber == 0) {
            facility = STANDARD;
        } else if (facilityNumber == 1) {
            facility = IMAX;
        } else if (facilityNumber == 2) {
            facility = COUPLE_SEAT;
        } else {
            facility = SEAT_SERVICE;
        }

        parsedScreen = Screen(stoi(fields[0]), stoi(fields[1]), stoi(fields[2]),
                               placeholderMovie, facility);
    }

    return parsedScreen;
}

void ScreenManager::SaveScreensToFile() {
    ofstream outputFile;
    outputFile.open(screensFilePath, ios::trunc);

    if (outputFile.is_open() == true) {
        int index = 0;
        while (index < screens.size()) {
            outputFile << BuildCsvLine(screens[index]) << endl;
            index = index + 1;
        }
        outputFile.close();
    } else {
        cout << "Error: could not save screens to file." << endl;
    }
}

void ScreenManager::LoadScreensFromFile() {
    ifstream inputFile;
    inputFile.open(screensFilePath);

    if (inputFile.is_open() == true) {
        Movie blankMovie;
        string currentLine;
        bool moreLines = true;

        while (moreLines == true) {
            if (getline(inputFile, currentLine)) {
                if (currentLine.empty() == false) {
                    Screen loadedScreen = ParseCsvLine(currentLine, blankMovie);
                    screens.push_back(loadedScreen);
                }
            } else {
                moreLines = false;
            }
        }
        inputFile.close();
    }
}

void ScreenManager::AddScreen(Screen newScreen) {
    newScreen.SetId(nextScreenId);
    screens.push_back(newScreen);
    nextScreenId = nextScreenId + 1;
    SaveScreensToFile();
}

bool ScreenManager::RemoveScreenById(int screenId) {
    bool screenRemoved = false;
    int index = 0;

    while (index < screens.size() && screenRemoved == false) {
        if (screens[index].GetId() == screenId) {
            screens.erase(screens.begin() + index);
            screenRemoved = true;
        }
        index = index + 1;
    }

    if (screenRemoved == true) {
        SaveScreensToFile();
    }

    return screenRemoved;
}

int ScreenManager::GetScreenCount() {
    return (int)screens.size();
}