#include "string"
#include "Aircraft.h"
int Aircraft::fight(){
    _ammo = 0;
    return _ammo * _damage ;

}

int* Aircraft::refill(int* needAmmo){
    int needed = _maxAmmo - _ammo;
    if(*needAmmo > 0) {
        _ammo = _maxAmmo;
        *needAmmo = *needAmmo - needed;
        return needAmmo ;
    }
    return 0;
}

std::string Aircraft::getType() {
    return _type;
}
std::string Aircraft::getStatus(){
    std::string status;
    std::string a = std::to_string(getAmmo());
    std::string bd= std::to_string(getBaseDamage());
    std::string ad= std::to_string(getAmmo()*getBaseDamage());
    status = "Type " + getType() + ", " + "Ammo: " +  a +  "," + " Base Damage: " + bd +  ", " + "All Damage: " + ad;
    return status;
}
int Aircraft::getAmmo(){
    return  _ammo;
}
int Aircraft::getBaseDamage(){
    return _damage;
}

bool Aircraft::isPriority(){
    return _type == "F35";
}

void Aircraft::setAmmo(int minAmmo){
    _ammo = minAmmo;
}
void Aircraft::setMaxAmmo(int max){
    _maxAmmo = max;
}
void Aircraft::setType(std::string type){
    _type = type;
}
void Aircraft::setBaseDamage(int base){
    _damage = base;
}
int Aircraft::getMaxAmmo(){
    return _maxAmmo;
}

