#ifndef WANDERERLIKEGAME_DRAW_H
#define WANDERERLIKEGAME_DRAW_H

#include <SDL_render.h>
#include "DrawableElement.h"
#include "string"
#include <SDL_ttf.h>
#include "Resources.h"
#include "map"

class Draw : public Resources {

public:
    Draw(SDL_Renderer *renderer);

    void draw(DrawableElement* figure, int side);
    void animation( DrawableElement* figure, int side);
    void SetMap( DrawableElement* Hero, std::vector<DrawableElement*>* allObject, int k, int z, std::vector<std::vector<int>> tiles, int side,int zoom);
    void drawFromSheet( DrawableElement* figure, int onTheSheetX , int ontheSheetY, int widht, int height, int side );
    std::vector<std::vector<int>> generateMap(int size);
    void menuBackground();
    void writeOnTheScreen( int x , int y, std::string text);
    void mainMenu();
    void inventory(std::map<DrawableElement*, int>* inventory);
    void generateInnerMap( std::vector<std::vector<int>>* innerMap, std::vector<DrawableElement*>* allObject);


protected:

    SDL_Renderer* _renderer;

private:






};


#endif //WANDERERLIKEGAME_DRAW_H
