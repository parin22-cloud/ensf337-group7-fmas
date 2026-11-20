FMAS - Flight Management Application System
ENSF 337 Term Project, Fall 2026
Group 7: Parin Patel, Agastya Parashar, Aditya Patel


Files
-----
Source files: main.cpp, Airline.h, Airline.cpp, Flight.h, Flight.cpp,
Passenger.h, Passenger.cpp, FileRecordIO.h, FileRecordIO.cpp

Data files: flights.txt and passengers.txt (given input set)
            flights_test2.txt and passengers_test2.txt (our test set)

Keep all of these in the same folder and run the program from that folder.


Windows
-------
Compile:
g++ -std=c++17 -Wall -Wextra main.cpp Airline.cpp Flight.cpp Passenger.cpp FileRecordIO.cpp -o fmas.exe

Run:
.\fmas.exe


macOS
-----
If clang++ is not installed, run this first:
xcode-select --install

Compile:
clang++ -std=c++17 -Wall -Wextra main.cpp Airline.cpp Flight.cpp Passenger.cpp FileRecordIO.cpp -o fmas

Run:
./fmas


Using the second input set
--------------------------
By default the program loads flights.txt and passengers.txt. To use our
test set, change the two filenames in main.cpp to flights_test2.txt and
passengers_test2.txt, then compile and run again.

Note: option 7 (Save data) overwrites the passenger file that was loaded.
