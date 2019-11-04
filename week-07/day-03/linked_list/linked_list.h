#include "stdlib.h"

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

typedef struct node{
    void* data;
    struct node* next;
}node_t;

typedef struct linked_list{
    node_t* head;
    size_t element_size_in_byte;
    size_t size;
}linked_list_t;

linked_list_t* init_linked_list(size_t element_size_in_byte);
void push_back_linked_list(linked_list_t* list, void* data);
node_t* iterator_last(linked_list_t* list);
node_t* create_new_node(linked_list_t* list, void* data);
void* element_at_linked_list(linked_list_t* list, int index);
void delete_elemet_at_index_linked_list(linked_list_t* list,  int index);
void* data_at_linked_list(linked_list_t* list, int index);
void insert_at_beginning_linked_list(linked_list_t* list, void* data );
int empty_linked_list(linked_list_t* list);
void delete_at_beginning_linked_list(linked_list_t* list);
size_t get_size_linked_list(linked_list_t* list);



#endif //LINKED_LIST_LINKED_LIST_H
