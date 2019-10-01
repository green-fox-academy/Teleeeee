#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


#include "Animals.h"

class Mammal : public Animals {
public:
    Mammal(std::string name);
    virtual std::string breed() override ;
    std::string getName();

protected:

};


#endif //ZOO_MAMMAL_H
