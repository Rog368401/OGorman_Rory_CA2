//
// Created by roryo on 08/04/2024.
//
#include "Bug.h"
#include<iostream>
#include <utility>
#include <list>

using namespace std;

void Bug::move() {

    while (isWayBlocked())
    {
        if (direction==Direction::North){
            direction=Direction::East;
        } else if (direction==Direction::East){
            direction=Direction::South;
        } else if (direction==Direction::South){
            direction=Direction::West;
        } else if (direction==Direction::West){
            direction=Direction::North;
        }
        // change direction
    }

// now move in current direction


}
bool Bug::isWayBlocked() {
    int x = this->position.first;
    int y = this->position.second;


    if (x == 0 && direction == Direction::North) {
        return true;
    } else if (x == 10 && direction == Direction::South) {
        return true;
    } else if (y == 0 && direction == Direction::West) {
        return true;
    } else if (y == 10 && direction == Direction::East) {
        return true;
    }


    return false;
}




