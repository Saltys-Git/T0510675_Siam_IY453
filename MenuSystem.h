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
using namespace std;

class MenuSystem {
private:
    MovieManager movieManager;
    BookingManager bookingManager;
    BookingValidator validator;
    Schedule schedule;
    int nextBookingId;
    string currentWeekStart;
    string currentWeekEnd;

    int ReadValidatedMenuChoice(int minOption, int maxOption);
    string ReadNonEmptyLine(string promptText);
    bool IsValidDateFormat(string dateText);
    Ticket* CreateTicketFromChoice(int ticketChoice, int ticketQuantity);
    Payment* CreatePaymentFromChoice(int paymentChoice, double amountDue);
    void SetCurrentBookingWeek();

    void RunStaffBookingFlow();
    void RunManagerScheduleFlow();
    void RunBookingSearchFlow();

public:
    MenuSystem();

    void RunMainMenu();
};

#endif //ASSESMENT_1_MENU_SYSTEM_H