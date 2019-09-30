//
// Created by User on 30/09/2019.
//

#include <iostream>
#include "Mentor.h"

void  Mentor::getGoal(){
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce(){
    std::cout << "Hi, I am " << getName() << " a "<< getAge() << " year old " << getGender() << " " << _level << " mentor." <<  std::endl;
}

Mentor::Mentor(std::string name,int age,Gender gender ,LEVEL level){
    setName(name);
    setAge(age);
    switch (gender) {
        case (Gender::FEMALE): setGender(Gender ::FEMALE);
            break;
        case (Gender::MALE): setGender(Gender ::MALE);
    }
    switch(level){
        case (LEVEL::SENIOR): _level = "senior";
                break;
        case (LEVEL::INTERMADIATE): _level = "intermadiate";
                break;
        case (LEVEL::JUNIOR): _level = "junior";
               break;

    }
}
Mentor::Mentor(){
    setName("Jane Doe");
    setAge(30);
    setGender(Gender::FEMALE);
    _level = "intermediate";
}
