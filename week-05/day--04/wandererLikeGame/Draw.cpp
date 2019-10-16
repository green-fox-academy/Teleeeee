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
void Draw::SetMap(SDL_Renderer *renderer,  DrawableElement* wall, DrawableElement* floor, DrawableElement* kfc, DrawableElement* senco,DrawableElement* silverkratch,
                  DrawableElement* kenwu, DrawableElement* tomlossajt, DrawableElement* zsir, DrawableElement* mustar, DrawableElement* pennyLogo, DrawableElement* Cartmen, int k , int z, std::vector<std::vector<int>> tiles, int side, int zoom ) {

    if (Cartmen->getXOnDrawtable() + z > 0 && Cartmen->getYOnDrawtable() - 5 + k > 0 &&
        Cartmen->getXOnDrawtable() - 5 + z < 500 && Cartmen->getYOnDrawtable() - 5 + k < 500) {

        for (int i = -1 + z; i < 11 + z + zoom; ++i) {

            for (int j = -1 + k; j < 11 + k + zoom; ++j) {

                wall->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                          j - k + Cartmen->getYOnDrawtable() - 5);
                floor->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                           j - k + Cartmen->getYOnDrawtable() - 5);
                kfc->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                         j - k + Cartmen->getYOnDrawtable() - 5);
                senco->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                           j - k + Cartmen->getYOnDrawtable() - 5);
                silverkratch->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                                  j - k + Cartmen->getYOnDrawtable() - 5);
                kenwu->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                           j - k + Cartmen->getYOnDrawtable() - 5);
                tomlossajt->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                                j - k + Cartmen->getYOnDrawtable() - 5);
                zsir->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                          j - k + Cartmen->getYOnDrawtable() - 5);
                mustar->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                            j - k + Cartmen->getYOnDrawtable() - 5);
                pennyLogo->setXAndYOnDrawtable(i - z + Cartmen->getXOnDrawtable() - 5,
                                            j - k + Cartmen->getYOnDrawtable() - 5);
                if (tiles[j][i] == 0) draw(renderer, floor, side);
                if (tiles[j][i] == 1) draw(renderer, wall, side);
                if (tiles[j][i] == 2) draw(renderer, senco, side);
                if (tiles[j][i] == 3) drawFromSheet(renderer, kfc, 0, 0, 440, 337, side);
                if (tiles[j][i] == 4) draw(renderer, silverkratch, side);
                if (tiles[j][i] == 5) draw(renderer, kenwu, side);
                if (tiles[j][i] == 6) draw(renderer, tomlossajt, side);
                if (tiles[j][i] == 7) draw(renderer, zsir, side);
                if (tiles[j][i] == 8) draw(renderer, mustar, side);
                if (tiles[j][i] == 98) draw(renderer, pennyLogo, side);
            }
        }
    }
    wall->resetXandYtoZero();
    floor->resetXandYtoZero();
    kfc->resetXandYtoZero();
    senco->resetXandYtoZero();
    silverkratch->resetXandYtoZero();
    kenwu->resetXandYtoZero();
    tomlossajt->resetXandYtoZero();
    zsir->resetXandYtoZero();
    mustar->resetXandYtoZero();
    pennyLogo->resetXandYtoZero();
}

std::vector<std::vector<int>> Draw::generateMap(int size){
    std::vector<std::vector<int>> tiles  (size, std::vector<int>(size, 0));
    for (int i = 0; i < size ; ++i) {
        for (int k = 0; k < size ; ++k) {
            if(size > 10){
            if (rand()%10 == 1) {
                tiles.at(i).at(k) = 1;
                }
                if (rand() % 30 == 1) {
                    tiles.at(i).at(k) = 2;
                }
            }
            if(size == 10) {
                if (rand() % 3 == 1) {
                    tiles.at(i).at(k) = 1;
                }
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
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Blended( font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
    SDL_Rect dstrect = { x,  y, 300, 100};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

void Draw::mainMenu(SDL_Renderer* renderer){
    writeOnTheScreen(renderer,350, 100, "Hello hello Sziasztok!");
    writeOnTheScreen(renderer,350, 250, "Uj jatek");
    writeOnTheScreen(renderer,350, 400, "Regi hogyishijjak");
    writeOnTheScreen(renderer,350, 550, "Tedd el kesobbre!");
}

void Draw::inventory(SDL_Renderer* renderer, DrawableElement* first, DrawableElement* second, DrawableElement* third, DrawableElement* fourth){
    draw(renderer, first, 50);
    draw(renderer, second, 50);
    draw(renderer, third, 50);
    drawFromSheet(renderer, fourth, 320, 1, 69, 49, 50);;
}

void Draw::generateInnerMap(SDL_Renderer* renderer, std::vector<std::vector<int>>* innerMap, DrawableElement* floor, DrawableElement* wall){
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10 ; ++j) {
            floor->setXAndYOnDrawtable(j,i);
            wall->setXAndYOnDrawtable(j,i);
            if((*innerMap)[i][j] == 1) drawFromSheet(renderer, floor,470,297,31,31,100);
            if((*innerMap)[i][j] == 0) drawFromSheet(renderer, floor, 173,231,31,31,100);
        }
    }
}