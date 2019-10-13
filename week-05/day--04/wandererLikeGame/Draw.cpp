#include <vector>
#include <SDL_timer.h>
#include "Draw.h"



void Draw::draw(SDL_Renderer *renderer, DrawableElement* figure, int side) {
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_RenderCopy(renderer, figure->getTexture(), NULL, &dstrect);

}
void Draw::drawFromSheet(SDL_Renderer *renderer, DrawableElement* figure, int onTheSheetX , int ontheSheetY, int widht, int height, int side){
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_Rect cutrect = {onTheSheetX, ontheSheetY, widht, height};
    SDL_RenderCopy(renderer, figure->getTexture(), &cutrect, &dstrect);
}
void Draw::SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor, DrawableElement* kfc,  DrawableElement* Cartmen, int k , int z, std::vector<std::vector<int>> tiles, int side ){

    if(Cartmen->getXOnDrawtable() + z  > 0 && Cartmen->getYOnDrawtable() - 5 + k > 0 && Cartmen->getXOnDrawtable() - 5 + z  < 500 && Cartmen->getYOnDrawtable() - 5 + k < 500 ) {

        for ( int i = Cartmen->getXOnDrawtable() - 5  + z ; i <7  + Cartmen->getXOnDrawtable() + z; ++i) {

            for (int j = Cartmen->getYOnDrawtable() - 5 + k ; j < 7 + Cartmen->getYOnDrawtable() + k ; ++j) {

                wall->setXOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5 );
                wall->setYOnDrawtable(j -k + Cartmen->getYOnDrawtable() - 5 );
                floor->setXOnDrawtable(i - z  + Cartmen->getXOnDrawtable() - 5);
                floor->setYOnDrawtable(j - k + Cartmen->getYOnDrawtable() - 5);
                kfc->setXOnDrawtable(i - z  + Cartmen->getXOnDrawtable() - 5);
                kfc->setYOnDrawtable(j - k + Cartmen->getYOnDrawtable() - 5);
                if (tiles[j][i] == 0) {
                    drawFromSheet(renderer, floor, 107, 33, 31, 31, side);
                }
                if(tiles[j][i] == 1){
                    drawFromSheet(renderer, wall, 173, 0, 31, 31, side);
                }
                if(tiles[j][i] == 2){
                    drawFromSheet(renderer, wall, 371, 231, 31, 31, side);
                }
                if(tiles[j][i] == 3){
                    //drawFromSheet(renderer, wall, 107, 231, 31, 31, side);
                    drawFromSheet(renderer, kfc, 0, 0, 440,337, side);
                    //draw(renderer, kfc);
                }
            }
        }
    }
    wall->setXOnDrawtable(0);
    wall->setYOnDrawtable(0);
    floor->setXOnDrawtable(0);
    floor->setYOnDrawtable(0);
    kfc->setXOnDrawtable(0);
    kfc->setYOnDrawtable(0);
}

std::vector<std::vector<int>> Draw::generateMap(){
    std::vector<std::vector<int>> tiles  (500, std::vector<int>(500, 0));
    for (int i = 0; i < 500 ; ++i) {
        for (int k = 0; k < 500 ; ++k) {
            if (rand()%10 == 1) {
                tiles.at(i).at(k) = 1;
            }
            if(rand()%30 == 1){
                tiles.at(i).at(k) = 2;
            }
        }
    }
    return  tiles;
}

void Draw::animation(SDL_Renderer* renderer, DrawableElement* figure, int side){
    int lastTime = 0;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    int currentTime = 0;
    int i = 0;
    while(i < 2 ){
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 100) {
            lastTime = currentTime;
            SDL_Rect cutrect = {0 + i * 38, 165, 38, 42};
            SDL_RenderCopy(renderer, figure->getAnimation(), &cutrect, &dstrect);
            SDL_RenderPresent(renderer);
            i++;
        }
    }
}

void Draw::menuBackground(SDL_Renderer* renderer){
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_Rect rect = {0,0,1000,1000};
    SDL_RenderFillRect(renderer,&rect);
}

void Draw::writeOnTheScreen(SDL_Renderer* renderer , int x , int y, std::string text){
    TTF_Font* font =TTF_OpenFont( "Laffayette_Comic_Pro.ttf", 50);
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Surface* textSurface = TTF_RenderText_Blended( font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
    SDL_Rect dstrect = { x,  y, 120, 100};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

void Draw::mainMenu(SDL_Renderer* renderer){
    writeOnTheScreen(renderer,400, 100, "quit");
    writeOnTheScreen(renderer,400, 250, "new");
    writeOnTheScreen(renderer,400, 400, "last");
}