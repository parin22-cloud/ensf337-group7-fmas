// Airline.h
// ENSF 337 Term Project - Group 7

// Declare the Airline class in this file.
//
// Store the collection of Flight objects.
// Declare the operations shown in the project class diagram for loading data,
// displaying flights, finding a flight and saving passenger data.
// Add any private helper functions needed by your design.

#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <vector>
#include "Flight.h"

class Airline{
    private:
        std::vector<Flight> flights;
        std::string name;

    public:
        // Displays all the flights
        void displayFlights() const;
        
        bool loadData(const std::string& flight_file, const std::string& passenger_file);

        bool savePassengerData(const std::string& passenger_data_file);

        Flight* findFlight(const std::string& flight_number);

        Flight* getFlightNumber(int number);

        bool passengerIdExists(int passengerId) const;
        
};

#endif