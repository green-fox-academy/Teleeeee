//
// Created by User on 30/09/2019.
//

#include "Cohort.h"
#include "iostream"


void Cohort::addStudent(Student* Student){
    _students.push_back(Student);
}
void Cohort::addMentor(Mentor* Mentor){
    _mentors.push_back(Mentor);
}
void Cohort::info(){
    std::cout << "The " << " "  << _name << " cohort "<< _students.size() << " students and " << _mentors.size() << " mentors." << std::endl;
}

Cohort::Cohort(std::string name){
    _name = name;
    _students = {};
    _mentors = {};
}