//
// Created by roryo on 08/04/2024.
//
#include "Bug.h"
#include<iostream>
#include <utility>
#include <list>

using namespace std;

bool Bug::isWayBlocked() {
    int x = this->position.first;
    int y = this->position.second;

    // Check if the bug is about to hit a boundary
    if (x == 9 && direction == Direction::North) {
        return true;
    } else if (x == 0 && direction == Direction::South) {
        return true;
    } else if (y == 9 && direction == Direction::West) {
        return true;
    } else if (y == 0 && direction == Direction::East) {
        return true;
    }

    return false;
}

void Bug::move() {
    cout << "Current position: (" << position.first << ", " << position.second << ")" << endl;
    if (!isWayBlocked()) {
        cout << "Way is blocked." << endl;
        // Change direction when hitting a boundary
        switch (direction) {
            case Direction::North:
                direction = Direction::South;
                break;
            case Direction::East:
                direction = Direction::West;
                break;
            case Direction::South:
                direction = Direction::North;
                break;
            case Direction::West:
                direction = Direction::East;
                break;
        }
        cout << "New direction: ";
        switch (direction) {
            case Direction::North:
                cout << "North" << endl;
                break;
            case Direction::East:
                cout << "East" << endl;
                break;
            case Direction::South:
                cout << "South" << endl;
                break;
            case Direction::West:
                cout << "West" << endl;
                break;
        }
    } else {
        // Move in the current direction
        int x = this->position.first;
        int y = this->position.second;

        // Move according to the current direction
        switch (direction) {
            case Direction::North:
                position.first -= 1;
                break;
            case Direction::East:
                position.second += 1;
                break;
            case Direction::South:
                position.first += 1;
                break;
            case Direction::West:
                position.second -= 1;
                break;
        }

        // Ensure position stays within bounds
        position.first = max(0, min(position.first, 9));
        position.second = max(0, min(position.second, 9));
        cout << "Moved to: (" << position.first << ", " << position.second << ")" << endl;
    }
}

