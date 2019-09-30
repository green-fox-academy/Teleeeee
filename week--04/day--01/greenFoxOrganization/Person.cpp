//
// Created by User on 30/09/2019.
//

#include "Person.h"
#include "iostream"




void Person::introduce(){
    std::cout << "Hi, I am " << _name << " " << _age << " year old " << _gender << std::endl;
}

void Person::getGoal(){
        std::cout << "My goal is: Live for the moment" << std::endl;
}

Person::Person(std::string name, int age, Gender gender) {
    _name = name;
    _age = age;
    switch (gender) {
        case (Gender::FEMALE): _gender = "female";
            break;
        case (Gender::MALE): _gender = "male";
    }

}

Person::Person(){
  _name = "Jane Doe";
  _age = 30;
  _gender = "female";
}

std::string  Person::getName(){
    return _name;
}
int  Person::getAge(){
    return _age;
}
std::string  Person::getGender(){
    return _gender;
}
void Person::setName(std::string name){
    _name = name;
};
void Person::setAge(int age){
    _age = age;
};
void Person::setGender(Gender gender){
    switch (gender) {
        case (Gender::FEMALE): _gender = "female";
            break;
        case (Gender::MALE): _gender = "male";
    }
};