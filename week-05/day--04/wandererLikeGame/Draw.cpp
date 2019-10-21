#include <vector>
#include <SDL_timer.h>
#include "Draw.h"


Draw::Draw(SDL_Renderer *renderer) : _renderer(renderer) {}

void Draw::draw(DrawableElement* figure, int side) {
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_RenderCopy(_renderer, figure->getTexture(), NULL, &dstrect);

}
void Draw::drawFromSheet(DrawableElement* figure, int onTheSheetX , int ontheSheetY, int widht, int height, int side){
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    SDL_Rect cutrect = {onTheSheetX, ontheSheetY, widht, height};
    SDL_RenderCopy(_renderer, figure->getTexture(), &cutrect, &dstrect);
}
void Draw::SetMap( DrawableElement* Hero, std::vector<DrawableElement*>* allObject, int k , int z, std::vector<std::vector<int>> tiles, int side, int zoom ) {

    if (Hero->getXOnDrawtable() + z > 0 && Hero->getYOnDrawtable() - 5 + k > 0 &&
            Hero->getXOnDrawtable() - 5 + z < 500 && Hero->getYOnDrawtable() - 5 + k < 500) {

        for (int i = -1 + z; i < 11 + z + zoom; ++i) {

            for (int j = -1 + k; j < 11 + k + zoom; ++j) {
                for (int l = 0; l < (*allObject).size() ; ++l) {
                    (*allObject)[l]->setXAndYOnDrawtable(i - z + Hero->getXOnDrawtable() - 5,
                                                         j - k + Hero->getYOnDrawtable() - 5);
                }

                for(int k = 0; k < (*allObject).size() ; k++ ) {
                    if (tiles[j][i] == (*allObject)[k]->getInventoryId()) {
                        draw((*allObject)[k], side);
                    }
                }

            }
        }
    }
    for (int l = 0; l < (*allObject).size() ; ++l) {
        (*allObject)[l]->resetXandYtoZero();
    }
}

std::vector<std::vector<int>> Draw::generateMap(int size){
    std::vector<std::vector<int>> tiles(size, std::vector<int>(size, 0));
    for (int i = 0; i < size ; ++i) {
        for (int k = 0; k < size ; ++k) {
            if(size > 10){
            if (rand()%10 == 1) {
                tiles.at(i).at(k) = 1;
                }
                if (rand() % 30 == 1) {
                    tiles.at(i).at(k) = 5;
                }
            }
            if(size == 10) {
                if (rand() % 3 == 1) {
                    tiles.at(i).at(k) = 3;
                }else{
                    tiles.at(i).at(k) = 2;
                }
                //if (rand() % 10 == 2) {
                //    tiles.at(i).at(k) = 96;
                //}
            }
        }
    }
    return  tiles;
}

void Draw::animation( DrawableElement* figure, int side){
    int lastTime = 0;
    SDL_Rect dstrect = {figure->getXOnDrawtable() * side, figure->getYOnDrawtable() * side, side, side};
    int currentTime = 0;
    int i = 0;
    while(i < 2 ){
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 100) {
            lastTime = currentTime;
            SDL_Rect cutrect = {0 + i * 38, 165, 38, 42};
            SDL_RenderCopy(_renderer, figure->getAnimation(), &cutrect, &dstrect);
            SDL_RenderPresent(_renderer);
            i++;
        }
    }
}

void Draw::menuBackground(){
    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(_renderer,0,0,0,255);
    SDL_Rect rect = {0,0,1000,1000};
    SDL_RenderFillRect(_renderer,&rect);
}

void Draw::writeOnTheScreen(int x , int y, std::string text){
    TTF_Font* font =TTF_OpenFont( "Laffayette_Comic_Pro.ttf", 40);
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Blended( font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface( _renderer, textSurface );
    SDL_Rect dstrect = { x,  y, 200, 100};
    SDL_RenderCopy(_renderer, texture, NULL, &dstrect);
}

void Draw::mainMenu(){
    writeOnTheScreen(350, 100, "Close");
    writeOnTheScreen(350, 250, "New game");
    writeOnTheScreen(350, 400, "Load last");
    writeOnTheScreen(350, 550, "Save");
}

void Draw::inventory(std::map<DrawableElement*, int>* inventory){
    int counter = 0;
    for (std::pair<DrawableElement*, int> it : *inventory) {
        it.first->setXAndYOnDrawtable(counter, 0);
        draw(it.first, 50);
        counter++;
    }
}

void Draw::generateInnerMap(std::vector<std::vector<int>>* innerMap, std::vector<DrawableElement*>* allObject){
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10 ; ++j) {
            for(int k = 0; k < (*allObject).size() ; k++ ){
                if((*innerMap)[i][j] == (*allObject)[k]->getInventoryId() ){
                    (*allObject)[k]->setXAndYOnDrawtable(j,i);
                    draw((*allObject)[k], 100);
                }
            }
        }
    }
}


