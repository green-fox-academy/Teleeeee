#include <stdio.h>
#include <stdlib.h>

// You will write a program that keeps track of exam results.
// First, your program should ask the user how many classes took the exam. Let's say this number is N.
// Then you need to ask how many students took the exam in the first class. Let's say this number is M.
// You need to ask for the name of the class, the the exam results in percentage M times and store them.
// The number of students might be different for each class.
// You need to repeat this N times.
// Make sure you have a separate function that reads the data and returns it.

// Once you have the data write functions for the following questions:
// Which class has the biggest difference between the worst and best exam and how much is the difference?
// Which class has the best exam?
// What is the average of all the exams?

typedef struct exam_class{
    char* name_of_class;
    float* results;
}exam_class_t;

exam_class_t exam_clsas_init(char* name, int number_of_student){
    exam_class_t obj;
    float* temp = (float*)malloc(number_of_student* sizeof(float));
    obj.results = temp;
    obj.name_of_class = name;
    return obj;
}

int main()
{
    int number_of_classes = 0;
    int number_of_students = 0;
    printf("How many classes took the exam");
    scanf("%d", &number_of_classes);
    for (int i = 0; i < number_of_classes ; ++i) {
        printf("How many students took the exam?");
        scanf("%d", &number_of_students);
        printf("What is the name of class?");
        scanf();
    }


    return 0;
}