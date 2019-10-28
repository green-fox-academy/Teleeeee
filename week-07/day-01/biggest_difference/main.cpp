#include <stdio.h>
#include <stdlib.h>
#include "string.h"

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
    char name_of_class[64];
    int* results;
    int size_of_class;
}exam_class_t;

exam_class_t exam_class_init(char* name, int number_of_student){
    exam_class_t obj;
    int* temp = (int*)malloc(number_of_student* sizeof(float));
    obj.results = temp;
    obj.size_of_class = number_of_student;
    for (int i = 0; i < strlen(name) ; ++i) {
        obj.name_of_class[i] = name[i];
    }
    obj.name_of_class[strlen(name)] = '\0';
    return obj;
}

void biggest_difference_between_worst_and_best(exam_class_t* exam_classes, int size){
    int temp_grade = 0;
    int biggest_difference = 0;
    int temp_index_of_class = 0;
    for (int j = 0; j < size ; ++j) {
        for (int i = 0; i < exam_classes[j].size_of_class ; ++i) {
            for (int k = 0; k < exam_classes[j].size_of_class  ; ++k) {
                if (exam_classes[j].results[i] < exam_classes[j].results[k]) {
                    temp_grade = exam_classes[j].results[k];
                    exam_classes[j].results[i] =  exam_classes[j].results[k];
                    exam_classes[j].results[k] = temp_grade;
                }
            }
        }
    }
    for (int i = 0; i < size ; ++i) {
        abs( exam_classes[i].results[0] - exam_classes[i].results[exam_classes[i].size_of_class - 1]) > biggest_difference ?
        biggest_difference = abs(exam_classes[i].results[0] - exam_classes[i].results[exam_classes[i].size_of_class - 1]), temp_index_of_class = i : biggest_difference;

    }
    printf("The biggest difference is in the %s class, with %d difference\n" , exam_classes[temp_index_of_class].name_of_class, biggest_difference);
}

void which_class_has_best_exam(exam_class_t* exam_classes, int size){
    int best_exam_result = 0;
    int temp_grade;
    int best_index;
    for (int j = 0; j < size ; ++j) {
        for (int i = 0; i < exam_classes[j].size_of_class ; ++i) {
            for (int k = 0; k < exam_classes[j].size_of_class  ; ++k) {
                if (exam_classes[j].results[i] < exam_classes[j].results[k]) {
                    temp_grade = exam_classes[j].results[k];
                    exam_classes[j].results[i] =  exam_classes[j].results[k];
                    exam_classes[j].results[k] = temp_grade;
                }
            }
        }
    }
    for (int i = 0; i < size ; ++i) {
        if(exam_classes[i].results[(exam_classes[i].size_of_class) - 1] > best_exam_result){
            best_exam_result = exam_classes[i].results[(exam_classes[i].size_of_class) - 1];
            best_index = i;
        }
    }
    printf("The %s has the best exam with %d percentage!\n ", exam_classes[best_index].name_of_class, best_exam_result);

}

int avarage_of_all_exams(exam_class_t* exam_classes, int size){
    int sum = 0;
    int counter = 0;
    for (int i = 0; i < size ; ++i) {
        for (int j = 0; j < exam_classes[i].size_of_class ; ++j) {
            sum += exam_classes[i].results[j];
            counter++;
        }
    }
    return sum/counter;
}

int main()
{
    char name[64];
    int number_of_classes = 0;
    int number_of_students = 0;

    printf("How many classes took the exam\n");
    scanf("%d", &number_of_classes);

    auto* exam_classes = (exam_class_t*)malloc(number_of_classes * sizeof(exam_class_t));
    for (int i = 0; i < number_of_classes ; ++i) {
        printf("How many students took the exam in the %d's class?\n", i);
        scanf("%d", &number_of_students);
        printf("What is the name of the %d's class?\n", i);
        scanf("%s", name);
        exam_classes[i] = exam_class_init(name, number_of_students);
    }
    for (int j = 0; j < number_of_classes ; ++j) {
        for (int i = 0; i <exam_classes[j].size_of_class ; ++i) {
            printf("The result for %d's the %d's student.\n", j, i);
            scanf("%d", &exam_classes[j].results[i]);
        }
    }
    for (int j = 0; j < number_of_classes ; ++j) {
        for (int i = 0; i < exam_classes[j].size_of_class ; ++i) {
            printf("The %d. student in the %s class has %d.\n ", i, exam_classes[j].name_of_class, exam_classes[j].results[i] );
        }
    }

    biggest_difference_between_worst_and_best(exam_classes, number_of_classes);
    which_class_has_best_exam(exam_classes, number_of_classes);
    printf("The avarage exam results are %d", avarage_of_all_exams(exam_classes, number_of_classes));

    for (int k = 0; k < number_of_classes ; ++k) {
        free(exam_classes[k].results);
    }
    free(exam_classes);


    return 0;
}