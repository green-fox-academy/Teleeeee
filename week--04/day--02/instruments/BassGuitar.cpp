#include "BassGuitar.h"

std::string BassGuitar::sound(){
    return "Duum-duum-duum";
}

BassGuitar::BassGuitar() {
    _numberOfStrings = 4;
    _name = "Bass Guitar";
}
BassGuitar::BassGuitar(int numb) {
    _numberOfStrings = numb;
    _name = "Bass Guitar";
}