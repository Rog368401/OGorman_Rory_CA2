//
// Created by roryo on 11/04/2024.
//
#include "Hopper.h"
#include<iostream>
using namespace std;


void  Hopper::move(){

    while (isWayBlocked())
    {



        if (direction==Direction::North){
            position.first-= hopLength;
        } else if (direction==Direction::East){
            position.first+= hopLength;
        } else if (direction==Direction::South){
            position.second-= hopLength;
        } else if (direction==Direction::West){
            position.second+= hopLength;
        }
// change direction
    }

// now move in current direction


}



