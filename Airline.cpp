// Airline.cpp
// ENSF 337 Term Project - Group 7

// Implement the Airline member functions declared in Airline.h.
//
// Use the supplied FileRecordIO functions when loading and saving records.
// Convert the loaded FlightRecord and PassengerRecord values into the
// appropriate Flight and Passenger objects.
// Ensure each Passenger object is placed in the appropriate Flight object.

#include <iostream>
#include "Airline.h"
#include "FileRecordIO.h"
#include "Flight.h"


Flight* Airline::getFlightNumber(int number)
{
    if (number < 1 || number > static_cast<int>(flights.size()))
    {
        return nullptr;
    }
    return &flights[number - 1];

}

void Airline::displayFlights() const
{
    if (flights.empty())
    {
        std::cout << "There are no available flights";
        return;
    }

    std::cout << "List of available flights:";
    std::cout << "\n";

    for (int i = 0; i < static_cast<int>(flights.size()); i++)
    {
        std::cout << i + 1 << ".";
        std::cout << flights[i].getFlightCode() << " ";
        std::cout << flights[i].getOrigin() << " ";
        std::cout << flights[i].getDestination() << " ";
        std::cout << flights[i].getNumberOfRows() << " ";
        std::cout << flights[i].getSeatsPerRow() << "\n";

    }
}

Flight* Airline::findFlight(const std::string& flight_number)
{
    for(int i = 0; i < static_cast<int>(flights.size()); i++)
    {
        if (flight_number == flights[i].getFlightCode())
        {
            return &flights[i];
        }
    }
    return nullptr;
}



bool Airline::loadData(const std::string& flight_file, const std::string& passenger_file)
{
    std::vector<FlightRecord> flight_information;
    std::string error_message;

    if (!readFlightRecords(flight_file, flight_information, error_message ))
    {
        std::cout << error_message;
        std::cout << "\n";
        return false;
    }

    for (int i = 0; i < static_cast<int>(flight_information.size()); i++)
    {
        Flight new_Flight(flight_information[i].flight_code, flight_information[i].origin, flight_information[i].destination, flight_information[i].number_of_rows, flight_information[i].seats_per_row);
        flights.push_back(new_Flight);
            
    }

    std::vector<PassengerRecord> passenger_information;

    if (!readPassengerRecords(passenger_file, passenger_information, error_message))
    {
        std::cout << error_message << "\n";
        return false;
    }

    for (int i = 0; i < static_cast<int>(passenger_information.size()); i++)
    {
        Flight* selected_flight = findFlight(passenger_information[i].flight_code);
        if (selected_flight == nullptr)
        {
            std::cout << "This flight does not exist" << "\n";
            return false;
        }

        Passenger new_passenger(
            passenger_information[i].passenger_id,
            passenger_information[i].first_name,
            passenger_information[i].last_name,
            passenger_information[i].phone_number,
            passenger_information[i].seat_row,
            passenger_information[i].seat_letter
        );

        if (!selected_flight->addPassenger(new_passenger))
        {
            return false;
        }
    }
    return true;

}

bool Airline::savePassengerData(const std::string& passenger_data_file)
{
    std::vector<PassengerRecord> passenger_info;
    std::string error_message;

    for (int i = 0; i < static_cast<int>(flights.size()); i++)
    {
        const std::vector<Passenger>& passengers = flights[i].getPassengers();
        for (int j = 0; j < static_cast<int>(passengers.size()); j++)
        {
            struct PassengerRecord record;
            record.flight_code = flights[i].getFlightCode();
            record.passenger_id = passengers[j].getId();
            record.first_name = passengers[j].getFirstName();
            record.last_name = passengers[j].getLastName();
            record.phone_number = passengers[j].getPhoneNumber();
            record.seat_row = passengers[j].getSeatRow();
            record.seat_letter = passengers[j].getSeatLetter();

            passenger_info.push_back(record);
        }
    }

    if (!writePassengerRecords(passenger_data_file, passenger_info, error_message ))
    {
        std::cout << error_message << "\n";
        return false;
    }
    return true;

}

bool Airline::passengerIdExists(int passengerId) const
{
    for(int i = 0; i < static_cast<int>(flights.size()); i++)
    {
        const std::vector<Passenger>& passengers = flights[i].getPassengers();
        for(int j = 0; j < static_cast<int>(passengers.size()); j++)
        {
            if (passengerId == passengers[j].getId())
            {
                return true;
            }

        }
    }

    return false;
}

















