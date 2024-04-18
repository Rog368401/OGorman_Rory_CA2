#ifndef C_CA2_BUG_H
#define C_CA2_BUG_H

#include <utility>
#include <list>

// Define Direction enum class
enum class Direction {
    North,
    East,
    South,
    West
};

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;

    virtual void move() = 0;

    bool isWayBlocked();
};

#endif //C_CA2_BUG_H
