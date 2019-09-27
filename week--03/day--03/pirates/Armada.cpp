#include "Armada.h"
#include "ctime"
#include "iostream"

void Armada::addShipsToYourArmada(pirateShip * nextship){
    _armadaOfShip.emplace_back(nextship);
}

bool Armada::armadaWar(Armada* otherArmada){
   int counterAttacker = 0;
   int counterDeffender = 0;
   int limit = 0;
   if(otherArmada->_armadaOfShip.size()>_armadaOfShip.size()){                                                        //sets the limit of the round to the armada which has less ships
       limit = _armadaOfShip.size();
   }
   else{
       limit = otherArmada->_armadaOfShip.size();
   }
   for (int j = 0; j < limit ; ++j) {                                                                                 //ships are fighting in order
           if(_armadaOfShip[counterAttacker]->battleOtherShip(otherArmada->_armadaOfShip[counterDeffender])){
               counterDeffender++;
               if(otherArmada->_armadaOfShip.size() - 1 == counterAttacker){
                   break;
               }
           }
           else{
               counterAttacker++;
               if(_armadaOfShip.size() - 1 == counterDeffender ){
                   break;
               }
           }
       }
   if(counterAttacker < counterDeffender ){
       std::cout << getTheNameOfArmada()  <<" has won"<< std::endl;
   }else if(counterAttacker > counterDeffender){
       std::cout << otherArmada->getTheNameOfArmada()  <<" has won"<< std::endl;
   }else{
       std::cout << "It's a draw everybody loose!" << std::endl;
   }
    return counterAttacker <= counterDeffender;

}

void Armada::fillArmada(){
    srand(time(0));
    for (int i = 0; i < rand()%30; ++i) {
        _armadaOfShip.emplace_back(new pirateShip);
        _armadaOfShip[i]->fillShip();
    }
}

Armada::Armada(std::string name) {
    _nameOfArmada = name;
}
std::string Armada::getTheNameOfArmada(){
    return _nameOfArmada;
}

