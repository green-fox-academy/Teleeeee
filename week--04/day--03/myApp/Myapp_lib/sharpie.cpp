//
// Created by User on 25/09/2019.
//

#include "string"
#include "sharpie.h"
#include "iostream"

void sharpie::use(){
    if(_inkAmount>0) {
        _inkAmount = _inkAmount - 1;
        std::cout << "Using it !" << std::endl;
    }
}


sharpie::sharpie(std::string color, float width){
    _inkAmount = 5;
    _color = color;
    _width = width;
}
bool sharpie::haveInk(){
    if(_inkAmount > 0){
        return true;
    }
    return false;
}
