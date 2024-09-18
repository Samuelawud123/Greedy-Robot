/**
 * @brief The GreedyRobot class represents a robot navigating on a grid towards a designated treasure.
 *        It can move up (N), down (S), left (W), or right (E) and must reach a target position on the grid.
 *        This class enforces constraints on the number of consecutive movements the robot can make in any single direction,
 *        making the movement strategy more complex and not just the shortest path.
 *
 *        The robot is initialized with a starting position, a treasure position, and a maximum number of consecutive movements allowed
 *        in one direction. Once initialized, the robot calculates all possible paths to the treasure that adhere to these constraints.
 *        
 *        This class is designed to be used in scenarios where pathfinding needs to consider constraints on movement direction and frequency,
 *        which could be useful in real-world applications like automated warehouse management where paths might need to consider traffic flow
 *        or zones with restricted movements.
 *
 * Preconditions:
 *      - The coordinates for the robot and treasure must be non-negative integers within the bounds of the assumed grid size.
 *      - The maximum number of consecutive movements (maxDistance) should be a positive integer.
 *      - Proper values must be provided during the object instantiation; otherwise, the robot's behavior is undefined.
 *
 * Postconditions:
 *      - After initialization, the robot calculates all the valid paths based on the provided constraints.
 *      - All paths can be retrieved and displayed, showing all the possible ways the robot can reach the treasure while adhering to the movement limits.
 *      - The class provides detailed diagnostics that can be output to standard output to verify the correct paths are being calculated.
 *
 * Author: Samuel Awud
 */


#ifndef GREEDY_ROBOT_H
#define GREEDY_ROBOT_H

#include <iostream>
#include <vector>
#include <string>

// Structure to represent coordinates on a grid.
struct Coordinate {
    int x; // Horizontal position
    int y; // Vertical position
};

// Class definition for GreedyRobot which manages pathfinding for a robot navigating towards a treasure.
class GreedyRobot {
public:
    // Default constructor, initializes positions to zero and no paths.
    GreedyRobot();

    // Constructor that initializes the robot with the maximum distance for consecutive moves,
    // start position of the robot, and the position of the treasure.
    GreedyRobot(int maximumDistance, int initialRobotX, int initialRobotY, int targetTreasureX, int targetTreasureY);

    // Setters for updating the robot's and treasure's positions and the maximum consecutive movement limit.
    void setRobotPosition(int x, int y);
    void setTreasurePosition(int x, int y);
    void setMaxConsecutiveDistance(int max);

    // Getters for retrieving the robot's and treasure's positions, maximum consecutive movement limit, and total paths count.
    int getMaxConsecutiveDistance() const;
    int getRobotX() const;
    int getRobotY() const;
    int getTreasureX() const;
    int getTreasureY() const;
    int getTotalPathsCount() const;

    // Checks if the movement in any direction exceeds the maximum allowed consecutive moves.
    bool isNorthMovementExceedingDistance(const std::string& path);
    bool isSouthMovementExceedingDistance(const std::string& path);
    bool isWestMovementExceedingDistance(const std::string& path);
    bool isEastMovementExceedingDistance(const std::string& path);
    bool isDirectionMovementExceedingDistance(const std::string& path, char direction);

    // Path calculation and exploration functions.
    std::string calculateNewPathWithMovement(int& currentX, int& currentY, char moveDirection, const std::string& currentPath);
    void exploreAllPathsToTreasure(int currentX, int currentY, std::string path, bool checkOppositeDirection);
    void initiatePathSearch(int startX, int startY, const std::string& initialPath);
    void searchAlternativePaths(int startX, int startY, const std::string& initialPath);
    bool isPathAlreadyDiscovered(const std::string& path);
    void displayAllPaths();

    // Operator overloads for comparisons.
    bool operator==(const GreedyRobot& other) const;
    bool operator!=(const GreedyRobot& other) const;
    bool operator>=(const GreedyRobot& other) const;
    bool operator<=(const GreedyRobot& other) const;
    bool operator<(const GreedyRobot& other) const;
    bool operator>(const GreedyRobot& other) const;

private:
    Coordinate robotPosition_;  // Current position of the robot.
    Coordinate treasurePosition_;  // Position of the treasure.
    std::vector<std::string> discoveredPaths_;  // Collection of all valid paths from robot to treasure.
    int maximumDistance_;  // Maximum number of consecutive movements allowed in one direction.
    int totalPaths_;  // Total number of valid paths discovered.
};

#endif // GREEDY_ROBOT_H
