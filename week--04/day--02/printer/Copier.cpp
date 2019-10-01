#include <iostream>
#include "Copier.h"

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed) {}

std::string Copier::copy(){
    return   print() + " and " + scan();
}
