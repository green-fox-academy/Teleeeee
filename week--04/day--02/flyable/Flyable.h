#ifndef FLYABLE_FLYABLE_H
#define FLYABLE_FLYABLE_H


class Flyable {
public:
    Flyable(){};
    void virtual land() = 0;
    void virtual fly() = 0;
    void virtual takeOff() = 0;
protected:

private:


};


#endif //FLYABLE_FLYABLE_H
