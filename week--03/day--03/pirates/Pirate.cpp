#include "Pirate.h"
#include <iostream>
#include "ctime"
#include<cstdlib>



void  Pirate::drinkSomeRum() {
    if(!_dead) {
    _intoxicationCounter++;
    }else{
        std::cout << "He's dead!" << std::endl;
    }
}

Pirate::Pirate(std::string name) {
    _intoxicationCounter = 0;
    _dead = false;
    _parott = false;
}

Pirate::Pirate(bool isCaptain) {
    _intoxicationCounter = 0;
    _dead = false;
    _parott = false;
    _isCaptain = isCaptain;
}

Pirate::Pirate(){
    _intoxicationCounter = 0;
    _dead = false;
    _parott = false;
    _name = "filfthyMate";
    _isCaptain = false;
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

void Pirate::dead(){
    _dead = true;
}

std::string Pirate::getName(){
    return _name;
}

void Pirate::brawl(Pirate* otherPirate){
    srand(time(0));
    if(!otherPirate->_dead && !_dead){
        if(rand()%3 == 0){
            _dead = true;
        }else if(rand()%3 == 1){
            otherPirate->_dead = true;
        }else if (rand()%3 == 2){
        }
    }
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
