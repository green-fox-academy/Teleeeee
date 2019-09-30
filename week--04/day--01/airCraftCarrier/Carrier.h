//
// Created by User on 30/09/2019.
//

#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H


#include <vector>
#include "Aircraft.h"
#include "F16.h"
#include "F35.h"

class Carrier {
public:
    Carrier(int health, int ammoInTheStorage);
    void addAircraftF16(F16* airplane);
    void addAircraftF35(F35* airplane);
    void fill();
    void fight(Carrier* other);
    std::string getStatus();
    int getTotalDamage();
    void addAircraft(Aircraft* plane );

private:
    int _ammoStorage;
    int _health;
    std::vector<F16* > _planesF16;
    std::vector<F35* > _planesF35;
    std::vector<Aircraft* > _aircraft;


};


#endif //AIRCRAFTCARRIER_CARRIER_H
