//
// Created by Siam on 02/07/2026.
//

#ifndef ASSESMENT_1_MENU_SYSTEM_H
#define ASSESMENT_1_MENU_SYSTEM_H
#include <string>
#include "MovieManager.h"
#include "BookingManager.h"
#include "BookingValidator.h"
#include "Schedule.h"
#include "ManagerAuth.h"
#include "ScreenManager.h"
using namespace std;

class MenuSystem {
private:
    MovieManager movieManager;
    BookingManager bookingManager;
    ScreenManager screenManager;
    BookingValidator validator;
    Schedule schedule;
    ManagerAuth managerAuth;
    int nextBookingId;
    int nextMovieId;
    string currentWeekStart;
    string currentWeekEnd;

    int ReadValidatedMenuChoice(int minOption, int maxOption);
    string ReadNonEmptyLine(string promptText);
    bool IsValidDateFormat(string dateText);
    bool IsValidTimeFormat(string timeText);
    Ticket* CreateTicketFromChoice(int ticketChoice, int ticketQuantity);
    Payment* CreatePaymentFromChoice(int paymentChoice, double amountDue);

    void RunStaffBookingFlow();
    void RunBookingSearchFlow();
    void SetCurrentBookingWeek();

    void RunManagerMenu();
    void RunAddMovieFlow();
    void RunRemoveMovieFlow();
    void RunAddScheduleFlow();
    void RunRemoveScheduleFlow();
    void RunAddScreenFlow();
    void RunRemoveScreenFlow();
    void RunAssignMovieToScreenFlow();

public:
    MenuSystem();

    void RunMainMenu();
};

#endif //ASSESMENT_1_MENU_SYSTEM_H