#include "generic_vector.h"


void init_generic_vec(generic_vector_t* vec, unsigned int size, size_t element_size_in_byte){
    vec->size = 0;
    vec->capacity = size;
    vec->data = calloc(size, element_size_in_byte);
    vec->element_size_in_byte = element_size_in_byte;
}
void push_back_generic_vec(generic_vector_t* vec, void* new_data){
    if(vec->size >= vec->capacity){
        vec->capacity *= 2;
        vec->data = realloc(vec->data,vec->capacity * vec->element_size_in_byte);
    }
    for (size_t i = 0; i < vec->element_size_in_byte; ++i) {
        ((uint8_t*)vec->data)[vec->element_size_in_byte * vec->size + i] = ((uint8_t*)new_data)[i];
    }
    vec->size++;
}
void* element_at_generic_vec(generic_vector_t* vec, size_t at) {
    if (vec->size > at) {
        return (void *) &((uint8_t *) vec->data)[at * vec->element_size_in_byte];
    } else{
        return NULL;
    }
}
void pop_back_generic_vec(generic_vector_t* vec){
    if(vec->size != 0){
        vec->size -=1;
    }
}

void insert_generic_vector(generic_vector_t* vec, size_t at, void* new_data ){
    vec->size++;
    if(vec->size >= vec->capacity){
        vec->capacity *= 2;
        vec->data = realloc(vec->data, (size_t)vec->capacity * vec->element_size_in_byte);
    }
    for (size_t i = vec->size; i > at ; --i) {
        for (size_t j = 0; j < vec->element_size_in_byte ; ++j) {
            ((uint8_t*)vec->data)[vec->element_size_in_byte * i + j] = ((uint8_t*)vec->data)[vec->element_size_in_byte * i - vec->element_size_in_byte + j];
        }
    }
    for (size_t i = 0; i < vec->element_size_in_byte; ++i) {
        ((uint8_t*)vec->data)[at * vec->element_size_in_byte  + i] = ((uint8_t*)new_data)[i];
    }

}

int search_by_value_generic(generic_vector_t* vec, void* value){
    for (size_t i = 0; i < vec->size ; ++i) {
        int found = 1;
        for (size_t k = 0; k < vec->element_size_in_byte ; ++k) {
            if (((uint8_t *) vec->data)[i * vec->element_size_in_byte + k]
                != ((uint8_t *) value)[k]) {
                found = 0;
            }
        }if(found == 1) return i;
    }
    return -1;
}

void destroy_generic_vec(generic_vector_t* vec){
    vec->element_size_in_byte = 0;
    vec->size = 0;
    vec->capacity = 0;
    free(vec->data);
}

void transform(generic_vector_t* vec, void* fun_ptr()){
    fun_ptr(vec->data, vec->size);
}
