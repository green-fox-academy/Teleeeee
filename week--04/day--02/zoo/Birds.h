#ifndef ZOO_BIRDS_H
#define ZOO_BIRDS_H


#include "Animals.h"
#include "Reptile.h"

class Birds : virtual public Animals, public Reptile {
public:
    Birds(std::string name);


protected:

};


#endif //ZOO_BIRDS_H
