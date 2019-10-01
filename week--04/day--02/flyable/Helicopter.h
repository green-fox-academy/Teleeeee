#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "Flyable.h"
#include "Vehicle.h"

class Helicopter : public Flyable, public Vehicle {
public:

    void virtual land() override;
    void virtual fly() override;
    void virtual takeOff() override ;

private:

};


#endif //FLYABLE_HELICOPTER_H
