#ifndef INSTRUMENTS_STRINGEDINSTRRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRRUMENT_H
#include "Instrument.h"
#include <iostream>

class StringedInstrrument : public Instrument {
public:

    virtual std::string sound() = 0;
    virtual void play();

protected:
    int _numberOfStrings;

};


#endif //INSTRUMENTS_STRINGEDINSTRRUMENT_H
