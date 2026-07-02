//
// Created by Siam on 02/07/2026.
//

#include "ShowTime.h"

ShowTime::ShowTime() {
}

ShowTime::ShowTime(string showStartTime, string showEndTime) {
    startTime = showStartTime;
    endTime = showEndTime;
}

string ShowTime::GetStartTime() {
    return startTime;
}

string ShowTime::GetEndTime() {
    return endTime;
}