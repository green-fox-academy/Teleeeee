#include <vector>
#include "Draw.h"



void Draw::draw(SDL_Renderer *renderer, DrawableElement* figure) {
    int side = 50;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_RenderCopy(renderer, figure->getTexture(), NULL, &dstrect);

}

void Draw::SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor, DrawableElement* Cartmen, int k , int z, std::vector<std::vector<int>> tiles ){

    if(Cartmen->getXOnDrawtable() + z  > 0 && Cartmen->getYOnDrawtable() - 5 + k > 0 && Cartmen->getXOnDrawtable() - 5 + z  < 5000 && Cartmen->getYOnDrawtable() - 5 + k < 5000 ) {

        for ( int i = Cartmen->getXOnDrawtable() - 5  + z ; i < 7 + Cartmen->getXOnDrawtable() + z; ++i) {

            for (int j = Cartmen->getYOnDrawtable() - 5 + k ; j < 7 + Cartmen->getYOnDrawtable() + k; ++j) {

                wall->setXOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5 );
                wall->setYOnDrawtable(j -k + Cartmen->getYOnDrawtable() - 5 );
                floor->setXOnDrawtable(i - z  + Cartmen->getXOnDrawtable() - 5);
                floor->setYOnDrawtable(j - k + Cartmen->getYOnDrawtable() - 5);
                if (tiles[j][i] == 0) {
                    draw(renderer, floor);
                } else {
                    draw(renderer, wall);
                }
            }
        }
    }
    wall->setXOnDrawtable(0);
    wall->setYOnDrawtable(0);
    floor->setXOnDrawtable(0);
    floor->setYOnDrawtable(0);
}

std::vector<std::vector<int>> Draw::generateMap(){
    std::vector<std::vector<int>> tiles  (5000, std::vector<int>(5000, 0));
    for (int i = 0; i < 5000 ; ++i) {
        for (int k = 0; k < 5000 ; ++k) {
            if (rand()%5 == 1) {
                tiles.at(i).at(k) = 1;
            }
            }
    }
    return  tiles;
}