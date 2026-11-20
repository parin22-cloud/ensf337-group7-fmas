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

void pressReturn(){
    std::cout << "<<< Press Return to Continue>>>>";
    std::string inputGarbage;
    std::getline(std::cin, inputGarbage);
}

int main(){

    std::cout << "FMAS Version: 1.0\n";
    std::cout << "Term Project - Flight Management Application System\n";
    std::cout << "Produced by group: 7\n";
    std::cout << "Names: Parin Patel, Agastya Parashar, Aditya Patel\n\n";
    pressReturn();

    int choice;
    do {
        std::cout << "\nPlease select one of the following options:\n\n";
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
        if (std::cin.fail()){
            std::cin.clear();
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)

        {
        case 1:
            std::cout << "Option 1 not done yet.\n";
            pressReturn();
            break;
        case 2:
            std::cout << "Option 2 not done yet.\n";
            pressReturn();
            break;
        case 3:
            std::cout << "Option 3 not done yet.\n";
            pressReturn();
            break;
        case 4:
            std::cout << "Option 4 not done yet.\n";
            pressReturn();
            break;
        case 5:
            std::cout << "Option 5 not done yet.\n";
            break;
        case 6:
            std::cout << "Option 6 not done yet.\n";
            pressReturn();
            break;
        case 7:
            std::cout << "Option 7 not done yet.\n";
            pressReturn();
            break;
        case 8:
            std::cout << "Program terminated.\n";
            break;
        
        default:
            std::cout << "Invalid Choice.\n";
            pressReturn();    
            break;
        }
    } while(choice!= 8);






    return 0; 
}   