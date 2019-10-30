#include <stdio.h>
#include "linked_list.h"

typedef struct phone{
    int number;
    float weight;
    char name[100];
    char lofasz[1000];
}phone_t;

int main() {

    phone_t firstphone = {123124, 4452.00f, "MAMAMAMAMA"};
    phone_t secondphone = {53124, 9999.00f, "Mlalallsad"};
    phone_t thirdphone = {443434, 111111.00f, "Mkakakaksd"};

    linked_list_t* list = init_linked_list(sizeof(phone_t));

    push_back_linked_list(list, &firstphone );
    push_back_linked_list(list, &secondphone);
    push_back_linked_list(list, &thirdphone);
    printf("%d\n", (*((phone_t*)data_at_linked_list(list, 0))).number);
    printf("%d\n", (*((phone_t*)data_at_linked_list(list, 1))).number);
    printf("%d\n", (*((phone_t*)data_at_linked_list(list, 2))).number);

    delete_elemet_at_index_linked_list(list,1);

    printf("%d\n", (*((phone_t*)data_at_linked_list(list, 0))).number);
    printf("%d\n", (*((phone_t*)data_at_linked_list(list, 1))).number);





    return 0;
}