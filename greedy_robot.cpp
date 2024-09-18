#include "greedy_robot.h"
#include <algorithm>
#include <iostream>
#include <string>

// Default constructor initializes positions to zero and sets no paths.
GreedyRobot::GreedyRobot() : maximumDistance_(0), totalPaths_(0) {
    robotPosition_.x = robotPosition_.y = treasurePosition_.x = treasurePosition_.y = 0;
}

// Constructor that sets initial configuration.
GreedyRobot::GreedyRobot(int maximumDistance, int initialRobotX, int initialRobotY, int targetTreasureX, int targetTreasureY)
    : maximumDistance_(maximumDistance), totalPaths_(0) {
    robotPosition_.x = initialRobotX;
    robotPosition_.y = initialRobotY;
    treasurePosition_.x = targetTreasureX;
    treasurePosition_.y = targetTreasureY;
    initiatePathSearch(robotPosition_.x, robotPosition_.y, "");
}

// Setters for robot and treasure positions.
void GreedyRobot::setRobotPosition(int x, int y) {
    robotPosition_.x = x;
    robotPosition_.y = y;
}

void GreedyRobot::setTreasurePosition(int x, int y) {
    treasurePosition_.x = x;
    treasurePosition_.y = y;
}

void GreedyRobot::setMaxConsecutiveDistance(int max) {
    maximumDistance_ = max;
}

// Getters for robot and treasure positions.
int GreedyRobot::getMaxConsecutiveDistance() const {
    return maximumDistance_;
}

int GreedyRobot::getRobotX() const {
    return robotPosition_.x;
}

int GreedyRobot::getRobotY() const {
    return robotPosition_.y;
}

int GreedyRobot::getTreasureX() const {
    return treasurePosition_.x;
}

int GreedyRobot::getTreasureY() const {
    return treasurePosition_.y;
}

int GreedyRobot::getTotalPathsCount() const {
    return totalPaths_;
}

// Check methods for exceeding maximum allowed consecutive moves in any direction.
bool GreedyRobot::isDirectionMovementExceedingDistance(const std::string& path, char direction) {
    int count = 0;
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        if (*it == direction) {
            if (++count > maximumDistance_) return true;
        } else {
            break;
        }
    }
    return false;
}

bool GreedyRobot::isNorthMovementExceedingDistance(const std::string& path) {
    return isDirectionMovementExceedingDistance(path, 'N');
}

bool GreedyRobot::isSouthMovementExceedingDistance(const std::string& path) {
    return isDirectionMovementExceedingDistance(path, 'S');
}

bool GreedyRobot::isEastMovementExceedingDistance(const std::string& path) {
    return isDirectionMovementExceedingDistance(path, 'E');
}

bool GreedyRobot::isWestMovementExceedingDistance(const std::string& path) {
    return isDirectionMovementExceedingDistance(path, 'W');
}

// Function to compute new paths based on movement.
std::string GreedyRobot::calculateNewPathWithMovement(int& currentX, int& currentY, char moveDirection, const std::string& currentPath) {
    std::string newPath = currentPath + moveDirection;
    switch (moveDirection) {
        case 'N': currentY++; break;
        case 'S': currentY--; break;
        case 'E': currentX++; break;
        case 'W': currentX--; break;
    }
    return newPath;
}

// Explore all valid paths to the treasure.
void GreedyRobot::exploreAllPathsToTreasure(int currentX, int currentY, std::string path, bool checkOppositeDirection) {
    if (currentX == treasurePosition_.x && currentY == treasurePosition_.y) {
        if (isPathAlreadyDiscovered(path) == false) {
            discoveredPaths_.push_back(path);
            totalPaths_++;
        }
        return;
    }

    if (currentX < treasurePosition_.x && !isEastMovementExceedingDistance(path))
        exploreAllPathsToTreasure(currentX + 1, currentY, path + 'E', checkOppositeDirection);
    if (currentX > treasurePosition_.x && !isWestMovementExceedingDistance(path))
        exploreAllPathsToTreasure(currentX - 1, currentY, path + 'W', checkOppositeDirection);
    if (currentY < treasurePosition_.y && !isNorthMovementExceedingDistance(path))
        exploreAllPathsToTreasure(currentX, currentY + 1, path + 'N', checkOppositeDirection);
    if (currentY > treasurePosition_.y && !isSouthMovementExceedingDistance(path))
        exploreAllPathsToTreasure(currentX, currentY - 1, path + 'S', checkOppositeDirection);
}

// Initiates the search for paths.
void GreedyRobot::initiatePathSearch(int startX, int startY, const std::string& initialPath) {
    exploreAllPathsToTreasure(startX, startY, initialPath, false);
}

// Search alternative paths.
void GreedyRobot::searchAlternativePaths(int startX, int startY, const std::string& initialPath) {
    exploreAllPathsToTreasure(startX, startY, initialPath, true);
}

// Check if a path has already been discovered.
bool GreedyRobot::isPathAlreadyDiscovered(const std::string& path) {
    return std::find(discoveredPaths_.begin(), discoveredPaths_.end(), path) != discoveredPaths_.end();
}

// Display all discovered paths.
void GreedyRobot::displayAllPaths() {
    for (const auto& path : discoveredPaths_) {
        std::cout << path << std::endl;
    }
}

// Comparison operators implementation.
bool GreedyRobot::operator==(const GreedyRobot& other) const {
    return totalPaths_ == other.totalPaths_;
}

bool GreedyRobot::operator!=(const GreedyRobot& other) const {
    return !(*this == other);
}

bool GreedyRobot::operator>=(const GreedyRobot& other) const {
    return totalPaths_ >= other.totalPaths_;
}

bool GreedyRobot::operator<=(const GreedyRobot& other) const {
    return totalPaths_ <= other.totalPaths_;
}

bool GreedyRobot::operator<(const GreedyRobot& other) const {
    return totalPaths_ < other.totalPaths_;
}

bool GreedyRobot::operator>(const GreedyRobot& other) const {
    return totalPaths_ > other.totalPaths_;
}
