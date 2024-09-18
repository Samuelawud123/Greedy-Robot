#include "greedy_robot.h"
#include <cstdlib> // Include for atoi
#include <iostream>

using namespace std;

/**
 * Main function for testing the GreedyRobot class. This program takes command line
 * arguments to initialize the robot's and treasure's positions and the maximum number
 * of consecutive moves the robot can make in one direction.
 *
 * Usage: ./greedy_robot max_distance robot_x robot_y treasure_x treasure_y
 * Compile using: g++ robot_test.cpp greedy_robot.cpp -o greedy_robot
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return int Status code (0 for success).
 */
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is passed
    if (argc == 6) {
        // Parse command line arguments
        int maxDistance = atoi(argv[1]);
        int robotX = atoi(argv[2]);
        int robotY = atoi(argv[3]);
        int treasureX = atoi(argv[4]);
        int treasureY = atoi(argv[5]);

        // Output the input values for verification
        cout << "GreedyRobot initialized with:" << endl
             << "Max Distance: " << maxDistance << endl
             << "Robot Position: (" << robotX << ", " << robotY << ")" << endl
             << "Treasure Position: (" << treasureX << ", " << treasureY << ")" << endl;

        // Initialize the GreedyRobot object
        GreedyRobot robot(maxDistance, robotX, robotY, treasureX, treasureY);

        // Call displayAllPaths() to show all the paths found
        robot.displayAllPaths();
    } else {
        // Error message if the wrong number of arguments are provided
        cout << "Usage: ./greedy_robot max_distance robot_x robot_y treasure_x treasure_y" << endl;
    }

    return 0;
}
