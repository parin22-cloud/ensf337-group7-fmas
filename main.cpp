// main.cpp
// ENSF 337 Term Project - Group 7

// Create the program entry point in this file.
//
// Your main function should:
// - create the Airline object;
// - load flights.txt and passengers.txt;
// - keep track of the currently selected flight;
// - display the menu and read the user's choices;
// - call the appropriate Airline or Flight operation for each menu choice;
// - continue until the user chooses to quit.
#include <iostream>
#include <string>
#include <limits>

int main(){

    std::cout << "FMAS Version: 1.0\n";
    std::cout << "Term Project - Flight Management Application System\n";
    std::cout << "Produced by group: 7\n";
    std::cout << "Names: Parin Patel, Agastya Parashar, Aditya Patel\n\n";
    std::cout << "<<< Press Return to Continue>>>>\n";
    std::string Garb;
    std::getline(std::cin, Garb);

    int choice;
    do {
        std::cout << "Please select one of the following options:\n\n";
        std::cout << "  1. Display all flights.\n";
        std::cout << "  2. Select a flight.\n";
        std::cout << "  3. Display Flight Seat Map.\n";
        std::cout << "  4. Display Passengers Information.\n";
        std::cout << "  5. Add a New Passenger.\n";
        std::cout << "  6. Remove an Existing Passenger.\n";
        std::cout << "  7. Save data.\n";
        std::cout << "  8. Quit.\n\n";
        std::cout << "Enter your choice: (1, 2, 3, 4, 5, 6, 7, or 8) "; 
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(choice!= 8);







    return 0; 
}   