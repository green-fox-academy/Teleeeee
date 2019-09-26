#ifndef PIRATES_ARMADA_H
#define PIRATES_ARMADA_H
#include "pirateShip.h"

class Armada {
public:

    void addShipsToYourArmada(pirateShip * nextship);
    bool armadaWar(Armada*  otherArmada);
    void fillArmada();



private:

    std::vector<pirateShip*> _armadaOfShip;

};


#endif //PIRATES_ARMADA_H
