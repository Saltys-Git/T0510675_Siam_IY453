//
// Created by Siam on 02/07/2026.
//

#include "BookingManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

BookingManager::BookingManager() {
    bookingsFilePath = "bookings.csv";
}

// One line per booking: id,customerName,movieTitle,screenId,showDate,showTime,
// ticketType,quantity,paymentMethod,totalCost
string BookingManager::BuildCsvLine(Booking& booking) {
    ostringstream csvLine;
    csvLine << booking.GetId() << ","
            << booking.GetCustomerName() << ","
            << booking.GetMovieTitle() << ","
            << booking.GetShowDate() << ","
            << booking.CalculateTotalCost();

    string finishedLine = csvLine.str();
    return finishedLine;
}

void BookingManager::SaveBookingToFile(Booking& booking) {
    ofstream outputFile;
    outputFile.open(bookingsFilePath, ios::app);

    if (outputFile.is_open() == true) {
        outputFile << BuildCsvLine(booking) << endl;
        outputFile.close();
        cout << "Booking saved to file." << endl;
    } else {
        cout << "Error: could not open bookings file for writing." << endl;
    }
}

void BookingManager::DisplayAllBookingsFromFile() {
    ifstream inputFile;
    inputFile.open(bookingsFilePath);

    if (inputFile.is_open() == true) {
        string currentLine;
        bool moreLines = true;

        while (moreLines == true) {
            moreLines = (bool)getline(inputFile, currentLine);
            if (moreLines == true) {
                cout << currentLine << endl;
            }
        }
        inputFile.close();
    } else {
        cout << "No bookings file found yet." << endl;
    }
}

// Splits a single CSV line into its fields by comma, used by all three
// search functions below so the splitting logic is written only once (DRY).
vector<string> SplitCsvLine(string line) {
    vector<string> fields;
    stringstream lineStream(line);
    string field;
    bool moreFields = true;

    while (moreFields == true) {
        moreFields = (bool)getline(lineStream, field, ',');
        if (moreFields == true) {
            fields.push_back(field);
        }
    }

    return fields;
}

void BookingManager::SearchBookingsByCustomerName(string searchName) {
    ifstream inputFile;
    inputFile.open(bookingsFilePath);

    if (inputFile.is_open() == true) {
        string currentLine;
        bool moreLines = true;
        bool matchFound = false;

        while (moreLines == true) {
            moreLines = (bool)getline(inputFile, currentLine);
            if (moreLines == true) {
                vector<string> fields = SplitCsvLine(currentLine);
                if (fields.size() > 1 && fields[1] == searchName) {
                    cout << currentLine << endl;
                    matchFound = true;
                }
            }
        }
        inputFile.close();

        if (matchFound == false) {
            cout << "No bookings found for customer: " << searchName << endl;
        }
    } else {
        cout << "No bookings file found yet." << endl;
    }
}

void BookingManager::SearchBookingsByMovieTitle(string searchTitle) {
    ifstream inputFile;
    inputFile.open(bookingsFilePath);

    if (inputFile.is_open() == true) {
        string currentLine;
        bool moreLines = true;
        bool matchFound = false;

        while (moreLines == true) {
            moreLines = (bool)getline(inputFile, currentLine);
            if (moreLines == true) {
                vector<string> fields = SplitCsvLine(currentLine);
                if (fields.size() > 2 && fields[2] == searchTitle) {
                    cout << currentLine << endl;
                    matchFound = true;
                }
            }
        }
        inputFile.close();

        if (matchFound == false) {
            cout << "No bookings found for film: " << searchTitle << endl;
        }
    } else {
        cout << "No bookings file found yet." << endl;
    }
}

void BookingManager::SearchBookingsByDate(string searchDate) {
    ifstream inputFile;
    inputFile.open(bookingsFilePath);

    if (inputFile.is_open() == true) {
        string currentLine;
        bool moreLines = true;
        bool matchFound = false;

        while (moreLines == true) {
            moreLines = (bool)getline(inputFile, currentLine);
            if (moreLines == true) {
                vector<string> fields = SplitCsvLine(currentLine);
                if (fields.size() > 3 && fields[3] == searchDate) {
                    cout << currentLine << endl;
                    matchFound = true;
                }
            }
        }
        inputFile.close();

        if (matchFound == false) {
            cout << "No bookings found for date: " << searchDate << endl;
        }
    } else {
        cout << "No bookings file found yet." << endl;
    }
}