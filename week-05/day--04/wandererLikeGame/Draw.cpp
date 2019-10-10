#include <vector>
#include "Draw.h"



void Draw::draw(SDL_Renderer *renderer, DrawableElement* figure) {
    int side = 20;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_RenderCopy(renderer, figure->getTexture(), NULL, &dstrect);

}

void Draw::SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor, DrawableElement* Cartmen, int k , int z){
    std::vector<std::vector<int>> tiles =  {{0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
                                            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
                                            {0,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,1,0,0},
                                            {0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
                                            {1,0,1,1,0,0,1,1,1,0,1,0,1,1,0,0,1,1,1,0},
                                            {0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0},
                                            {0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0},
                                            {1,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0},
                                            {0,0,0,1,0,1,1,0,1,0,0,0,0,1,0,1,1,0,1,0},
                                            {0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
                                            {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
                                            {0,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,1,0,0},
                                            {0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
                                            {1,0,1,1,0,0,1,1,1,0,1,0,1,1,0,0,1,1,1,0},
                                            {0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0},
                                            {0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0},
                                            {1,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0},
                                            {0,0,0,1,0,1,1,0,1,0,0,0,0,1,0,1,1,0,1,0}};


    if(Cartmen->getXOnDrawtable() + z  > 0 && Cartmen->getYOnDrawtable() - 4 + k > 0 && Cartmen->getXOnDrawtable() - 4 + z  < 20 && Cartmen->getYOnDrawtable() - 4 + k < 20 ) {
        for ( int i = Cartmen->getXOnDrawtable()  + z ; i < 7 + Cartmen->getXOnDrawtable() + z; ++i) {
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
