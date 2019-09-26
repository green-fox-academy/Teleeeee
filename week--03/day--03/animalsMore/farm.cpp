//
// Created by User on 25/09/2019.
//

#include "farm.h"
#include "animals.h"

farm::farm(int slots) {
    _slots = slots;
}

void farm::slaughter(){
    int leastHungriest = _cattle[0].getHunger();
    int indexOfLeastHungriest = 0;
    for(int i =0; i < _cattle.size(); i++){
        if(leastHungriest > _cattle[i].getHunger()){
            leastHungriest = _cattle[i].getHunger();
            indexOfLeastHungriest = i;
        }
    }
    _cattle.erase(_cattle.begin()+indexOfLeastHungriest);
}


void farm::breed(){
    for(int i =0; i < _slots; i++) {
        if (_slots > 0) {
            _cattle.emplace_back();
        }
    }
}

void farm::addAnimal(Animals& o){
    _cattle.emplace_back(o);
}