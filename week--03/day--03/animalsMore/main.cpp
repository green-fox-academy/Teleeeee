#include <iostream>
#include "animals.h"
#include "farm.h"

int main() {
    Animals cat;

    cat.drink();
    cat.eat();

    std::cout << "The hunger of the cat is " <<cat.getHunger() << std::endl;
    std::cout << "The thirst of the cat is " <<cat.getThirst() << std::endl;

    farm goodFarm(4);
    goodFarm.addAnimal(cat);



    goodFarm.breed();
    goodFarm.slaughter();


    return 0;
}