#include "Armada.h"
#include "ctime"
#include "iostream"

void Armada::addShipsToYourArmada(pirateShip * nextship){
    _armadaOfShip.emplace_back(nextship);
}

bool Armada::armadaWar(Armada* otherArmada){
   int counterAtacker = 0;
   int counterDeffender = 0;
   int limit = 0;
   if(otherArmada->_armadaOfShip.size()>_armadaOfShip.size()){                                                        //sets the limit of the round to the armada which has less ships
       limit = _armadaOfShip.size();
   }
   else{
       limit = otherArmada->_armadaOfShip.size();
   }
   for (int j = 0; j < limit ; ++j) {                                                                                 //ships are fighting in order
           if(_armadaOfShip[counterAtacker]->battleOtherShip(otherArmada->_armadaOfShip[counterDeffender])){
               counterDeffender++;
               if(otherArmada->_armadaOfShip.size() - 1 == counterAtacker){
                   break;
               }
           }
           else{
               counterAtacker++;
               if(_armadaOfShip.size() - 1 == counterDeffender ){
                   break;
               }
           }
       }
   if(counterAtacker < counterDeffender ){
       std::cout << getTheNameOfArmada()  <<" has won"<< std::endl;
   }else if(counterAtacker > counterDeffender){
       std::cout << otherArmada->getTheNameOfArmada()  <<" has won"<< std::endl;
   }else{
       std::cout << "It's a draw everybody loose!" << std::endl;
   }
    return counterAtacker <= counterDeffender;

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

