//
// Created by User on 30/09/2019.
//

#ifndef GARDENAPPLICATION_FLOWERS_H
#define GARDENAPPLICATION_FLOWERS_H

#include "string"
#include "Trees.h"

class Flowers {

public:

    double getWaterlevel();
    void setWaterlevel(double water);
    Flowers(std::string color);
    std::string getColor();

protected:

    double _waterlevel;
    std::string _color;

private:

};


#endif //GARDENAPPLICATION_FLOWERS_H
