#include "Pirate.h"
#include <iostream>
#include "ctime"
#include<cstdlib>



void  Pirate::drinkSomeRum() {
    if(!_dead || !_sleeping) {
    _intoxicationCounter++;
    }else if(_intoxicationCounter > 4){
        _sleeping = true;
        std::cout << "He is sleeping it off!" << std::endl;
        _intoxicationCounter = 0;
    }
}

void  Pirate::wakeHimUp(){
    if(_sleeping) {
        _sleeping = false;
    }
}

Pirate::Pirate(std::string name) {
    _intoxicationCounter = 0;
    _dead = false;
    _parott = false;
    _sleeping = false;
    _isCaptain = false;
}

Pirate::Pirate(bool isCaptain) {
    _intoxicationCounter = 0;
    _dead = false;
    _parott = false;
    _isCaptain = isCaptain;
    _sleeping = false;
}

Pirate::Pirate(){
    _intoxicationCounter = 0;
    _dead = false;
    _parott = false;
    _name = "filfthyMate";
    _isCaptain = false;
    _sleeping= false;
}

void Pirate::howsItGoingMate(){
    if(!_dead) {
        if (0 <= _intoxicationCounter <= 4) {
            std::cout << "Pour me anudder!" << std::endl;
        } else {
            std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
        }
    }else{
        std::cout << "He's dead!" << std::endl;
    }
}


std::string Pirate::getName(){
    return _name;
}

void Pirate::brawl(Pirate* otherPirate){
    srand(time(0));
    if(!otherPirate->_dead && !_dead && !otherPirate->_sleeping && !_sleeping ){
        if(rand()%3 == 0){
            killHim();
        }else if(rand()%3 == 1){
            otherPirate->killHim();
        }else if (rand()%3 == 2){
            otherPirate->_sleeping = true;
            _sleeping = true;
        }
    }
}

void Pirate::soberHim(){
    _intoxicationCounter = 0;
}

void Pirate::heIsNowCaptain(){
    _isCaptain = true;
}

bool Pirate::isHeCaptain(){
    return _isCaptain;
}

int Pirate::howDrunkIsHe(){
    return _intoxicationCounter;
}

bool Pirate::isHeAlive(){
    return !_dead;
}

void Pirate::killHim(){
    _dead = true;
}
