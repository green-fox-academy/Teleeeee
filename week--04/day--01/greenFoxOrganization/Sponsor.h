//
// Created by User on 30/09/2019.
//

#ifndef GREENFOXORGANIZATION_SPONSOR_H
#define GREENFOXORGANIZATION_SPONSOR_H


#include "Person.h"

class Sponsor : public Person {
public:
    void virtual introduce();
    void hire();
    void virtual getGoal();
    Sponsor(std::string name, int age, Gender , std::string company);
    Sponsor();

private:
    int _hiredStudents;
    std::string _company;
};


#endif //GREENFOXORGANIZATION_SPONSOR_H
