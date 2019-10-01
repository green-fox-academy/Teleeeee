#include <iostream>
#include "Printer.h"


std::string Printer::print(){
    std::cout << "I'm printing something that's " << getSize() << " cm." << std::endl;
    return "I'm printing something that's " +  getSize() + " cm.";
}