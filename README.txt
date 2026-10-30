ENSF 337 Term Project Starter Files

The supplied FileRecordIO files contain the C++ stream operations required to
read the flight and passenger records and to write passenger records. The
remaining Airline, Flight, Passenger, menu and seat-map work is not
implemented for you.

Comment-only files for main, Airline, Flight and Passenger are included to show
the expected multi-file structure. Complete those files as part of the project.

Use readFlightRecords and readPassengerRecords from Airline::loadData. Convert
the returned records into your Flight and Passenger objects. When saving, build
a vector of PassengerRecord values from all flights and pass it to
writePassengerRecords.

The supplied flights.txt and passengers.txt form the first input set.

Your team must create flights_test2.txt and passengers_test2.txt. The second
set must use different values, contain at least two valid flights and at least
four valid passengers across at least two flights, and contain no duplicate
passenger IDs or duplicate occupied seats on the same flight.

Your finished program must work with either pair by changing only the filenames
passed to the loading functions. Do not hard-code records from either input set.
