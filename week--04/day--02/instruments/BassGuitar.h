#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H

#include "StringedInstrrument.h"

class BassGuitar : public StringedInstrrument  {
public:
    std::string sound() override;
    BassGuitar(int numb);
    BassGuitar();

protected:

};


#endif //INSTRUMENTS_BASSGUITAR_H
