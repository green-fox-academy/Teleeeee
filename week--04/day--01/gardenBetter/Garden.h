//
// Created by User on 30/09/2019.
//

#ifndef GARDENBETTER_GARDEN_H
#define GARDENBETTER_GARDEN_H

#include <vector>
#include "Trees.h"
#include "Flowers.h"

class Garden {
public:

    void wateringWith40();
    void wateringWith70();
    void needsWatering();
    void addPlants(Plant* plant);


private:

    std::vector<Plant* > _plants;


};



#endif //GARDENBETTER_GARDEN_H
