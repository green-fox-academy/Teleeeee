//
// Created by User on 01/10/2019.
//

#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H


#include <string>

class Animal {
public:
    Animal(std::string name);

    std::string virtual getName() = 0;
    std::string virtual breed() = 0;


protected:
    int _age;
    std::string _name;
    std::string gender;
    int hunger;
    int thirst;


};


#endif //ZOO_ANIMAL_H
