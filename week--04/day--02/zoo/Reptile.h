#ifndef ZOO_REPTILE_H
#define ZOO_REPTILE_H


#include "Animal.h"

class Reptile : virtual public Animal {
public:
    Reptile(std::string name);
    std::string breed();
    std::string getName();


protected:


};


#endif //ZOO_REPTILE_H
