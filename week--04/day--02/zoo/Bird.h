#ifndef ZOO_BIRD_H
#define ZOO_BIRD_H


#include "Animal.h"
#include "Reptile.h"

class Bird : virtual public Animal, public Reptile {
public:
    Bird(std::string name);


protected:

};


#endif //ZOO_BIRD_H
