#include <stdio.h>
#include "generic_vector.h"

typedef struct phone{
    int number;
    float weight;
    char owner[64];
}phone_t;


void add(void* vec,size_t size){
    for (int i = 0; i < size ; ++i) {
        ((float *) vec)[i] += ((float *) vec)[i];
    }
}


int main() {
/*
    phone_t firstphone = {1, 4.0f, "lajos"};
    phone_t secondphone = {4, 8.0f, "levi"};
    phone_t thirdphone = {4545334, 67.0f, "millla"};
    phone_t fourthphone = {4435334, 1.0f, "mfafa"};
    phone_t fifthphone = {42334, 6455.0f, "missdfllla"};
    phone_t sixthphone = {45, 11.0f, "llsdfla"};
    phone_t seventhphone = {222, 621.0f, "misdfdsllla"};


    generic_vector_t genericVector;

    init_generic_vec(&genericVector,5, sizeof(phone_t));

    push_back_generic_vec(&genericVector, &firstphone);
    push_back_generic_vec(&genericVector, &secondphone);
    pop_back_generic_vec(&genericVector);
    insert_generic_vector(&genericVector, 1, &thirdphone);
    insert_generic_vector(&genericVector, 1, &fourthphone);
    insert_generic_vector(&genericVector, 1, &fifthphone);
    insert_generic_vector(&genericVector, 1, &sixthphone);
    insert_generic_vector(&genericVector, 1, &seventhphone);


    printf("%f\n", (*(phone_t*)element_at_generic_vec(&genericVector, 0)).weight );
    printf("%f\n", (*(phone_t*)element_at_generic_vec(&genericVector, 1)).weight );
    printf("%f\n", (*(phone_t*)element_at_generic_vec(&genericVector, 2)).weight );
    printf("%f\n", (*(phone_t*)element_at_generic_vec(&genericVector, 3)).weight );
    printf("%f\n", (*(phone_t*)element_at_generic_vec(&genericVector, 4)).weight );
    printf("%f\n", (*(phone_t*)element_at_generic_vec(&genericVector, 5)).weight );

    printf("%d\n",  search_by_value_generic(&genericVector,&fifthphone));

    transform(&genericVector, (void*)add );
*/
    //destroy_generic_vec(&genericVector);

    float to_it = 2.00f;

    generic_vector_t float_vector;
    init_generic_vec(&float_vector, 10, sizeof(float));
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    push_back_generic_vec(&float_vector,&to_it );
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 0)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 1)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 2)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 3)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 4)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 5)));

    transform(&float_vector, (void*)add);

    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 0)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 1)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 2)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 3)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 4)));
    printf("%f\n", (*(float*)element_at_generic_vec(&float_vector, 5)));

    destroy_generic_vec(&float_vector);

    return 0;
}
