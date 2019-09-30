//
// Created by User on 30/09/2019.
//

#include "Plant.h"



double Plant::getWaterlevel(){
    return _waterlevel;
}
void Plant::setWaterlevel(double water){
    _waterlevel = _waterlevel + water;
}

std::string Plant::getColor(){
    return _color;
}
std::string  Plant::getType(){
    return _type;
}
int Plant::getMaxWaterLevel(){
    return _maxWaterLevel;
}

