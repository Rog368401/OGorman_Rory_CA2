#include "Hopper.h"
#include <iostream>
using namespace std;

void Hopper::move() {
    // Keep changing direction until the way is not blocked
    while (isWayBlocked()) {
        int random = rand() % 4 + 1; // generate random 1 - 4
        // set new direction based on random number
        switch (random) {
            case 1:
                direction = Direction::North;
                break;
            case 2:
                direction = Direction::East;
                break;
            case 3:
                direction = Direction::South;
                break;
            case 4:
                direction = Direction::West;
                break;
        }
    }
    path.push_back(position);
    // Move with hopLength
    if (direction == Direction::North && position.first >= hopLength) {
        position.first -= hopLength;
    } else if (direction == Direction::East && position.second <= 9 - hopLength) {
        position.second += hopLength;
    } else if (direction == Direction::South && position.first <= 9 - hopLength) {
        position.first += hopLength;
    } else if (direction == Direction::West && position.second >= hopLength) {
        position.second -= hopLength;
    }
}

void Hopper::display() const {
    cout << "Hopper ";
    cout << "Bug ID: " << id << endl;
    cout << "Position: (" << position.first << ", " << position.second << ")" << endl;
    cout << "Direction: ";
    switch(direction) {
        case Direction::North:
            cout << "North";
            break;
        case Direction::East:
            cout << "East";
            break;
        case Direction::South:
            cout << "South";
            break;
        case Direction::West:
            cout << "West";
            break;
    }
    cout << endl;
    cout << "Size: " << size << endl;
    cout << "Alive: " << (alive ? "Yes" : "No") << endl;
    cout << "Path History:" << endl;
    // Display path history
    for (const auto& pos : path) {
        cout << "(" << pos.first << ", " << pos.second << ")" << endl;
    }
    cout << "Hop Length: " << hopLength << endl;
    cout << endl;
}
