//
// Created by User on 30/09/2019.
//

#include <iostream>
#include "Carrier.h"

Carrier::Carrier(int health, int ammoInTheStorage){
        _health  = health;
        _ammoStorage = ammoInTheStorage;
}

void Carrier::addAircraftF16(F16* airplane){
    _planesF16.emplace_back(airplane);
}
void Carrier::addAircraftF35(F35* airplane){
    _planesF35.emplace_back(airplane);
}

void Carrier::fill(){
    try {
        if(_ammoStorage <= 0){
            throw "There is no ammo!";
        }
    int neededammo = 0;
    for (int i = 0; i < _planesF16.size() ; ++i) {
        if(_planesF16[i]->getAmmo() > _planesF16[i]->getMaxAmmo()){
            neededammo = neededammo + (_planesF16[i]->getMaxAmmo() - _planesF16[i]->getAmmo());
        }
    }
    for (int i = 0; i < _planesF35.size() ; ++i) {
        if(_planesF35[i]->getAmmo() > _planesF35[i]->getMaxAmmo()){
            neededammo = neededammo + (_planesF35[i]->getMaxAmmo() - _planesF35[i]->getAmmo());
        }
    }
    if(neededammo > _ammoStorage){
        for (int i = 0; i < _planesF35.size() ; ++i) {
           _planesF35[i]->refill(&_ammoStorage);
        }
        for (int i = 0; i < _planesF16.size() ; ++i) {
            _planesF16[i]->refill(&_ammoStorage);
        }
    }
    else{
        for (int i = 0; i < _planesF35.size() ; ++i) {
            _planesF35[i]->refill(&_ammoStorage);
        }
        for (int i = 0; i < _planesF16.size() ; ++i) {
            _planesF16[i]->refill(&_ammoStorage);
        }
    }

    }catch(const char* e) {
        std::cout << e << std::endl;
    }

}
int Carrier::getTotalDamage(){
    int alldamage = 0;
    for (int i = 0; i < _planesF16.size() ; ++i) {
        alldamage = alldamage +  (_planesF16[i]->getAmmo() * _planesF16[i]->getBaseDamage());
    }
    for (int i = 0; i < _planesF35.size() ; ++i) {
        alldamage = alldamage +  (_planesF35[i]->getAmmo() * _planesF35[i]->getBaseDamage());
    }
    return  alldamage;
}

void Carrier::fight(Carrier* other){
    int alldamage = 0;
    for (int i = 0; i < _planesF16.size() ; ++i) {
        alldamage = alldamage +  (_planesF16[i]->getAmmo() * _planesF16[i]->getBaseDamage());
        _planesF16[i]->fight();
    }
    for (int i = 0; i < _planesF35.size() ; ++i) {
        alldamage = alldamage +  (_planesF35[i]->getAmmo() * _planesF35[i]->getBaseDamage());
        _planesF35[i]->fight();
    }
    other->_health = other->_health - alldamage;
}

std::string Carrier::getStatus(){
    std::string carrierStatus;
    std::string hp = std::to_string(_health);
    std::string aircraftCount = std::to_string(_planesF16.size() + _planesF35.size());
    std::string ammoStorageCarrier = std::to_string(_ammoStorage);
    std::string totalDamage = std::to_string(getTotalDamage());
    carrierStatus = "HP: " + hp + " , Aircraft " +  aircraftCount + " , Ammo Storage: " + ammoStorageCarrier + " , Total damage: " + totalDamage + '\n'+
    "Aircrafts: " + '\n';
     for (int i = 0; i < _planesF35.size() ; ++i) {
       carrierStatus = carrierStatus + _planesF35[i]->getStatus() + '\n';
     }
     for (int i = 0; i < _planesF16.size() ; ++i) {
        carrierStatus = carrierStatus + _planesF16[i]->getStatus() + '\n';
     }
    return carrierStatus;

}
void Carrier::addAircraft(Aircraft* plane){
    _aircraft.emplace_back(plane);
}