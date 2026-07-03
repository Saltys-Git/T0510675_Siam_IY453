cmake_minimum_required(VERSION 4.2)
project(Assesment_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assesment_1 main.cpp
        Movie.cpp
        Movie.h
        Screen.cpp
        Screen.h
        Booking.cpp
        Booking.h
        User.cpp
        User.h
        MovieManager.cpp
        MovieManager.h
        Ticket.cpp
        Ticket.h
        AdultTicket.cpp
        AdultTicket.h
        ChildTicket.cpp
        ChildTicket.h
        StudentTicket.cpp
        StudentTicket.h
        SeniorCitizenTicket.cpp
        SeniorCitizenTicket.h
        Payment.cpp
        Payment.h
        CashPayment.cpp
        CashPayment.h
        CardPayment.cpp
        CardPayment.h
        BookingValidator.cpp
        BookingValidator.h
        BookingManager.cpp
        BookingManager.h
        ShowTime.cpp
        ShowTime.h
        ShowtimeGenerator.cpp
        ShowtimeGenerator.h
        Schedule.cpp
        Schedule.h
        MenuSystem.cpp
        MenuSystem.h)
