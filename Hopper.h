#ifndef C_CA2_HOPPER_H
#define C_CA2_HOPPER_H
//
// Created by roryo on 11/04/2024.
//


#include "Bug.h"

class Hopper: public Bug {
    int hopLength;
public:
    Hopper(int id, int x, int y, Direction direction, int size, bool alive, int hop_distance)
            : Bug{id, {x, y}, direction, size, alive}, hopLength(hop_distance) {
    }

    void move() override;
    void display() const override {
        std::cout << "Hopper ";
        std::cout << "Bug ID: " << id << std::endl;
        std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
        std::cout << "Direction: ";
        switch(direction) {
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
        std::cout << "Hop Length: " << hopLength << std::endl;
        std::cout << std::endl;
    }

};
#endif //C_CA2_HOPPER_H
