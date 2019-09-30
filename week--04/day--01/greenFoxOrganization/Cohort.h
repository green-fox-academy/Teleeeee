#ifndef GREENFOXORGANIZATION_COHORT_H
#define GREENFOXORGANIZATION_COHORT_H


#include <string>
#include "Student.h"
#include "vector"
#include "Mentor.h"

class Cohort {
public:
    void addStudent(Student* Student);
    void addMentor(Mentor* Mentor);
    void info();
    Cohort(std::string name);




private:
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;
    std::string _name;

};


#endif //GREENFOXORGANIZATION_COHORT_H
