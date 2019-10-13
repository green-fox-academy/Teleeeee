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

void Movements::generalButtonMovements(std::vector<std::vector<int>>* map, int* k, int* z, bool* quit){

}
