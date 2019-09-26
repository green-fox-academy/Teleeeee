#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include "string"


class Pirate {
public:
    Pirate();
    Pirate(std::string name);
    Pirate(bool isCaptain);
    void howsItGoingMate();
    void drinkSomeRum();
    void brawl(Pirate* otherPirate);
    bool isHeAlive();
    std::string getName();
    void heIsNowCaptain();
    bool isHeCaptain();
    int howDrunkIsHe();
    void killHim();
    void wakeHimUp();
    void soberHim();


private:
     int _intoxicationCounter;
     bool _dead;
     std::string _name;
     bool _parott;
     bool _isCaptain;
     bool _sleeping;

};


#endif //PIRATES_PIRATE_H
