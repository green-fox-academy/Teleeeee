#ifndef WANDERERLIKEGAME_DRAW_H
#define WANDERERLIKEGAME_DRAW_H

#include <SDL_render.h>
#include "DrawableElement.h"

class Draw {

public:

    void draw(SDL_Renderer* renderer,DrawableElement* figure);
    void SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor, DrawableElement* Cartmen, int k, int z, std::vector<std::vector<int>> tiles  );
    std::vector<std::vector<int>> generateMap();

private:




};


#endif //WANDERERLIKEGAME_DRAW_H
