#include <map>
#include "Movements.h"



Movements::Movements(SDL_Renderer *renderer) : Draw(renderer) {}

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
            (*map)[mouseY / 100 + k + 1 ][mouseX / 100 + z + 1 ] = 98;
        }
    }

}
void Movements::menuHandling(bool* firstRun, bool* menu, bool* quit, SDL_Event* e){

}

void Movements::goForInnerMap(DrawableElement ZoliBacsi, bool* innerGame, int k, int z,std::vector<std::vector<int>>* map){
    if((*map)[ZoliBacsi.getYOnDrawtable() + k + 1][ZoliBacsi.getXOnDrawtable()+ z + 1 ] == 98){
        *innerGame = true;
    }
}

void Movements::heroInnerMapMovement(DrawableElement* Zolibacsi, std::vector<std::vector<int>>* innerMap, bool* innerGame, DrawableElement* firstEnemy, DrawableElement* secondEnemy,
        DrawableElement* thirdEnemy, int* timer,  std::map<DrawableElement* , int>* inventory, std::vector<DrawableElement*>* allObject){
    SDL_Event e;
    if(SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case (SDLK_UP):
                    if(Zolibacsi->getYOnDrawtable() > 0){
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable() - 1][Zolibacsi->getXOnDrawtable()] == 2) {
                            Zolibacsi->changeByYOnDrawtable(-1);
                            *timer += 1;
                        }
                        innerMapEnemyMovement(innerMap, firstEnemy);
                        innerMapEnemyMovement(innerMap, secondEnemy);
                        innerMapEnemyMovement(innerMap, thirdEnemy);
                    }
                    break;
                case (SDLK_DOWN):
                    if(Zolibacsi->getYOnDrawtable() < 9) {
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable() + 1][Zolibacsi->getXOnDrawtable()] == 2){
                            Zolibacsi->changeByYOnDrawtable(+1);
                            *timer += 1;
                        }
                        innerMapEnemyMovement(innerMap,firstEnemy);
                        innerMapEnemyMovement(innerMap, secondEnemy);
                        innerMapEnemyMovement(innerMap, thirdEnemy);
                    }
                    break;
                case (SDLK_RIGHT):
                    if(Zolibacsi->getXOnDrawtable() < 9) {
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable()][Zolibacsi->getXOnDrawtable() + 1] == 2){
                            Zolibacsi->changeByXOnDrawtable(+1);
                            *timer += 1;
                        }
                        innerMapEnemyMovement(innerMap, firstEnemy);
                        innerMapEnemyMovement(innerMap, secondEnemy);
                        innerMapEnemyMovement(innerMap, thirdEnemy);
                    }
                    break;
                case (SDLK_LEFT):
                    if(Zolibacsi->getXOnDrawtable() > 0) {
                        if ((*innerMap)[Zolibacsi->getYOnDrawtable()][Zolibacsi->getXOnDrawtable() - 1] == 2){
                            Zolibacsi->changeByXOnDrawtable(-1);
                            *timer += 1;
                        }
                        innerMapEnemyMovement(innerMap, firstEnemy);
                        innerMapEnemyMovement(innerMap, secondEnemy);
                        innerMapEnemyMovement(innerMap, thirdEnemy);
                    }
                    break;
                case (SDLK_ESCAPE):
                    Zolibacsi->setXAndYOnDrawtable(5,5);
                    *innerGame = false;
                    break;
            }

        }
        changeTileInnerMap(innerMap, inventory, allObject, &e);
        timerBomb(innerMap, *timer);
    }

    draw( Zolibacsi,  100);
    draw( firstEnemy, 100);
    draw( secondEnemy,100);
    draw( thirdEnemy, 100);
}

void Movements::innerMapEnemyMovement( std::vector<std::vector<int>>* innerMap, DrawableElement* enemy){
    switch (rand()%4) {
        case (0):
            if (enemy->getYOnDrawtable() > 0) {
                if ((*innerMap)[enemy->getYOnDrawtable() - 1][enemy->getXOnDrawtable()] == 2) {
                    enemy->changeByYOnDrawtable(-1);
                }
            }
            break;
        case (1):
            if (enemy->getYOnDrawtable() < 9) {
                if ((*innerMap)[enemy->getYOnDrawtable() + 1][enemy->getXOnDrawtable()] == 2) {
                    enemy->changeByYOnDrawtable(+1);
                }
            }
            break;
        case (2):
            if (enemy->getXOnDrawtable() < 9) {
                if ((*innerMap)[enemy->getYOnDrawtable()][enemy->getXOnDrawtable() + 1] == 2) {
                    enemy->changeByXOnDrawtable(+1);
                }
            }
            break;
        case (3):
            if (enemy->getXOnDrawtable() > 0) {
                if ((*innerMap)[enemy->getYOnDrawtable()][enemy->getXOnDrawtable() - 1] == 2) {
                    enemy->changeByXOnDrawtable(-1);
                }
            }
            break;
    }
}

void Movements::timerBomb(std::vector<std::vector<int>>* innerMap, int timer){
    if(timer == 2) {
        for (int i = 0; i < 10 ; ++i) {
            for (int j = 0; j < 10; ++j) {
                if ((*innerMap)[i][j] == 96) {
                    (*innerMap)[i][j] = 2;
                }
            }
        }
    }
}

void Movements::changeTileInnerMap(std::vector<std::vector<int>>* innerMap, std::map<DrawableElement* , int>* inventory, std::vector<DrawableElement*>* allObject, SDL_Event* e){
    std::map<DrawableElement*, int>::iterator it;
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX > 200 || mouseY > 50) {
            for (int j = 0; j < allObject->size() ; ++j) {
                if((*innerMap)[mouseY / 100 ][mouseX / 100 ] == (*allObject)[j]->getInventoryId() ) {
                    it =(*inventory).find((*allObject)[j]);
                    if (!it->second) {
                        inventory->emplace(std::pair<DrawableElement *, int>((*allObject)[j], 1));
                        (*innerMap)[mouseY / 100][mouseX / 100] = 2;
                    }
                }
            }
        }
    }
}
