//
// Created by Siam on 21/05/2026.
//

#include "Booking.h"
#include <iostream>

Booking::Booking(int bookingId, string bookingCustomerName, string bookingMovieTitle,
                  int bookingScreenId, string bookingShowDate, string bookingShowTime,
                  Ticket* bookingTicket, Payment* bookingPayment) {
    id = bookingId;
    customerName = bookingCustomerName;
    movieTitle = bookingMovieTitle;
    screenId = bookingScreenId;
    showDate = bookingShowDate;
    showTime = bookingShowTime;
    ticket = bookingTicket;
    payment = bookingPayment;
}

Booking::~Booking() {
    delete ticket;
    delete payment;
}

double Booking::CalculateTotalCost() {
    double totalCost = ticket->CalculateTotalPrice();
    return totalCost;
}

void Booking::DisplayBookingInformation() {
    cout << endl << "Booking Reference: " << id << endl;
    cout << "Customer: " << customerName << endl;
    cout << "Film: " << movieTitle << endl;
    cout << "Screen: " << screenId << endl;
    cout << "Date: " << showDate << " Time: " << showTime << endl;
    cout << "Ticket Type: " << ticket->GetTicketTypeName() << endl;
    cout << "Quantity: " << ticket->GetQuantity() << endl;
    cout << "Payment Method: " << payment->GetPaymentMethodName() << endl;
    cout << "Total Cost: " << CalculateTotalCost() << endl;
}

int Booking::GetId() {
    return id;
}

string Booking::GetCustomerName() {
    return customerName;
}

string Booking::GetMovieTitle() {
    return movieTitle;
}

string Booking::GetShowDate() {
    return showDate;
}


int Booking::GetScreenId() {
    return screenId;
}