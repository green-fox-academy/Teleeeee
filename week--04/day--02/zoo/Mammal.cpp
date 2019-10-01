//
// Created by User on 01/10/2019.
//

#include "Mammal.h"

std::string Mammal::breed(){
    return "pushing miniature versions out.";
}

Mammal::Mammal(std::string name) : Animal(name){}

std::string Mammal::getName() {
    return  _name;
}