#ifndef TRIAL_EXAM_SECOND_DOGGO_REGISTER_H
#define TRIAL_EXAM_SECOND_DOGGO_REGISTER_H

enum size{
    SMALL,
    MEDIUM,
    BIG,
    LARGE
};

struct dog{
    char name[64];
    int age;
    int weight;
    enum size dog_size;
};


#endif //TRIAL_EXAM_SECOND_DOGGO_REGISTER_H
