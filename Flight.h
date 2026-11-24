// Flight.h
// ENSF 337 Term Project - Group 7

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
    std::vector<Passenger> passengers;   // everyone booked on this flight

public:
    // starts with no passengers, Airline adds them while loading
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
    const std::vector<Passenger>& getPassengers() const;   // used when saving

    // true if a passenger with this id is on this flight
    bool hasPassenger(int id) const;

    void displaySeatMap() const;
    void displayPassengers() const;

    // return true if it worked, otherwise error_message says why
    bool addPassenger(const Passenger& p, std::string& error_message);
    bool removePassenger(int id, std::string& error_message);
};

#endif
