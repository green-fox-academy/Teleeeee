//
// Created by User on 25/09/2019.
//

#include "animals.h"

void Animals::eat(){
    _hunger = _hunger - 1;
}

void Animals::drink(){
    _thirst = _thirst - 1;
}

void Animals::play(){
    _hunger = _hunger + 1;
    _thirst = _thirst + 1;
}

int Animals::getHunger()const {
    return _hunger;
}

int Animals::getThirst() const {
    return _thirst;
}

Animals::Animals() {
    _hunger = 50 ;
    _thirst = 50 ;

}