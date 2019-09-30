
#ifndef GREENFOXORGANIZATION_STUDENT_H
#define GREENFOXORGANIZATION_STUDENT_H


#include "Person.h"

class Student : public Person {
public:

    void virtual introduce();
    void virtual getGoal();
    void skipDays(int numberOfDays);
    Student(std::string name, int age,Gender ,std::string previousOrganization);
    Student();

private:
    int _skippedDays;
    std::string _previousOrganization;


};


#endif //GREENFOXORGANIZATION_STUDENT_H
