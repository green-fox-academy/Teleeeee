#include "pirateShip.h"
#include "time.h"
#include<cstdlib>
#include "Pirate.h"
#include "iostream"

void pirateShip::onBoardYouFilthyPirates(Pirate* newPirate){
    _ship.emplace_back(newPirate);
}

void pirateShip::fillShip(){
    srand(time(0));
    _ship.emplace_back(new Pirate(true));
    for (int i = 0; i < rand()%50; ++i) {
    _ship.emplace_back(new Pirate());
    }
}

pirateShip::pirateShip() {
}

int pirateShip::captainConsumedRum(){
    int howDrunk = 0;
    for (int i = 0; i < _ship.size() ; ++i) {
        if( _ship[i]->isHeCaptain()){
            howDrunk = _ship[i]->howDrunkIsHe();
        }

    }
    return howDrunk;
}

Pirate* pirateShip::giveMeThePirate(int index){
    return _ship[index];
}

double  pirateShip::numberOfAlivePirates(){
    double alive = 0;
    for (int i = 0; i < _ship.size() ; ++i) {
        if( _ship[i]->isHeAlive()){
            alive++;
        }
    }

    return alive;
}

bool pirateShip::battleOtherShip(pirateShip* otherShip){
    double scoreFirst = 0;
    double scoreSecond = 0;
    for (int i = 0; i < _ship.size() ; ++i) {
        _ship[i]->brawl(otherShip->_ship[i]);
        if(_ship[i]->isHeAlive()){
            scoreFirst++;
        }else{
            scoreSecond++;
        }
    }

    scoreFirst = numberOfAlivePirates() - captainConsumedRum();
    scoreSecond= otherShip->numberOfAlivePirates();
    if(scoreFirst >=scoreSecond){
        winnerHaveSomeRum(_ship);
    }else{
        winnerHaveSomeRum(otherShip->_ship);
    }

    return scoreFirst >= scoreSecond;
}

void pirateShip::winnerHaveSomeRum(std::vector<Pirate *> drunkenShip){
    srand(time(0));
    for (int i = 0; i < drunkenShip.size() ; ++i) {
        for(int k = 0; k < rand()%20; k++)
            drunkenShip[i]->drinkSomeRum();
    }
}

