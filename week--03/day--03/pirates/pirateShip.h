#ifndef PIRATES_PIRATESHIP_H
#define PIRATES_PIRATESHIP_H
#include "Pirate.h"
#include "vector"
#include "string"

class pirateShip {
public:
    pirateShip();
    void onBoardYouFilthyPirates(Pirate* newPirate);
    void fillShip();
    int captainConsumedRum();
    Pirate* giveMeThePirate(int index);
    double numberOfAlivePirates();
    bool battleOtherShip(pirateShip* otherShip);
    void winnerHaveSomeRum(std::vector<Pirate *> drunkenShip);


private:
    std::vector<Pirate*> _ship;


};


#endif //PIRATES_PIRATESHIP_H
