//
// Created by roryo on 28/04/2024.
//

#ifndef CA2_SPIDER_H
#define CA2_SPIDER_H
#include "Bug.h"

class Spider : public Bug {

public:
    Spider(int id, int x, int y, Direction direction, int size, bool alive)
            : Bug{id, {x, y}, direction, size, alive} {

    }

    virtual int getID() const override {
        return id;
    }
    void move() override;
    void display() const override ;

};



#endif //CA2_SPIDER_H
