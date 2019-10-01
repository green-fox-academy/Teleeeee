#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H

#include "StringedInstrrument.h"

class Violin : public StringedInstrrument  {
public:
    std::string sound() override;
    Violin();
    Violin(int numb);

protected:

};


#endif //INSTRUMENTS_VIOLIN_H
