#ifndef WANDERERLIKEGAME_MOVEMENTS_H
#define WANDERERLIKEGAME_MOVEMENTS_H


#include <vector>
#include "DrawableElement.h"
#include "SDL.h"

class Movements {
public:

    bool moveAble(std::vector<std::vector<int>>* tiles, int k , int z);
    void changeTile(std::vector<std::vector<int>>* tiles, int k, int z);
    void generalButtonMovements(std::vector<std::vector<int>>* tiles, int* k, int* z, bool* quit);


private:


};


#endif //WANDERERLIKEGAME_MOVEMENTS_H
