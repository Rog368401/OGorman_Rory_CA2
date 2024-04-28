// Bug.h
#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>
#include <iostream>

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

public:
    // Constructor for Bug class
    Bug(int id, std::pair<int, int> position, Direction direction, int size, bool alive)
            : id(id), position(std::move(position)), direction(direction), size(size), alive(alive) {
    }

    virtual int getID() const {
        return id;
    }
    const std::list<std::pair<int,int>>& getPath() const {
        return path;
    }
    virtual ~Bug() {}


    virtual void move() = 0;
    virtual void display() const = 0;

    bool isWayBlocked() ;

};

#endif // BUG_H
