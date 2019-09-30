//
// Created by User on 30/09/2019.
//

#include "Flowers.h"

Flowers::Flowers(std::string color){
    _color = color;
    _waterlevel = 0;
    std::string _type = "flower";
    _maxWaterLevel = 5;
}
void Flowers::setWaterlevel(double water){
    _waterlevel = _waterlevel + water* 0.75;
}