// Flight.cpp
// ENSF 337 Term Project - Group 7

// Implement the Flight member functions declared in Flight.h.
//
// Build the seat map from this flight's dimensions and passenger information.
// Implement the passenger display, addition and removal operations here.
// Flight.cpp
// ENSF 337 Term Project - Group 7

#include "Flight.h"
#include <iostream>

Flight::Flight(const std::string& code,
               const std::string& from,
               const std::string& to,
               int rows,
               int seats)
    : flight_code(code),
      origin(from),
      destination(to),
      number_of_rows(rows),
      seats_per_row(seats)
{
}

std::string Flight::getFlightCode() const { return flight_code; }
std::string Flight::getOrigin() const { return origin; }
std::string Flight::getDestination() const { return destination; }
int Flight::getNumberOfRows() const { return number_of_rows; }
int Flight::getSeatsPerRow() const { return seats_per_row; }
const std::vector<Passenger>& Flight::getPassengers() const { return passengers; }

// ---------- you write these ----------

bool Flight::hasPassenger(int id) const
{
    // TODO
    return false;
}

void Flight::displaySeatMap() const
{
    // TODO
}

void Flight::displayPassengers() const
{
    // TODO
}

bool Flight::addPassenger(const Passenger& p, std::string& error_message)
{
    // TODO
    return false;
}

bool Flight::removePassenger(int id, std::string& error_message)
{
    // TODO
    return false;
}