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

Flight::Flight(const std::string &code,
               const std::string &from,
               const std::string &to,
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
const std::vector<Passenger> &Flight::getPassengers() const { return passengers; }

bool Flight::hasPassenger(int id) const
{
    for (const Passenger &p : passengers)
    {
        if (p.getId() == id)
            return true;
    }
    return false;
}

void Flight::displaySeatMap() const
{
    std::vector<std::vector<char>> seats(number_of_rows, std::vector<char>(seats_per_row, '-'));
    for (const Passenger &p : passengers)
    {
        seats[p.getSeatRow() - 1][p.getSeatLetter() - 'A'] = 'X';
    }
        std::cout << "\nAircraft Seat Map\n";

        std::cout << "    ";
        for (int j = 0; j < seats_per_row; j++)
            std::cout << "  " << char('A' + j) << " ";
        std::cout << '\n';

        for (int i = 0; i < number_of_rows; i++)
        {
            std::cout << std::right << std::setw(3) << i + 1 << " ";
            for (int j = 0; j < seats_per_row; j++)
                std::cout << "  " << seats[i][j] << " ";
            std::cout << '\n';
        }
}

void Flight::displayPassengers() const
{
    std::cout << "\nPassenger List (Flight: " << flight_code << " from "
              << origin << " to " << destination << ")\n\n";

    std::cout << "ID      First Name   Last Name    Phone           Row   Seat\n";
    std::cout << std::string(61, '-') << '\n';

    for (const Passenger &p : passengers)
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

bool Flight::addPassenger(const Passenger &p, std::string &error_message)
{
    if (p.getSeatRow() < 1 || p.getSeatRow() > number_of_rows)
    {
        error_message = "Invalid row number.";
        return false;
    }
    if (p.getSeatLetter() < 'A' || p.getSeatLetter() >= 'A' + seats_per_row)
    {
        error_message = "Invalid seat letter.";
        return false;
    }
    for (const Passenger &check : passengers)
    {
        if (check.getSeatRow() == p.getSeatRow() && check.getSeatLetter() == p.getSeatLetter())
        {
            error_message = "That seat is already taken.";
            return false;
        }
    }
    passengers.push_back(p);
    return true;
}

bool Flight::removePassenger(int id, std::string &error_message)
{
    for (size_t i = 0; i < passengers.size(); i++)
    {
        if (passengers[i].getId() == id)
        {
            std::cout << "\nPassenger " << passengers[i].getFirstName() << " " << passengers[i].getLastName()
                      << " was successfully removed from flight " << flight_code << ".\n";
            passengers.erase(passengers.begin() + i);
            return true;
        }
    }
    error_message = "Passenger ID not found on this flight.";
    return false;
}