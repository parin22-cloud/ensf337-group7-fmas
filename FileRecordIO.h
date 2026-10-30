#ifndef FILE_RECORD_IO_H
#define FILE_RECORD_IO_H

#include <string>
#include <vector>

struct FlightRecord {
    std::string flight_code;
    std::string origin;
    std::string destination;
    int number_of_rows;
    int seats_per_row;
};

struct PassengerRecord {
    std::string flight_code;
    int passenger_id;
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    int seat_row;
    char seat_letter;
};

bool readFlightRecords(const std::string& filename,
                       std::vector<FlightRecord>& records,
                       std::string& error_message);

bool readPassengerRecords(const std::string& filename,
                          std::vector<PassengerRecord>& records,
                          std::string& error_message);

bool writePassengerRecords(const std::string& filename,
                           const std::vector<PassengerRecord>& records,
                           std::string& error_message);

#endif
