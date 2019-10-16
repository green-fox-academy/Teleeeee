#include "Movements.h"



bool Movements::moveAble(std::vector<std::vector<int>>* tiles, int k, int z){
    if((*tiles)[k + 5][z + 5] == 98){
        return true;
    }
    return (*tiles)[k + 5][z + 5] == 0;
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
        if(mouseX > 200 || mouseY > 50) {
            (*map)[mouseY / 100 + k + 1][mouseX / 100 + z + 1] = 98;
        }
    }

}
void Movements::menuHandling(SDL_Renderer* renderer, bool* firstRun, bool* menu, bool* quit, SDL_Event* e){

}

void Movements::goForInnerMap(DrawableElement ZoliBacsi, bool* innerGame, int k, int z,std::vector<std::vector<int>>* map){
    if((*map)[ZoliBacsi.getYOnDrawtable() + k + 1][ZoliBacsi.getXOnDrawtable()+ z + 1] == 98){
        *innerGame = true;
    }
}

void Movements::heroInnerMapMovement(SDL_Renderer* renderer, DrawableElement* Zolibacsi, std::vector<std::vector<int>>* innerMap, bool* innerGame){
    SDL_Event e;
    if(SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case (SDLK_UP):
                    if(Zolibacsi->getYOnDrawtable() > 0){
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable() - 1][Zolibacsi->getXOnDrawtable()] == 0) {
                            Zolibacsi->changeByYOnDrawtable(-1);
                        }
                    }
                    break;
                case (SDLK_DOWN):
                    if(Zolibacsi->getYOnDrawtable() < 9) {
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable() + 1][Zolibacsi->getXOnDrawtable()] == 0){
                            Zolibacsi->changeByYOnDrawtable(+1);
                        }
                    }
                    break;
                case (SDLK_RIGHT):
                    if(Zolibacsi->getXOnDrawtable() < 9) {
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable()][Zolibacsi->getXOnDrawtable() + 1] == 0){
                            Zolibacsi->changeByXOnDrawtable(+1);
                        }
                    }
                    break;
                case (SDLK_LEFT):
                    if(Zolibacsi->getXOnDrawtable() > 0) {
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable()][Zolibacsi->getXOnDrawtable() - 1] == 0){
                            Zolibacsi->changeByXOnDrawtable(-1);
                        }
                    }
                    break;
                case (SDLK_ESCAPE):
                    *innerGame = false;
                    Zolibacsi->setXAndYOnDrawtable(5,5);
                    break;
            }
        }
    }
    draw(renderer, Zolibacsi, 100);
}
