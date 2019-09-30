#include <iostream>
#include "Trees.h"
#include "Flowers.h"
#include "Garden.h"

int main() {
   Flowers Yellow("Yellow");
   Flowers Blue("Blue");
   Trees Purple("Purple");
   Trees Orange("Orange");

   Garden smallGarnden;

   smallGarnden.addFlowers(&Yellow);
   smallGarnden.addFlowers(&Blue);
   smallGarnden.addTrees(&Purple);
   smallGarnden.addTrees(&Orange);

   smallGarnden.needsWatering();

   smallGarnden.wateringWith40();

    smallGarnden.needsWatering();

   smallGarnden.wateringWith70();

    smallGarnden.needsWatering();




}