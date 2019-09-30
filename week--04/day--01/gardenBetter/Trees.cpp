//
// Created by User on 30/09/2019.
//

#include "Trees.h"

Trees::Trees(std::string color){
    _color = color;
    _waterlevel = 0;
    std::string _type = "tree";
    _maxWaterLevel = 10;
}
void Trees::setWaterlevel(double water){
    _waterlevel = _waterlevel + water* 0.4;
}

