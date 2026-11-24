// Flight.cpp
// ENSF 337 Term Project - Group 7

// Implement the Flight member functions declared in Flight.h.
//
// Build the seat map from this flight's dimensions and passenger information.
// Implement the passenger display, addition and removal operations here.

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

std::string Flight::getFlightCode() const {
    return flight_code;
}

std::string Flight::getOrigin() const {
    return origin;
}

std::string Flight::getDestination() const {
    return destination;
}

int Flight::getNumberOfRows() const {
    return number_of_rows;
}

int Flight::getSeatsPerRow() const {
    return seats_per_row;
}

const std::vector<Passenger>& Flight::getPassengers() const {
    return passengers;
}

bool Flight::addPassenger(const Passenger& passenger) {
    int row = passenger.getSeatRow();
    char seat = passenger.getSeatLetter();

    if (row < 1 || row > number_of_rows ||
        seat < 'A' || seat >= 'A' + seats_per_row) {
        return false;
    }

    for (int i = 0; i < static_cast<int>(passengers.size()); i++) {
        if (passengers[i].getId() == passenger.getId()) {
            return false;
        }

        if (passengers[i].getSeatRow() == row &&
            passengers[i].getSeatLetter() == seat) {
            return false;
        }
    }

    passengers.push_back(passenger);
    return true;
}

bool Flight::removePassenger(int passengerId) {
    for (int i = 0; i < static_cast<int>(passengers.size()); i++) {
        if (passengers[i].getId() == passengerId) {
            passengers.erase(passengers.begin() + i);
            return true;
        }
    }

    return false;
}

void Flight::displaySeatMap() const {
    std::vector<std::vector<char>> seatMap(
        number_of_rows,
        std::vector<char>(seats_per_row, '-')
    );

    for (int i = 0; i < static_cast<int>(passengers.size()); i++) {
        int row = passengers[i].getSeatRow() - 1;
        int seat = passengers[i].getSeatLetter() - 'A';

        seatMap[row][seat] = 'X';
    }

    std::cout << "Aircraft Seat Map\n    ";

    for (int j = 0; j < seats_per_row; j++) {
        std::cout << static_cast<char>('A' + j) << "   ";
    }

    std::cout << '\n';

    for (int i = 0; i < number_of_rows; i++) {
        std::cout << std::setw(2) << i + 1 << "  ";

        for (int j = 0; j < seats_per_row; j++) {
            std::cout << seatMap[i][j] << "   ";
        }

        std::cout << '\n';
    }
}

void Flight::displayPassengers() const {
    std::cout << "Passenger List (Flight: "
              << flight_code << " from "
              << origin << " to "
              << destination << ")\n\n";

    if (passengers.empty()) {
        std::cout << "No passengers on this flight.\n";
        return;
    }

    for (int i = 0; i < static_cast<int>(passengers.size()); i++) {
        passengers[i].print();
    }
}
