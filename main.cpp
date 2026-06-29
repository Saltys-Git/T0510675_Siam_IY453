#include <iostream>
#include "Movie.h"
#include "Screen.h"
#include "Booking.h"
#include "MovieManager.h"
#include "Ticket.h"
#include "AdultTicket.h"
#include "ChildTicket.h"
#include "StudentTicket.h"
#include "SeniorCitizenTicket.h"

int main() {
    MovieManager movieManager;
    cout << "All available films:" << endl;
    movieManager.DisplayAllMovies();

    Ticket* ticketList[4];
    ticketList[0] = new AdultTicket(2);
    ticketList[1] = new ChildTicket(1);
    ticketList[2] = new StudentTicket(3);
    ticketList[3] = new SeniorCitizenTicket(1);

    int index = 0;
    while (index < 4) {
        cout << ticketList[index]->GetTicketTypeName() << " x"
             << ticketList[index]->GetQuantity() << " = £"
             << ticketList[index]->CalculateTotalPrice() << endl;
        index = index + 1;
    }

    index = 0;
    while (index < 4) {
        delete ticketList[index];
        index = index + 1;
    }

    return 0;
}