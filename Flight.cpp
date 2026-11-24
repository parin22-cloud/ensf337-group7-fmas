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
#include <iomanip>

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


bool Flight::hasPassenger(int id) const
{
    for (const Passenger& p : passengers){
        if (p.getId() == id)
            return true;
    }
    return false;
}

void Flight::displaySeatMap() const
{
    // TODO
}

void Flight::displayPassengers() const
{
    std::cout << "\nPassenger List (Flight: " << flight_code << " from "
              << origin << " to " << destination << ")\n\n";

    std::cout << "ID      First Name   Last Name    Phone           Row   Seat\n";
    std::cout << std::string(61, '-') << '\n';

    // one passenger per line, padded so the columns line up
    for (const Passenger& p : passengers)
    {
        std::cout << std::left
                  << std::setw(8) << p.getId()
                  << std::setw(13) << p.getFirstName()
                  << std::setw(13) << p.getLastName()
                  << std::setw(16) << p.getPhoneNumber()
                  << std::setw(6) << p.getSeatRow()
                  << p.getSeatLetter() << '\n';
    }

    std::cout << std::string(61, '-') << '\n';
}

bool Flight::addPassenger(const Passenger& p, std::string& error_message)
{
    // TODO
    return false;
}

bool Flight::removePassenger(int id, std::string& error_message)
{
    for (size_t i = 0; i<passengers.size(); i++){
        if (passengers[i].getId() == id){
            std::cout << "\nPassenger " << passengers[i].getFirstName() << " " << passengers[i].getLastName()
                      << " was successfully removed from flight " << flight_code << ".\n";
            passengers.erase(passengers.begin()+i);
            return true;}
    }
    error_message =  "Passenger ID not found on this flight.";
    return false;
}