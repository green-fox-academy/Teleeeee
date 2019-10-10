#include "Movements.h"



bool Movements::moveAble(std::vector<std::vector<int>>* tiles, int k, int z){
    if((*tiles)[k + 5][z + 5] == 1){
        return false;
    }else{
        return true;
    }
}
