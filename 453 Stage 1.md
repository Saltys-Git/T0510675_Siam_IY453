# IY453 Stage 1

| Assessment Details | Please Complete All Details        |
| ------------------ | ---------------------------------- |
| Group              | IY453 A                            |
| Module Title       | Software Design and Implementation |
| Assessment Type    | ASSESSMENT 1: Coursework           |
| Module Tutor Name  | Jonathan Shore                     |
| Student ID Number  | T0510765                           |
| Date of Submission | 07/05/2026                         |
| Word Count         |                                    |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.*

------------------------------------------------------------------------------------------------------------------------------

### Introduction

------------------------------------------------------------------------------------------------------------------------------

This stage of the assesment is about designing and planning what and how the program should work. This stage splits into three parts where, first is to outlining the program specification. Then second part is to show the IO table of the program. FInally, a flowchart to show the algorithm of the whole program. The program is about cinema ticket booking system. By the end of this assesment, I will be prepared for the coding part. Because the structure of the program and description will be outlined in this assesment.

------------------------------------------------------------------------------------------------------------------------------

### Analysis and Design

------------------------------------------------------------------------------------------------------------------------------

#### First stage: Outline program specification

The main requirement of the program is to help the staffs to book cinema tickets on behalf of customers. It will act like a POS system where staffs with different roles can have different permissions. Core functional requirements are to get booking information from customers and feed it to the system to book, updating screen information, updating or adding new movies to the system, and updating the schedules for shows. For booking a ticket process, the system/program has several rules to follow. It should not allow staffs to make booking if it is not for current week and if all the seats are already sold. The booking data should be saved in certain file format. It should also show the booking data if needed. While updating screen information, the program has to analyse movie lengths and update the show times with a certain amount of time gap. Now, updating the schedule must be done on a specific day of the week. Similar to booking data, schedule data needs to be saved in a text or csv file. Finally the structure will be,

- **Book ticket:** To book a ticket for a movie on specific time. 

- **Admin Panel:** A list of menus to access all the modification related functions.
  
  - Update movie: 

#### Second stage: Identify inputs, outputs, and processes

| Feature / Task    | Inputs                     | Processing (what the system does)                               | Outputs                                                                              |
| ----------------- | -------------------------- | --------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| Start Program     | None                       | Initialise the datasets                                         | Main Menu Displayed                                                                  |
| Display Main Menu | User menu choice (1-3)     | Validate input is an integer in range; route to chosen function | Confirmation of selected option / next screen shown OR error “option does not exist” |
| Book Ticket       | Menu choice = 1            | Retrive movie and schedule data from the saved csv or text      | Ask for preferred date range in two cin                                              |
| Preferred dates   | Dates in DD-MM-YYYY format | Format dates, validate and check if date range is valid or not  | Shows "Enter"                                                                        |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
|                   |                            |                                                                 |                                                                                      |
| Exit              | Menu choice = 3            | End loop; terminate program                                     | “Goodbye!” message                                                                   |

#### Third state: Algorithms

------------------------------------------------------------------------------------------------------------------------------

### References

------------------------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------------------------
