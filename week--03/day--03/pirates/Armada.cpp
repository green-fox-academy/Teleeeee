#include "Armada.h"
#include "ctime"
#include "random"
#include "iostream"

void Armada::addShipsToYourArmada(pirateShip * nextship){
    _armadaOfShip.emplace_back(nextship);
}

bool Armada::armadaWar(Armada* otherArmada){
   int counterAtacker = 0;
   int counterDeffender = 0;
   if(otherArmada->_armadaOfShip.size() > _armadaOfShip.size()){
           for (; ; ) {
               if(_armadaOfShip[counterAtacker]->battleOtherShip(otherArmada->_armadaOfShip[counterDeffender ])){
                   counterDeffender++;
                   if(counterDeffender == (otherArmada->_armadaOfShip.size()-1)) {
                       break;
                   }
               }else{
                   counterAtacker++;
                   if(counterAtacker == (_armadaOfShip.size())-1) {

                       break;
                   }
               }
               }

       }else if(otherArmada->_armadaOfShip.size() <= _armadaOfShip.size()){
            for (; ; ) {
                if(_armadaOfShip[counterAtacker]->battleOtherShip(otherArmada->_armadaOfShip[counterDeffender ])){
                    counterDeffender++;
                    if(counterDeffender == (otherArmada->_armadaOfShip.size()-1)) {
                        break;
                    }
                }else{
                    counterAtacker++;
                    if(counterAtacker == (_armadaOfShip.size())-1) {
                        break;
                    }
                }
            }
    }else{
       std::cout << "There are only loosers" << std::endl;
   }

    return counterAtacker <= counterDeffender;

}

void Armada::fillArmada(){
    srand(time(0));
    for (int i = 0; i < rand()%50; ++i) {
        _armadaOfShip.emplace_back(new pirateShip);
        _armadaOfShip[i]->fillShip();
    }
}

