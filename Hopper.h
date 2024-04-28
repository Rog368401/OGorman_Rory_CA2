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
    virtual int getID() const override {
        return id;
    }

    void move() override;
    void display() const override ;

};
#endif //C_CA2_HOPPER_H
