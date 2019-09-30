#include <iostream>
#include "Plant.h"
#include "Flowers.h"
#include "Trees.h"
#include "Garden.h"

int main() {
    Flowers Yellow("Yellow");
    Flowers Blue("Blue");
    Trees Purple("Purple");
    Trees Orange("Orange");

    Garden smallGarnden;

    smallGarnden.addPlants(&Yellow);
    smallGarnden.addPlants(&Blue);
    smallGarnden.addPlants(&Purple);
    smallGarnden.addPlants(&Orange);

    smallGarnden.needsWatering();

    smallGarnden.wateringWith40();

    smallGarnden.needsWatering();

    smallGarnden.wateringWith70();

    smallGarnden.needsWatering();




}