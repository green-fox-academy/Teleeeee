#ifndef OOPTEST_ANIMALS_H
#define OOPTEST_ANIMALS_H

#include "iostream"


class Animals {
public:

    void eat();
    void drink();
    void play();

    Animals();

    Animals(int hunger, int thirst);

private:

    int _hunger;
public:
    int getHunger() const;

    int getThirst() const;

private:
    int _thirst;


};


#endif //OOPTEST_ANIMALS_H