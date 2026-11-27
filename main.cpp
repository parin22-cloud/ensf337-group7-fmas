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
#include "Airline.h"

void pressReturn()
{
    std::cout << "\n<<< Press Return to Continue>>>>";
    std::string input_garbage;
    std::getline(std::cin, input_garbage);
}

int readInt()
{
    int value;
    std::cin >> value;
    if (std::cin.eof())
    {
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

bool flightSelected(Flight *selected_flight)
{
    if (selected_flight == nullptr)
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
    std::cout << "Names: Parin Patel, Agastya Parashar, Aditya Patel\n";
    pressReturn();

    int choice;
    Flight *selected_flight = nullptr;
    ;
    std::string flight_file = "flights.txt";
    std::string passenger_file = "passengers.txt";

    Airline airline;

    if (!airline.loadData(flight_file, passenger_file))
    {
        std::cout << "Could not load the data files.";
        return -1;
    }

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
            airline.displayFlights();
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
                Flight *found = airline.findFlight(flight_number);
                if (found == nullptr)
                {
                    std::cout << "Invalid flight number.\n";
                }
                else
                {
                    selected_flight = found;
                    std::cout << "You have selected flight " << found->getFlightCode()
                              << " from " << found->getOrigin()
                              << " to " << found->getDestination() << ".\n";
                }
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
            selected_flight->displaySeatMap();
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
            selected_flight->displayPassengers();
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

            if (airline.passengerIdExists(id))
            {
                std::cout << "Passenger ID already exists.\n";
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

            Passenger new_passenger(id, first, last, phone, row, seat);
            std::string error;
            if (selected_flight->addPassenger(new_passenger, error))
            {
                std::cout << "Passenger " << first << " " << last
                          << " was added to flight " << selected_flight->getFlightCode() << ".\n";
            }
            else
            {
                std::cout << error << '\n';
                pressReturn();
            }

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
                std::string error;
                if (!selected_flight->removePassenger(passenger_id, error))
                {
                    std::cout << error << '\n';
                }
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
                if (airline.savePassengerData(passenger_file))
                    std::cout << "All passenger data was saved successfully.\n";
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