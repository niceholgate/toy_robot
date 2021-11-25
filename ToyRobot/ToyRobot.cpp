
#include <iostream>
#include "Table.h"
#include <gtest/gtest.h>


// Parse a string to an integer, returning false upon failure
bool stringToIntDefaultZero(std::string& aString, int& aInt) {
    try {
        aInt = std::stoi(aString);
        return true;
    }
    catch (...) {
        return false;
    }
}

// Parse commands from prompt - PLACE command causes three sequential sub-prompts
bool parseCommand(std::string aCommand, Table* aTable) {
    // Initially assume command success, set to false if a failure occurs
    bool command_success = true;

    if (aCommand == "PLACE") {
        // Store inputs for X, Y, F
        std::string x_coord_str;
        std::string y_coord_str;
        int x_coord_int;
        int y_coord_int;
        std::string direction_str;

        std::cout << "Enter integer X position: ";
        std::getline(std::cin, x_coord_str);
        std::cout << "\nEnter integer Y position: ";
        std::getline(std::cin, y_coord_str);
        std::cout << "\nEnter 'S', 'E', 'W' direction (otherwise defaults to 'N'): ";
        std::getline(std::cin, direction_str);
        
        // Parse integer positions, failing the command if they do not parse successfully
        if (!stringToIntDefaultZero(x_coord_str, x_coord_int) ||
            !stringToIntDefaultZero(y_coord_str, y_coord_int)) {
            return false;
        }

        // Parse direction, defaulting to N if invalid input
        Direction direction = Direction::NORTH;
        if (direction_str == "S") {
            direction = Direction::SOUTH;
        }
        else if (direction_str == "E") {
            direction = Direction::EAST;
        }
        else if (direction_str == "W") {
            direction = Direction::WEST;
        }

        // Perform the PLACE command
        command_success = aTable->placeRobot(x_coord_int, y_coord_int, direction, false);
    }
    else if (aCommand == "MOVE") {
        command_success = aTable->getRobot()->move();
    }
    else if (aCommand == "LEFT") {
        command_success = aTable->getRobot()->left();
    }
    else if (aCommand == "RIGHT") {
        command_success = aTable->getRobot()->right();
    }
    else if (aCommand == "REPORT") {
        aTable->report(false);
    }
    else if (aCommand == "MAP") {
        aTable->report(true);
    }
    else {
        std::cout << "Unknown command '" + aCommand + "'.\n";
    }
    return command_success;
}

// Main command loop with initial option to perform tests
int main(int argc, char **argv) {

    // Print instructions
    std::cout << "Starting toy robot simulation.\n";
    std::cout << "Type 'TEST' to run tests, or make use of the following commands:\n";
    std::cout << "Available commands: PLACE          (place the robot at sequentially prompted position X, Y with direction F)\n";
    std::cout << "Available commands: MOVE           (move robot forwards one space)\n";
    std::cout << "Available commands: LEFT           (turn robot left)\n";
    std::cout << "Available commands: RIGHT          (turn robot right)\n";
    std::cout << "Available commands: REPORT         (report current robot position and direction)\n";
    std::cout << "Available commands: MAP            (as above, but also with graphical representation of the table)\n";
    std::cout << "Available commands: EXIT           (exit the program)\n\n";

    std::string command;
    std::getline(std::cin, command);

    // Run tests if requested
    if (command == "TEST") {
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
        // Pause
        std::getline(std::cin, command);
    }
    // Otherwise start a command loop with a 5x5 Table
    else {
        // Create a 5x5 Table
        Table table(5, 5);
        
        // Begin a loop, parsing commands until one is EXIT
        while (command != "EXIT") {

            // Parse then perform the current command, giving a message if a command fails
            if (!parseCommand(command, &table)) {
                std::cout << "Command failed.\n";
            }

            // Read in new command
            std::getline(std::cin, command);
        }
    }
    return 0;

}

