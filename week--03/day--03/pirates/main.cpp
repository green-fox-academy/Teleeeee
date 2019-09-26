#include <iostream>
#include "Pirate.h"
#include "pirateShip.h"
#include "Armada.h"
#include "ctime"

int main() {
    srand(time(0));
    Pirate jackSparrow("JackSparrow");

    Pirate Hook("Hook");

    jackSparrow.heIsNowCaptain();


    Armada bigAssArmada("British Great Armada");
    bigAssArmada.fillArmada();

    Armada otherBigAssArmada("Spanish Rulers of the world");
    otherBigAssArmada.fillArmada();

    std::cout << bigAssArmada.armadaWar( &otherBigAssArmada );

    return 0;

}