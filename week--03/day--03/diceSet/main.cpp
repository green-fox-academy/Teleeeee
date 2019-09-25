#include <iostream>

#include "dice_set.h"

int main(int argc, char* args[]) {
    // You have a `DiceSet` class which has a list for 6 dices
    // You can roll all of them with roll()
    // Check the current rolled numbers with getCurrent()
    // You can reroll with roll()
    // Your task is to roll the dices until all of the dices are 6
    DiceSet diceSet;

    diceSet.roll();

    int counter = 0;

    while (!(6 == diceSet.getCurrent(1) && 6 == diceSet.getCurrent(2) && 6 == diceSet.getCurrent(3) && 6 == diceSet.getCurrent(4) && 6 ==
           diceSet.getCurrent(5) && 6 == diceSet.getCurrent(0))) {
        diceSet.roll();

        counter++;
    }

    std::cout << counter << std::endl;
    std::cout << diceSet.getCurrent(0) << std::endl;
    std::cout << diceSet.getCurrent(1) << std::endl;
    std::cout << diceSet.getCurrent(2) << std::endl;
    std::cout << diceSet.getCurrent(3) << std::endl;
    std::cout << diceSet.getCurrent(4) << std::endl;
    std::cout << diceSet.getCurrent(5) << std::endl;


    return 0;
}