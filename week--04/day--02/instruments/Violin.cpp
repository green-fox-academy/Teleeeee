
#include "Violin.h"

std::string Violin::sound(){
    return  "Screech";
}

Violin::Violin() {
    _numberOfStrings = 4;
    _name = "Violin";
}

Violin::Violin(int numb) {
    _numberOfStrings = numb;
    _name = "Violin";
}
