//
// Created by User on 30/09/2019.
//

#ifndef GARDENBETTER_TREES_H
#define GARDENBETTER_TREES_H


#include "Plant.h"

class Trees : public Plant {
public:
    Trees(std::string color);
    void virtual setWaterlevel(double water);

private:

};


#endif //GARDENBETTER_TREES_H
