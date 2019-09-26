#ifndef PIRATES_ARMADA_H
#define PIRATES_ARMADA_H
#include "pirateShip.h"

class Armada {
public:

    void addShipsToYourArmada(pirateShip * nextship);
    bool armadaWar(Armada*  otherArmada);
    void fillArmada();
    std::string getTheNameOfArmada();
    Armada(std::string name);

private:

    std::vector<pirateShip*> _armadaOfShip;
    std::string _nameOfArmada;

};


#endif //PIRATES_ARMADA_H
