#ifndef WANDERERLIKEGAME_MOVEMENTS_H
#define WANDERERLIKEGAME_MOVEMENTS_H


#include <vector>
#include "DrawableElement.h"
#include "SDL.h"
#include "Draw.h"
#include "map"

class Movements : public Draw {

public:

    Movements(SDL_Renderer *renderer);

    bool moveAble(std::vector<std::vector<int>>* tiles, int k , int z);
    void changeTile(std::vector<std::vector<int>>* tiles, int k, int z);
    void generalButtonMovements(std::vector<std::vector<int>>* tiles, int* k, int* z, bool* menu,bool* firstRun , SDL_Event*e);
    void changeTileWithMouseClick(int k, int z, std::vector<std::vector<int>>* map, SDL_Event* e);
    void menuHandling(bool* firstRun, bool* menu,bool* quit, SDL_Event* e);
    void goForInnerMap(DrawableElement ZoliBacsi, bool* innerGame, int k, int z,std::vector<std::vector<int>>* map);
    void heroInnerMapMovement(DrawableElement* Zolibacsi, std::vector<std::vector<int>>* innerMap, bool* innerGame, DrawableElement* firstEnemy, DrawableElement* secondEnemy,
                              DrawableElement* thirdEnemy, int* timer,  std::map<DrawableElement* , int>* inventory, std::vector<DrawableElement*>* allObject);
    void innerMapEnemyMovement(std::vector<std::vector<int>>* innerMap, DrawableElement* enemy);
    void timerBomb(std::vector<std::vector<int>>* innerMap, int timer);
    void changeTileInnerMap(std::vector<std::vector<int>>* innerMap, std::map<DrawableElement* , int>* inventory, std::vector<DrawableElement*>* allObject, SDL_Event* e);


private:


};


#endif //WANDERERLIKEGAME_MOVEMENTS_H
