#include <iostream>
#include "cmake-build-debug/sharpie.h"
#include "sharpieSet.h"

int main() {
    sharpie little("blue", 1.11);
    sharpie little1("blue", 1.11);
    sharpie little2("blue", 1.11);
    sharpie little3("blue", 1.11);
    sharpie little4("blue", 1.11);
    sharpie little5("blue", 1.11);

    for(int k =0; k < 5; k++) {
        little3.use();
        little1.use();
    }

    sharpieSet sharpies;

    sharpies.addSharpie(little);
    sharpies.addSharpie(little1);
    sharpies.addSharpie(little2);
    sharpies.addSharpie(little3);
    sharpies.addSharpie(little4);
    sharpies.addSharpie(little5);

    std::cout <<sharpies.countUseable();

    sharpies.removeTrash();

    return 0;
}