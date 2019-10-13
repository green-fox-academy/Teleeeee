#include "Movements.h"



bool Movements::moveAble(std::vector<std::vector<int>>* tiles, int k, int z){
    if((*tiles)[k + 5][z + 5] != 0 ){
        return false;
    }else{
        return true;
    }
}

void Movements::changeTile(std::vector<std::vector<int>>* tiles, int k, int z){
    (*tiles)[k + 4][z+ 5] = 3;
}

void Movements::generalButtonMovements(std::vector<std::vector<int>>* map, int* k, int* z, bool* menu,bool* firstRun, SDL_Event*e){

}

void Movements::changeTileWithMouseClick(int k, int z,std::vector<std::vector<int>>* map, SDL_Event* e){
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        (*map)[mouseY / 100 + k + 1][mouseX / 100 + z + 1] = 0;
    }

}
void Movements::menuHandling(SDL_Renderer* renderer, bool* firstRun, bool* menu, bool* quit, SDL_Event* e){

}
