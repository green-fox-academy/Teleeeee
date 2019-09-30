//
// Created by User on 30/09/2019.
//

#include "Flowers.h"


Flowers::Flowers(std::string color ){
    _color = color;
    _waterlevel = 0;
}

double Flowers::getWaterlevel(){
    return _waterlevel;
}
void Flowers::setWaterlevel(double water){
    _waterlevel = _waterlevel + water* 0.75;
}

std::string Flowers::getColor(){
    return _color;
}