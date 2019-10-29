#include <stdio.h>
#include "vector.h"

int main() {

    vector_t vec;
    error_t result;

    init_vec(&vec,3, &result);

    for (int i = 0; i < 10 ; ++i) {
        push_back(&vec, i,  &result);
    }
    print(&vec,  &result);
    pop_back(&vec,  &result);
    pop_back(&vec,  &result);
    print(&vec,  &result);

    printf("Element at %d: %d ", 5,  element_at(&vec,5, &result));



    return 0;
}
