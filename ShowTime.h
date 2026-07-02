//
// Created by Siam on 02/07/2026.
//

#ifndef ASSESMENT_1_SHOW_TIME_H
#define ASSESMENT_1_SHOW_TIME_H
#include <string>
using namespace std;

class ShowTime {
private:
    string startTime;
    string endTime;

public:
    ShowTime();
    ShowTime(string showStartTime, string showEndTime);

    string GetStartTime();
    string GetEndTime();
};

#endif //ASSESMENT_1_SHOW_TIME_H