#include "stdlib.h"
#include "stdio.h"


#ifndef VECTOR_GENERIC_VECTOR_H
#define VECTOR_GENERIC_VECTOR_H


#include <stdint.h>

typedef struct generic_vector{
    size_t element_size_in_byte;
    size_t size;
    unsigned int capacity;
    void* data;
}generic_vector_t;

void init_generic_vec(generic_vector_t* vec, unsigned int size, size_t element_size_in_byte);
void push_back_generic_vec(generic_vector_t* vec, void* new_data);
void* element_at_generic_vec(generic_vector_t* vec, size_t at);
void pop_back_generic_vec(generic_vector_t* vec);
void destroy_generic_vec(generic_vector_t* vec);
void print_generic_vec(generic_vector_t* vec);
void insert_generic_vector(generic_vector_t* vec,size_t at, void* new_data);
int search_by_value_generic(generic_vector_t* vec, void* find);
void transform(generic_vector_t* vec, void* (*fun_ptr)());



#endif //VECTOR_GENERIC_VECTOR_H
