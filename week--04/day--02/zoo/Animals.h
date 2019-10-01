//
// Created by User on 01/10/2019.
//

#ifndef ZOO_ANIMALS_H
#define ZOO_ANIMALS_H


#include <string>

class Animals {
public:
    Animals(std::string name);

    std::string virtual getName() = 0;
    std::string virtual breed() = 0;


protected:
    int _age;
    std::string _name;
    std::string gender;
    int hunger;
    int thirst;


};


#endif //ZOO_ANIMALS_H
