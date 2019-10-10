#ifndef WANDERERLIKEGAME_DRAW_H
#define WANDERERLIKEGAME_DRAW_H

#include <SDL_render.h>
#include "DrawableElement.h"

class Draw {

public:

    void draw(SDL_Renderer* renderer,DrawableElement* figure);
    void animation(SDL_Renderer* renderer, DrawableElement* figure);
    void SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor,DrawableElement* kfc, DrawableElement* Cartmen, int k, int z, std::vector<std::vector<int>> tiles  );
    void drawFromSheet(SDL_Renderer *renderer, DrawableElement* figure, int onTheSheetX , int ontheSheetY, int widht, int height );
    std::vector<std::vector<int>> generateMap();

private:




};


#endif //WANDERERLIKEGAME_DRAW_H
