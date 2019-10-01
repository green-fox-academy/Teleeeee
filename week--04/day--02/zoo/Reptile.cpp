#include "Reptile.h"

Reptile::Reptile(std::string name) : Animal(name){}

std::string Reptile::breed(){
    return  "laying eggs.";
}
std::string Reptile::getName() {
    return  _name;
}