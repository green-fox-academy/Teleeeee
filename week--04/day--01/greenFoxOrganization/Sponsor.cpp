//
// Created by User on 30/09/2019.
//

#include <iostream>
#include "Sponsor.h"
void Sponsor::introduce(){
    std::cout << "Hi, I am " << getName() << " " <<getAge() << " year old " << getGender() <<
    " who represents " << _company << " and hired " << _hiredStudents << " students sofar." <<  std::endl;
}

void  Sponsor::hire(){
    _hiredStudents +=1;
}

void Sponsor::getGoal(){
    std::cout << "My goal is: Hire brilliant junior software developers" << std::endl;
}

Sponsor::Sponsor(std::string name, int age, Gender gender , std::string company){
    setName(name);
    setAge(age);
    switch (gender) {
        case (Gender::FEMALE): setGender(Gender ::FEMALE);
            break;
        case (Gender::MALE): setGender(Gender ::MALE);
    }
    _company = company;
    _hiredStudents = 0;
}
Sponsor::Sponsor() {
    setName("Jane Doe");
    setAge(30);
    setGender(Gender::FEMALE);
    _company = "Google";
    _hiredStudents = 0;
}