#ifndef C_CA2_HOPPER_H
#define C_CA2_HOPPER_H
//
// Created by roryo on 11/04/2024.
//


#include "Bug.h"

class Hopper: public Bug {

    int hopLength;
    void move() override;

};
#endif //C_CA2_HOPPER_H
