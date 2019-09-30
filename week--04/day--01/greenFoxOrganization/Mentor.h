#ifndef GREENFOXORGANIZATION_MENTOR_H
#define GREENFOXORGANIZATION_MENTOR_H


#include "Person.h"


enum class LEVEL{
    SENIOR,
    JUNIOR,
    INTERMADIATE
};

class Mentor : public Person {
public:
    void introduce() override ;
    void getGoal() override;
    Mentor(std::string name,int age,Gender gender,LEVEL level);
    Mentor();

private:
    std::string _level;
};


#endif //GREENFOXORGANIZATION_MENTOR_H
