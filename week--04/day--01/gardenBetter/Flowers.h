//
// Created by User on 30/09/2019.
//

#ifndef GARDENBETTER_FLOWERS_H
#define GARDENBETTER_FLOWERS_H


#include "Plant.h"

class Flowers : public Plant {
public:
    Flowers(std::string color);
    void setWaterlevel(double water) ;

private:



};


#endif //GARDENBETTER_FLOWERS_H
