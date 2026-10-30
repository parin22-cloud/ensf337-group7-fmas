#include "FileRecordIO.h"

#include <fstream>

bool readFlightRecords(const std::string& filename,
                       std::vector<FlightRecord>& records,
                       std::string& error_message)
{
    std::ifstream input(filename);
    if (!input) {
        error_message = "Unable to open " + filename + " for reading.";
        return false;
    }

    records.clear();
    FlightRecord record;
    while (input >> record.flight_code
                 >> record.origin
                 >> record.destination
                 >> record.number_of_rows
                 >> record.seats_per_row) {
        records.push_back(record);
    }

    if (!input.eof()) {
        error_message = "Invalid flight record in " + filename + ".";
        records.clear();
        return false;
    }

    error_message.clear();
    return true;
}

bool readPassengerRecords(const std::string& filename,
                          std::vector<PassengerRecord>& records,
                          std::string& error_message)
{
    std::ifstream input(filename);
    if (!input) {
        error_message = "Unable to open " + filename + " for reading.";
        return false;
    }

    records.clear();
    PassengerRecord record;
    while (input >> record.flight_code
                 >> record.passenger_id
                 >> record.first_name
                 >> record.last_name
                 >> record.phone_number
                 >> record.seat_row
                 >> record.seat_letter) {
        records.push_back(record);
    }

    if (!input.eof()) {
        error_message = "Invalid passenger record in " + filename + ".";
        records.clear();
        return false;
    }

    error_message.clear();
    return true;
}

bool writePassengerRecords(const std::string& filename,
                           const std::vector<PassengerRecord>& records,
                           std::string& error_message)
{
    std::ofstream output(filename);
    if (!output) {
        error_message = "Unable to open " + filename + " for writing.";
        return false;
    }

    for (const PassengerRecord& record : records) {
        output << record.flight_code << ' '
               << record.passenger_id << ' '
               << record.first_name << ' '
               << record.last_name << ' '
               << record.phone_number << ' '
               << record.seat_row << ' '
               << record.seat_letter << '\n';
    }

    if (!output) {
        error_message = "Unable to finish writing " + filename + ".";
        return false;
    }

    error_message.clear();
    return true;
}
