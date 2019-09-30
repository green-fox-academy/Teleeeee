//
// Created by User on 30/09/2019.
//

#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H


#include <string>

class Aircraft {
public:

    int fight();
    int refill(int needAmmo);
    std::string getType();
    std::string getStatus();
    int getAmmo();
    int getBaseDamage();
    bool isPriority();
    void setAmmo(int minAmmo);
    void setMaxAmmo(int max);
    void setType(std::string type);
    void setBaseDamage(int base);
    int getMaxAmmo();




private:
    int _damage;
    int _ammo;
    int _maxAmmo;
    std::string _type;

};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
