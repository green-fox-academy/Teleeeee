
#include "ElectrticGuitar.h"

ElectrticGuitar::ElectrticGuitar() {
    _numberOfStrings = 6;
    _name = "Electric Guitar";
}
std::string ElectrticGuitar::sound(){
    return "Tawng";
}
ElectrticGuitar::ElectrticGuitar(int numb){
    _numberOfStrings  = numb;
    _name = "Electric Guitar";
}