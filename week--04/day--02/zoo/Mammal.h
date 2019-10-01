#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


#include "Animal.h"

class Mammal : public Animal {
public:
    Mammal(std::string name);
    virtual std::string breed() override ;
    std::string getName();

protected:

};


#endif //ZOO_MAMMAL_H
