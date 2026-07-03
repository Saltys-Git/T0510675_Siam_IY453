//
// Created by Siam on 02/07/2026.
//

#include "MenuSystem.h"
#include <iostream>
#include "AdultTicket.h"
#include "ChildTicket.h"
#include "StudentTicket.h"
#include "SeniorCitizenTicket.h"
#include "CashPayment.h"
#include "CardPayment.h"

MenuSystem::MenuSystem() {
    nextBookingId = 1;
}

// Keeps asking until a valid integer within range is entered.
// Centralised here so every menu re-uses the same input safety logic (DRY).
int MenuSystem::ReadValidatedMenuChoice(int minOption, int maxOption) {
    int userChoice = 0;
    bool validInputReceived = false;

    while (validInputReceived != true) {
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (cin.fail() == true) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
        } else if (userChoice < minOption || userChoice > maxOption) {
            cout << "Choice out of range. Try again." << endl;
        } else {
            validInputReceived = true;
        }
    }

    return userChoice;
}

// Only responsible for turning a menu number into the correct Ticket subclass.
Ticket* MenuSystem::CreateTicketFromChoice(int ticketChoice, int ticketQuantity) {
    Ticket* selectedTicket = nullptr;

    if (ticketChoice == 1) {
        selectedTicket = new AdultTicket(ticketQuantity);
    } else if (ticketChoice == 2) {
        selectedTicket = new ChildTicket(ticketQuantity);
    } else if (ticketChoice == 3) {
        selectedTicket = new StudentTicket(ticketQuantity);
    } else {
        selectedTicket = new SeniorCitizenTicket(ticketQuantity);
    }

    return selectedTicket;
}

// Only responsible for turning a menu number into the correct Payment subclass.
Payment* MenuSystem::CreatePaymentFromChoice(int paymentChoice, double amountDue) {
    Payment* selectedPayment = nullptr;

    if (paymentChoice == 1) {
        double cashGiven = 0.0;
        cout << "Amount due: GBP " << amountDue << endl;
        cout << "Enter cash given: ";
        cin >> cashGiven;
        selectedPayment = new CashPayment(amountDue, cashGiven);
    } else {
        string cardNumber, cardCvc, cardExpiry;
        cout << "Enter card number (16 digits): ";
        cin >> cardNumber;
        cout << "Enter CVC (3 digits): ";
        cin >> cardCvc;
        cout << "Enter expiry date (MM/YY): ";
        cin >> cardExpiry;

        CardPayment* newCardPayment = new CardPayment(amountDue);
        newCardPayment->ProcessPayment(cardNumber, cardCvc, cardExpiry);
        selectedPayment = newCardPayment;
    }

    return selectedPayment;
}

void MenuSystem::SetCurrentBookingWeek() {
    cout << "===== Setup: Enter Current Booking Week =====" << endl;
    currentWeekStart = ReadNonEmptyLine("Enter this week's start date (Thursday, YYYY-MM-DD): ");
    currentWeekEnd = ReadNonEmptyLine("Enter this week's end date (Wednesday, YYYY-MM-DD): ");
}

void MenuSystem::RunStaffBookingFlow() {
    movieManager.DisplayAllMovies();

    cin.ignore();
    string customerName = ReadNonEmptyLine("Enter customer name: ");
    string movieTitle = ReadNonEmptyLine("Enter film title: ");

    Movie* selectedMovie = movieManager.FindMovieByTitle(movieTitle);
    if (selectedMovie == nullptr) {
        cout << "Film not found. Returning to main menu." << endl;
        return;
    }

    string showDate;
    bool dateAccepted = false;
    while (dateAccepted == true == false) {
        showDate = ReadNonEmptyLine("Enter show date (YYYY-MM-DD): ");
        if (IsValidDateFormat(showDate) == true) {
            dateAccepted = true;
        } else {
            cout << "Invalid format. Use YYYY-MM-DD, e.g. 2026-07-09." << endl;
        }
    }

    string showTime = ReadNonEmptyLine("Enter show time (HH:MM): ");

    cout << "Ticket type (1=Adult 2=Child 3=Student 4=Senior): ";
    int ticketChoice = ReadValidatedMenuChoice(1, 4);
    cout << "Number of tickets: ";
    int ticketQuantity = ReadValidatedMenuChoice(1, 250);

    Screen currentScreen(1, 150, 0, *selectedMovie, IMAX, "", "");
    bool capacityOk = validator.IsWithinSeatCapacity(currentScreen, ticketQuantity);
    if (capacityOk == false) {
        cout << "Booking cancelled due to insufficient seats." << endl;
        return;
    }
    bool weekOk = validator.IsDateWithinCurrentWeek(showDate, currentWeekStart, currentWeekEnd);
    if (weekOk == false) {
        cout << "Booking cancelled: date outside current booking week." << endl;
        return;
    }

    Ticket* newTicket = CreateTicketFromChoice(ticketChoice, ticketQuantity);
    double amountDue = newTicket->CalculateTotalPrice();

    cout << "Payment method (1=Cash 2=Card): ";
    int paymentChoice = ReadValidatedMenuChoice(1, 2);
    Payment* newPayment = CreatePaymentFromChoice(paymentChoice, amountDue);

    Booking newBooking(nextBookingId, customerName, movieTitle, 1, showDate, showTime,
                        newTicket, newPayment);
    newBooking.DisplayBookingInformation();
    bookingManager.SaveBookingToFile(newBooking);
    nextBookingId = nextBookingId + 1;
}

void MenuSystem::RunManagerScheduleFlow() {
    movieManager.DisplayAllMovies();

    cin.ignore();
    string movieTitle = ReadNonEmptyLine("Enter film title to schedule: ");
    Movie* selectedMovie = movieManager.FindMovieByTitle(movieTitle);

    if (selectedMovie == nullptr) {
        cout << "Film not found. Returning to main menu." << endl;
        return;
    }

    string weekStartDate = ReadNonEmptyLine("Enter week start date (Thursday, YYYY-MM-DD): ");
    string weekEndDate = ReadNonEmptyLine("Enter week end date (Wednesday, YYYY-MM-DD): ");

    Screen selectedScreen(2, 150, 0, *selectedMovie, IMAX, "", "");
    vector<ScheduleEntry> weeklyEntries = schedule.GenerateWeeklySchedule(selectedScreen, weekStartDate, weekEndDate);
    schedule.SaveScheduleToFile(weeklyEntries);
    cout << "Generated and saved " << weeklyEntries.size() << " showings." << endl;
}

void MenuSystem::RunBookingSearchFlow() {
    cout << "Search by (1=Name 2=Film 3=Date): ";
    int searchChoice = ReadValidatedMenuChoice(1, 3);
    string searchTerm;
    cout << "Enter search term: ";
    cin.ignore();
    getline(cin, searchTerm);

    if (searchChoice == 1) {
        bookingManager.SearchBookingsByCustomerName(searchTerm);
    } else if (searchChoice == 2) {
        bookingManager.SearchBookingsByMovieTitle(searchTerm);
    } else {
        bookingManager.SearchBookingsByDate(searchTerm);
    }
}

void MenuSystem::RunMainMenu() {
    SetCurrentBookingWeek();
    bool programRunning = true;

    while (programRunning == true) {
        cout << endl << "===== Cinema Booking System =====" << endl;
        cout << "1. Book a ticket" << endl;
        cout << "2. Manager: create weekly schedule" << endl;
        cout << "3. Search bookings" << endl;
        cout << "4. Exit" << endl;

        int mainChoice = ReadValidatedMenuChoice(1, 4);

        if (mainChoice == 1) {
            RunStaffBookingFlow();
        } else if (mainChoice == 2) {
            RunManagerScheduleFlow();
        } else if (mainChoice == 3) {
            RunBookingSearchFlow();
        } else {
            cout << "Goodbye!" << endl;
            programRunning = false;
        }
    }
}

string MenuSystem::ReadNonEmptyLine(string promptText) {
    string enteredText;
    bool validTextReceived = false;

    while (validTextReceived == true == false) {
        cout << promptText;
        getline(cin, enteredText);

        if (enteredText.empty() == true) {
            cout << "Input cannot be empty. Please try again." << endl;
        } else {
            validTextReceived = true;
        }
    }

    return enteredText;
}


bool MenuSystem::IsValidDateFormat(string dateText) {
    bool formatIsValid = true;

    if (dateText.length() != 10) {
        formatIsValid = false;
    } else if (dateText[4] != '-' || dateText[7] != '-') {
        formatIsValid = false;
    }

    return formatIsValid;
}
