#ifndef INSTRUMENTS_ELECTRTICGUITAR_H
#define INSTRUMENTS_ELECTRTICGUITAR_H
#include "StringedInstrrument.h"

class ElectrticGuitar : public StringedInstrrument {
public:
    ElectrticGuitar();
    ElectrticGuitar(int numb);
    std::string sound() override ;

protected:
};


#endif //INSTRUMENTS_ELECTRTICGUITAR_H
