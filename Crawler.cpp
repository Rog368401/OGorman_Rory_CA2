//
// Created by roryo on 11/04/2024.
//
#include "Crawler.h"
#include<iostream>

using namespace std;


void Crawler::move() {
    int x = this->position.first;
    int y = this->position.second;
    while (isWayBlocked()) {  //
        // change the direction
        //
        int random = 1 + (rand() % 4);
        // generate random 1 -4
        // us that to set new direction
        direction = static_cast<Direction>(random);
    }

    // move
    if (direction == Direction::North) {
        position.first -= 1;
    } else if (direction == Direction::East) {
        position.second += 1;
    } else if (direction == Direction::South) {
        position.first += 1;
    } else if (direction == Direction::West) {
        position.second -= 1;
    }

}

// now move in current direction

void Crawler::display() const {
    std::cout << "Crawler ";
    std::cout << "Bug ID: " << id << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Direction: ";
    switch (direction) {
        case Direction::North:
            std::cout << "North";
            break;
        case Direction::East:
            std::cout << "East";
            break;
        case Direction::South:
            std::cout << "South";
            break;
        case Direction::West:
            std::cout << "West";
            break;
    }
    std::cout << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Alive: " << (alive ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
}


Crawler::Crawler(int
                 id, std::pair<int, int>
                 position, Direction
                 direction, int
                 size, bool
                 alive) : Bug(id, position, direction, size, alive) {}


