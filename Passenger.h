// Passenger.h
// ENSF 337 Term Project - Group 7

// Declare the Passenger class in this file.
// Add the passenger information shown in the project class diagram.
// Declare the constructor and any accessors needed by the other classes.
// Declare the operation that displays one passenger's information.

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger{
private:
    int passenger_id;
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    int seat_row;
    char seat_letter;

public:
    Passenger (int id,
                const std::string &first,
                const std::string &last,
                const std::string &phone,
                int row,
                char letter
            );
        int getId() const;

        std::string getFirstName() const;

        std::string getLastName() const;

        std::string getPhoneNumber() const;

        int getSeatRow() const;
        
        char getSeatLetter() const;

        void print() const;

};


#endif
