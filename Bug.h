#ifndef C_CA2_BUG_H
#define C_CA2_BUG_H
//
// Created by roryo on 11/04/2024.
//
#include <utility>
#include <list>
using namespace std;

class Bug {
protected:
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int,int>> path;

   virtual void move() =0;

     bool isWayBlocked() ;
};

#endif //C_CA2_BUG_H
