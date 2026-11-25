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
#include <cctype>
#include "Flight.h"
#include "Passenger.h"

void pressReturn()
{
    std::cout << "<<< Press Return to Continue>>>>";
    std::string input_garbage;
    std::getline(std::cin, input_garbage);
}

int readInt()
{
    int value;
    std::cin >> value;
    if(std::cin.eof()){
        return 8;
    }
    if (std::cin.fail())
    {
        std::cin.clear();
        value = -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

bool flightSelected(int selected_flight)
{
    if (selected_flight == -1)
    {
        std::cout << "Please select a flight first (option 2).\n";
        return false;
    }
    return true;
}

int main()
{

    std::cout << "FMAS Version: 1.0\n";
    std::cout << "Term Project - Flight Management Application System\n";
    std::cout << "Produced by group: 7\n";
    std::cout << "Names: Parin Patel, Agastya Parashar, Aditya Patel\n\n";
    pressReturn();

    int choice;
    int selected_flight = -1;
    std::string flight_file = "flights.txt";
    std::string passenger_file = "passengers.txt";

    do
    {
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
        choice = readInt();

        switch (choice)

        {
        case 1:
        {
            std::cout << "Option 1 not done yet.\n";
            pressReturn();
            break;
        }

        case 2:
        {
            std::cout << "Enter the flight number: ";
            int flight_number = readInt();

            if (flight_number == -1)
            {
                std::cout << "Invalid flight number.\n";
            }
            else
            {
                selected_flight = flight_number;
                std::cout << "You picked flight " << flight_number << ".\n";
            }

            pressReturn();
            break;
        }

        case 3:
        {
            if (!flightSelected(selected_flight))
            {
                pressReturn();
                break;
            }
            std::cout << "Option 3 not done yet.\n";
            pressReturn();
            break;
        }

        case 4:
        {
            if (!flightSelected(selected_flight))
            {
                pressReturn();
                break;
            }
            std::cout << "Option 4 not done yet.\n";
            pressReturn();
            break;
        }

        case 5:
        {
            if (!flightSelected(selected_flight))
            {
                pressReturn();
                break;
            }

            std::cout << "Please enter the passenger id: ";
            int id = readInt();
            if (id <= 0)
            {
                std::cout << "Invalid passenger ID.\n";
                pressReturn();
                break;
            }

            std::string first, last, phone;
            std::cout << "Please enter the passenger first name: ";
            std::cin >> first;
            std::cout << "Please enter the passenger last name: ";
            std::cin >> last;
            std::cout << "Please enter the passenger phone number: ";
            std::cin >> phone;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter the passenger's desired row: ";
            int row = readInt();
            if (row <= 0)
            {
                std::cout << "Invalid row.\n";
                pressReturn();
                break;
            }

            std::cout << "Enter the passenger's desired seat: ";
            char seat;
            std::cin >> seat;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            seat = std::toupper(static_cast<unsigned char>(seat));

            // TODO once Airline/Flight are merged:
            // if (airline.idExists(id))  -> "Passenger ID already exists."
            // else flight.addPassenger(Passenger(id, first, last, phone, row, seat));
            std::cout  << "Passenger " << first << " " << last
                       << " was added to flight " << "FLIGHT_CODE" << ".\n";

            break;
        }

        case 6:
        {
            if (!flightSelected(selected_flight))
            {
                pressReturn();
                break;
            }
            std::cout << "Please enter the id of the passenger that needs to be removed: ";
            int passenger_id = readInt();

            if (passenger_id == -1)
            {
                std::cout << "Invalid passenger ID.\n";
            }
            else
            {
                std::cout << "Would remove passenger " << passenger_id << ".\n";
            }

            pressReturn();
            break;
        }

        case 7:
        {
            char save_answer;
            while (true)
            {
                std::cout << "Save the updated passenger data to " << passenger_file << "? (Y or N) ";
                std::cin >> save_answer;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                save_answer = std::toupper(static_cast<unsigned char>(save_answer));
                if (save_answer == 'Y' || save_answer == 'N')
                    break;
                std::cout << "Invalid response. Please enter Y or N.\n";
            }

            if (save_answer == 'Y')
            {
                // TODO: uncomment once Airline is merged
                // std::string error;
                // if (airline.savePassengerData(passenger_file, error))                
                //     std::cout << "All passenger data was saved successfully.\n";
                // else
                //     std::cout << "Error: " << error << '\n';
                std::cout << "Would save now.\n";
            }
            else
            {
                std::cout << "Changes were not saved.\n";
            }

            pressReturn();
            break;
        }

        case 8:
        {
            std::cout << "Program terminated.\n";
            break;
        }

        default:
        {
            std::cout << "Invalid Choice.\n";
            pressReturn();
            break;
        }
        }
    } while (choice != 8);

    return 0;
}