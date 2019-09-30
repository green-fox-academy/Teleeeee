//
// Created by User on 30/09/2019.
//

#include "Trees.h"

double Trees::getWaterlevel(){
    return _waterlevel;
}
void  Trees::setWaterlevel(double water){
    _waterlevel = _waterlevel + water* 0.4;
}

Trees::Trees(std::string color){
    _color = color;
    _waterlevel = 0;
    std::string _type = "trees";
}

std::string Trees::getColor(){
    return _color;
}