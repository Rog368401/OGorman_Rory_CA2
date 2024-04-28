#ifndef C_CA2_CRAWLER_H
#define C_CA2_CRAWLER_H
//
// Created by roryo on 11/04/2024.
//



#include "Bug.h"

class Crawler: public Bug {


public:
    Crawler(int id, int x, int y, Direction direction, int size, bool alive)
            : Bug{id, {x, y}, direction, size, alive} {

    }

    virtual int getID() const override {
        return id;
    }
    void move() override;
    void display() const override ;
private:
    Crawler(int id, std::pair<int, int> position, Direction direction, int size, bool alive);



};

#endif //C_CA2_CRAWLER_H
