//
// Created by User on 30/09/2019.
//

#ifndef GARDENAPPLICATION_GARDEN_H
#define GARDENAPPLICATION_GARDEN_H


#include <vector>
#include "Trees.h"
#include "Flowers.h"

class Garden {
public:

    void wateringWith40();
    void wateringWith70();
    void needsWatering();
    void addFlowers(Flowers* flower);
    void addTrees(Trees* tree);

private:

    std::vector<Trees* > _trees;
    std::vector<Flowers*> _flowers;


};


#endif //GARDENAPPLICATION_GARDEN_H
