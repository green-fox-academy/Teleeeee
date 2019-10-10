#include <vector>
#include <SDL_timer.h>
#include "Draw.h"



void Draw::draw(SDL_Renderer *renderer, DrawableElement* figure) {
    int side = 50;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_RenderCopy(renderer, figure->getTexture(), NULL, &dstrect);

}
void Draw::drawFromSheet(SDL_Renderer *renderer, DrawableElement* figure, int onTheSheetX , int ontheSheetY, int widht, int height){
    int side = 50;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_Rect cutrect = {onTheSheetX, ontheSheetY, widht, height};
    SDL_RenderCopy(renderer, figure->getTexture(), &cutrect, &dstrect);
}
void Draw::SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor, DrawableElement* kfc,  DrawableElement* Cartmen, int k , int z, std::vector<std::vector<int>> tiles ){

    if(Cartmen->getXOnDrawtable() + z  > 0 && Cartmen->getYOnDrawtable() - 5 + k > 0 && Cartmen->getXOnDrawtable() - 5 + z  < 5000 && Cartmen->getYOnDrawtable() - 5 + k < 5000 ) {

        for ( int i = Cartmen->getXOnDrawtable() - 5  + z ; i < 7 + Cartmen->getXOnDrawtable() + z; ++i) {

            for (int j = Cartmen->getYOnDrawtable() - 5 + k ; j < 7 + Cartmen->getYOnDrawtable() + k; ++j) {

                wall->setXOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5 );
                wall->setYOnDrawtable(j -k + Cartmen->getYOnDrawtable() - 5 );
                floor->setXOnDrawtable(i - z  + Cartmen->getXOnDrawtable() - 5);
                floor->setYOnDrawtable(j - k + Cartmen->getYOnDrawtable() - 5);
                kfc->setXOnDrawtable(i - z  + Cartmen->getXOnDrawtable() - 5);
                kfc->setYOnDrawtable(j - k + Cartmen->getYOnDrawtable() - 5);
                if (tiles[j][i] == 0) {
                    drawFromSheet(renderer, floor, 107, 33, 31, 31);
                }
                if(tiles[j][i] == 1){
                    drawFromSheet(renderer, wall, 173, 0, 31, 31);
                }
                if(tiles[j][i] == 2){
                    drawFromSheet(renderer, wall, 371, 231, 31, 31);
                }
                if(tiles[j][i] == 3){
                    //drawFromSheet(renderer, wall, 107, 231, 31, 31);
                    drawFromSheet(renderer, kfc, 0, 0, 440,337);
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
    std::vector<std::vector<int>> tiles  (5000, std::vector<int>(5000, 0));
    for (int i = 0; i < 5000 ; ++i) {
        for (int k = 0; k < 5000 ; ++k) {
            if (rand()%5 == 1) {
                tiles.at(i).at(k) = 1;
            }
            if(rand()%10 == 1){
                tiles.at(i).at(k) = 2;
            }
        }
    }
    return  tiles;
}

//TODO: animation
void Draw::animation(SDL_Renderer* renderer, DrawableElement* figure){
    int side = 50;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    for (int i = 0; i < 3; ++i) {
        SDL_Delay(100);
        SDL_Rect cutrect = {74 + i * 38, 167, 38, 45};
        SDL_RenderCopy(renderer, figure->getAnimation(), &cutrect, &dstrect);
        SDL_RenderPresent(renderer);
    }

}