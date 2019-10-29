#include "stdlib.h"
#include "stdio.h"

typedef enum error{
    NO_ERROR,
    OK,
    OUT_OF_BOND,
    EMPTY,
    WRONG_ARGUMENT,
    INTERNAL_ERROR
}error_t;

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct vector{
    int size;
    int capacity;
    int*data;
}vector_t;

void init_vec(vector_t* vec, int size, error_t* result);
void push_back(vector_t* vec, int new_data, error_t* result);
int element_at(vector_t* vec, int at, error_t* result);
void pop_back(vector_t* vec, error_t* result);
void destroy(vector_t* vec, error_t* result);
void print(vector_t* vec, error_t* result);

#endif //VECTOR_VECTOR_H
