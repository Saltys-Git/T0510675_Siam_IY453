//
// Created by Siam on 05/07/2026.
//

#ifndef ASSESMENT_1_SCREEN_MANAGER_H
#define ASSESMENT_1_SCREEN_MANAGER_H
#include <vector>
#include <string>
#include "Screen.h"
#include "Movie.h"
using namespace std;

class ScreenManager {
private:
    vector<Screen> screens;
    string screensFilePath;
    int nextScreenId;

    string BuildCsvLine(Screen screen);
    Screen ParseCsvLine(string csvLine, Movie placeholderMovie);

public:
    ScreenManager();

    void DisplayAllScreens();
    Screen* FindScreenById(int screenId);
    bool BookSeatsOnScreen(int screenId, int ticketQuantity);
    void AssignMovieToScreen(int screenId, Movie movieToShow);

    void SaveScreensToFile();
    void LoadScreensFromFile();
    void AddScreen(Screen newScreen);
    bool RemoveScreenById(int screenId);
    int GetScreenCount();
};

#endif //ASSESMENT_1_SCREEN_MANAGER_H