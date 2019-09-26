#include <iostream>
#include "Pirate.h"
#include "pirateShip.h"
#include "Armada.h"
#include "ctime"
#include "time.h"

int main() {
    srand(time(0));
    Pirate jackSparrow("JackSparrow");

    jackSparrow.drinkSomeRum();
    jackSparrow.howsItGoingMate();
    jackSparrow.howsItGoingMate();

    Pirate Hook("Hook");

    jackSparrow.brawl(&Hook);
    jackSparrow.heIsNowCaptain();


    Armada bigAssArmada;
    bigAssArmada.fillArmada();

    Armada otherBigAssArmada;
    otherBigAssArmada.fillArmada();

    std::cout << bigAssArmada.armadaWar( &otherBigAssArmada );

    return 0;

}