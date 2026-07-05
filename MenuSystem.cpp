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
    nextMovieId = 1;
    currentWeekStart = "";
    currentWeekEnd = "";
    schedule.GetLatestWeekDates(&currentWeekStart, &currentWeekEnd);
}

// Keeps asking until a valid integer within range is entered.
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

// only responsible for turning a menu number into the correct Ticket subclass.
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

// only responsible for turning a menu number into the correct Payment subclass.
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

void MenuSystem::RunAddMovieFlow() {
    cin.ignore();
    string title = ReadNonEmptyLine("Enter film title: ");
    string description = ReadNonEmptyLine("Enter description: ");
    string genre = ReadNonEmptyLine("Enter genre: ");
    string certificate = ReadNonEmptyLine("Enter certificate (e.g. 12A): ");
    string mainStar = ReadNonEmptyLine("Enter main star: ");
    string filmDistributor = ReadNonEmptyLine("Enter film distributor: ");

    string releaseDate;
    bool dateAccepted = false;
    while (dateAccepted == true == false) {
        releaseDate = ReadNonEmptyLine("Enter release date (YYYY-MM-DD): ");
        dateAccepted = IsValidDateFormat(releaseDate);
        if (dateAccepted == false) {
            cout << "Invalid format. Use YYYY-MM-DD." << endl;
        }
    }

    cout << "Enter running time in minutes: ";
    int runningTime = ReadValidatedMenuChoice(1, 500);

    Movie newMovie(nextMovieId, title, description, genre, certificate, mainStar,
                   filmDistributor, runningTime, releaseDate);
    movieManager.AddMovie(newMovie);
    nextMovieId = nextMovieId + 1;

    cout << "Film added successfully." << endl;
}

void MenuSystem::RunRemoveMovieFlow() {
    movieManager.DisplayAllMovies();

    cout << "Enter the ID of the film to remove: ";
    int movieIdToRemove = ReadValidatedMenuChoice(1, 9999);

    bool removalSuccessful = movieManager.RemoveMovieById(movieIdToRemove);
    if (removalSuccessful == true) {
        cout << "Film removed successfully." << endl;
    } else {
        cout << "No film found with that ID." << endl;
    }
}

void MenuSystem::RunAddScheduleFlow() {
    movieManager.DisplayAllMovies();

    cin.ignore();
    string movieTitle = ReadNonEmptyLine("Enter film title to schedule: ");
    Movie* selectedMovie = movieManager.FindMovieByTitle(movieTitle);

    if (selectedMovie == nullptr) {
        cout << "Film not found." << endl;
        return;
    }

    string weekStartDate;
    bool startDateAccepted = false;
    while (startDateAccepted == true == false) {
        weekStartDate = ReadNonEmptyLine("Enter week start date (Thursday, YYYY-MM-DD): ");
        startDateAccepted = IsValidDateFormat(weekStartDate);
        if (startDateAccepted == false) {
            cout << "Invalid format. Use YYYY-MM-DD." << endl;
        }
    }

    string weekEndDate;
    bool endDateAccepted = false;
    while (endDateAccepted == true == false) {
        weekEndDate = ReadNonEmptyLine("Enter week end date (Wednesday, YYYY-MM-DD): ");
        endDateAccepted = IsValidDateFormat(weekEndDate);
        if (endDateAccepted == false) {
            cout << "Invalid format. Use YYYY-MM-DD." << endl;
        }
    }

    Screen selectedScreen(2, 150, 0, *selectedMovie, IMAX, "", "");
    vector<ScheduleEntry> weeklyEntries = schedule.GenerateWeeklySchedule(selectedScreen, weekStartDate, weekEndDate);
    schedule.SaveScheduleToFile(weeklyEntries);

    currentWeekStart = weekStartDate;
    currentWeekEnd = weekEndDate;

    cout << "Generated and saved " << weeklyEntries.size() << " showings." << endl;
}

void MenuSystem::RunRemoveScheduleFlow() {
    cout << "Current schedule:" << endl;
    schedule.DisplayScheduleFromFile();

    cout << "Remove all schedule data? (1=Yes 2=No): ";
    int confirmChoice = ReadValidatedMenuChoice(1, 2);

    if (confirmChoice == 1) {
        schedule.ClearScheduleFile();
    } else {
        cout << "Removal cancelled." << endl;
    }
}

void MenuSystem::RunStaffBookingFlow() {
    if (currentWeekStart.empty() == true) {
        cout << "No schedule has been created yet. Ask the manager to add one first." << endl;
        return;
    }

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
        dateAccepted = IsValidDateFormat(showDate);
        if (dateAccepted == false) {
            cout << "Invalid format. Use YYYY-MM-DD." << endl;
        }
    }

    string showTime;
    bool timeAccepted = false;
    while (timeAccepted == true == false) {
        showTime = ReadNonEmptyLine("Enter show time (HH:MM): ");
        timeAccepted = IsValidTimeFormat(showTime);
        if (timeAccepted == false) {
            cout << "Invalid format. Use HH:MM, e.g. 18:30." << endl;
        }
    }

    cout << "Ticket type (1=Adult 2=Child 3=Student 4=Senior): ";
    int ticketChoice = ReadValidatedMenuChoice(1, 4);
    cout << "Number of tickets: ";
    int ticketQuantity = ReadValidatedMenuChoice(1, 250);

    Screen currentScreen(1, 150, 0, *selectedMovie, IMAX, "", "");
    if (validator.IsWithinSeatCapacity(currentScreen, ticketQuantity) == false) {
        return;
    }

    if (validator.IsDateWithinCurrentWeek(showDate, currentWeekStart, currentWeekEnd) == false) {
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


void MenuSystem::RunManagerMenu() {
    bool managerSessionActive = true;

    while (managerSessionActive == true) {
        cout << endl << "===== Manager Menu =====" << endl;
        cout << "1. Add movie" << endl;
        cout << "2. Remove movie" << endl;
        cout << "3. Add schedule" << endl;
        cout << "4. Remove schedule" << endl;
        cout << "5. Log out" << endl;

        int managerChoice = ReadValidatedMenuChoice(1, 5);

        if (managerChoice == 1) {
            RunAddMovieFlow();
        } else if (managerChoice == 2) {
            RunRemoveMovieFlow();
        } else if (managerChoice == 3) {
            RunAddScheduleFlow();
        } else if (managerChoice == 4) {
            RunRemoveScheduleFlow();
        } else {
            cout << "Logging out of manager menu." << endl;
            managerSessionActive = false;
        }
    }
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
    bool programRunning = true;

    while (programRunning == true) {
        cout << endl << "===== Cinema Booking System =====" << endl;
        cout << "1. Book a ticket" << endl;
        cout << "2. Manager login" << endl;
        cout << "3. Search bookings" << endl;
        cout << "4. Exit" << endl;

        int mainChoice = ReadValidatedMenuChoice(1, 4);

        if (mainChoice == 1) {
            RunStaffBookingFlow();
        } else if (mainChoice == 2) {
            if (managerAuth.VerifyManagerAccess() == true) {
                RunManagerMenu();
            }
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

    while (validTextReceived == false) {
        cout << promptText;
        getline(cin, enteredText);

        int startPosition = 0;
        int endPosition = (int)enteredText.length() - 1;
        while (startPosition <= endPosition && isspace(enteredText[startPosition])) {
            startPosition = startPosition + 1;
        }
        while (endPosition >= startPosition && isspace(enteredText[endPosition])) {
            endPosition = endPosition - 1;
        }
        enteredText = enteredText.substr(startPosition, endPosition - startPosition + 1);

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


bool MenuSystem::IsValidTimeFormat(string timeText) {
    bool formatIsValid = true;

    if (timeText.length() != 5) {
        formatIsValid = false;
    } else if (timeText[2] != ':') {
        formatIsValid = false;
    } else {
        string hourPart = timeText.substr(0, 2);
        string minutePart = timeText.substr(3, 2);
        bool hourIsDigits = (isdigit(hourPart[0]) && isdigit(hourPart[1]));
        bool minuteIsDigits = (isdigit(minutePart[0]) && isdigit(minutePart[1]));

        if (hourIsDigits == false || minuteIsDigits == false) {
            formatIsValid = false;
        } else {
            int hourValue = stoi(hourPart);
            int minuteValue = stoi(minutePart);
            if (hourValue > 23 || minuteValue > 59) {
                formatIsValid = false;
            }
        }
    }

    return formatIsValid;
}