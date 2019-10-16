#ifndef WANDERERLIKEGAME_MOVEMENTS_H
#define WANDERERLIKEGAME_MOVEMENTS_H


#include <vector>
#include "DrawableElement.h"
#include "SDL.h"
#include "Draw.h"

class Movements : public Draw {
public:

    bool moveAble(std::vector<std::vector<int>>* tiles, int k , int z);
    void changeTile(std::vector<std::vector<int>>* tiles, int k, int z);
    void generalButtonMovements(std::vector<std::vector<int>>* tiles, int* k, int* z, bool* menu,bool* firstRun , SDL_Event*e);
    void changeTileWithMouseClick(int k, int z, std::vector<std::vector<int>>* map, SDL_Event* e);
    void menuHandling(SDL_Renderer* renderer,bool* firstRun, bool* menu,bool* quit, SDL_Event* e);
    void goForInnerMap(DrawableElement ZoliBacsi, bool* innerGame, int k, int z,std::vector<std::vector<int>>* map);
    void heroInnerMapMovement(SDL_Renderer* renderer, DrawableElement* Zolibacsi, std::vector<std::vector<int>>* innerMap, bool* innerGame);


private:


};


#endif //WANDERERLIKEGAME_MOVEMENTS_H
