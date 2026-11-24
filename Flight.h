// Flight.h
// ENSF 337 Term Project - Group 7

// Declare the Flight class in this file.
//
// Add the flight information shown in the project class diagram.
// Store the Passenger objects that belong to this flight.
// Declare the constructor and any accessors needed by the other classes.
// Declare the operations for displaying the seat map, displaying passengers,
// adding a passenger and removing a passenger.

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "Passenger.h"

class Flight {
private:
    std::string flight_code;
    std::string origin;
    std::string destination;
    int number_of_rows;
    int seats_per_row;
    std::vector<Passenger> passengers;

public:
    Flight(const std::string& code,
           const std::string& from,
           const std::string& to,
           int rows,
           int seats);

    std::string getFlightCode() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    int getNumberOfRows() const;
    int getSeatsPerRow() const;

    const std::vector<Passenger>& getPassengers() const;

    void displaySeatMap() const;
    void displayPassengers() const;

    bool addPassenger(const Passenger& passenger);
    bool removePassenger(int passengerId);
};

#endif
