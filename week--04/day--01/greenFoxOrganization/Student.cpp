//
// Created by User on 30/09/2019.
//

#include <iostream>
#include "Student.h"


void Student::introduce(){
    std::cout << "Hi, I am " << getName() << " "<< getAge() << " year old " << getGender() << ", from " << _previousOrganization <<
    " who skipped " << _skippedDays << " days from the course already." <<  std::endl;
}

void Student::getGoal(){
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::skipDays(int numberOfDays){
    _skippedDays = _skippedDays + numberOfDays;
}

Student::Student(std::string name, int age,Gender gender ,std::string previousOrganization){
    setAge(age);
    switch (gender) {
        case (Gender::FEMALE): setGender(Gender ::FEMALE);
            break;
        case (Gender::MALE): setGender(Gender ::MALE);
    }
    setName(name);
    _previousOrganization = previousOrganization;
    _skippedDays = 0;
}

Student::Student(){
    setAge(30);
    setGender(Gender::FEMALE);
    setName("Jane Doe");
    _skippedDays = 0;
    _previousOrganization = "The School of Life";
}