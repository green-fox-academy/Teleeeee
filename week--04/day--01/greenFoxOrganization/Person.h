
#ifndef GREENFOXORGANIZATION_PERSON_H
#define GREENFOXORGANIZATION_PERSON_H


#include <string>

enum class Gender{
    MALE,
    FEMALE
};


class Person {
public:
    void virtual introduce();
    void virtual getGoal();
    Person(std::string name, int age, Gender gender);
    Person();
    std::string getName();
    int getAge();
    std::string getGender();
    void setName(std::string name);
    void setAge(int age);
    void setGender(Gender);

private:
    std::string _gender;
    int _age;
    std::string _name;

};


#endif //GREENFOXORGANIZATION_PERSON_H
