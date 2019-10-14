#ifndef WANDERERLIKEGAME_DRAW_H
#define WANDERERLIKEGAME_DRAW_H

#include <SDL_render.h>
#include "DrawableElement.h"
#include "string"
#include <SDL_ttf.h>
#include "Resources.h"

class Draw : public Resources {

public:

    void draw(SDL_Renderer* renderer,DrawableElement* figure, int side);
    void animation(SDL_Renderer* renderer, DrawableElement* figure, int side);
    void SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor,DrawableElement* kfc, DrawableElement* senco,DrawableElement* kenwu,
            DrawableElement* Cartmen, int k, int z, std::vector<std::vector<int>> tiles, int side,int zoom);
    void drawFromSheet(SDL_Renderer *renderer, DrawableElement* figure, int onTheSheetX , int ontheSheetY, int widht, int height, int side );
    std::vector<std::vector<int>> generateMap();
    void menuBackground(SDL_Renderer* renderer);
    void writeOnTheScreen(SDL_Renderer* renderer , int x , int y, std::string text);
    void mainMenu(SDL_Renderer* renderer);
    void inventory(SDL_Renderer* renderer, DrawableElement* first, DrawableElement* second, DrawableElement* third, DrawableElement* fourth);

private:




};


#endif //WANDERERLIKEGAME_DRAW_H
