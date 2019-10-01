#include "Reptile.h"

Reptile::Reptile(std::string name) : Animals(name){}

std::string Reptile::breed(){
    return  "laying eggs.";
}
std::string Reptile::getName() {
    return  _name;
}