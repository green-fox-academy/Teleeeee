#include <iostream>
#include "StringedInstrrument.h"

void StringedInstrrument::play(){
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;

}