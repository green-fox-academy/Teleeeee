#include <iostream>
#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet some;

    Thing first("Get milk");
    Thing second("Remove the obstacles");
    Thing third("Stand up");
    Thing fourth("Eat lunch");


    third.complete();
    fourth.complete();


    some.add(first);
    some.add(second);
    some.add(third);
    some.add(fourth);
    //   You have the `Thing` class
    // - You have the `Fleet` class
    // - You have the `FleetOfThings` class with a `main` method
    // - Download those, use those
    // - In the main method create a fleet
    // - Achieve this output:
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    std::cout << some.toString() << std::endl;
    return 0;
}