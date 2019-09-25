//
// Created by User on 25/09/2019.
//

#ifndef ANIMALSMORE_FARM_H
#define ANIMALSMORE_FARM_H

#include "vector"
#include "animals.h"


class farm {
public:
    farm(int slots);
    void breed();
    void slaughter();
    void addAnimal(Animals&);

private:
    std::vector<Animals> _cattle;
    int _slots;


};


#endif //ANIMALSMORE_FARM_H
