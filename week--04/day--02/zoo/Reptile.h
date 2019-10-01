#ifndef ZOO_REPTILE_H
#define ZOO_REPTILE_H


#include "Animals.h"

class Reptile : virtual public Animals {
public:
    Reptile(std::string name);
    std::string breed();
    std::string getName();


protected:


};


#endif //ZOO_REPTILE_H
