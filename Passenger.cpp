// Passenger.cpp
// ENSF 337 Term Project - Group 7


// Implement the Passenger member functions declared in Passenger.h.

#include "Passenger.h"
#include <iostream>

Passenger::Passenger(int id,
                     const std::string& first,
                     const std::string& last,
                     const std::string& phone,
                     int row,
                     char letter)
    : passenger_id(id),
      first_name(first),
      last_name(last),
      phone_number(phone),
      seat_row(row),
      seat_letter(letter)
{
}

int Passenger::getId() const { return passenger_id; }

std::string Passenger::getFirstName() const { return first_name; }

std::string Passenger::getLastName() const { return last_name; }

std::string Passenger::getPhoneNumber() const { return phone_number; }

int Passenger::getSeatRow() const { return seat_row; }

char Passenger::getSeatLetter() const { return seat_letter; }

void Passenger::print() const
{
    std::cout << passenger_id << "  "
              << first_name << "  "
              << last_name << "  "
              << phone_number << "  "
              << seat_row << "  "
              << seat_letter << std::endl;
}