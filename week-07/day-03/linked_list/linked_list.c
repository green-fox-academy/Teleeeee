#include <stdint.h>
#include "linked_list.h"


void push_back_linked_list(linked_list_t* list, void* data){
    if(list->size == 0){
        uint8_t* data_new = (uint8_t*)malloc(list->element_size_in_byte);
        for (size_t i = 0; i < list->element_size_in_byte ; ++i) {
            ((uint8_t*)data_new)[i] = ((uint8_t*)data)[i];
        }
        list->head->data = (void*)data_new;
        list->size += 1;
    }else {
        node_t *next = create_new_node(list, data);
        node_t *last = iterator_last(list);
        last->next = next;
        list->size += 1;
    }
}

linked_list_t* init_linked_list(size_t element_size_in_byte){
    node_t* head = malloc(sizeof(node_t));
    head->next = NULL;
    linked_list_t* temp_list = malloc(element_size_in_byte + sizeof(node_t));
    temp_list->head = head;
    temp_list->element_size_in_byte = element_size_in_byte;
    temp_list->size = 0;
    return temp_list;
}

node_t* iterator_last(linked_list_t* list){
    node_t* temp_ptr = list->head->next;
    node_t* last_temp_ptr = list->head;
    while (temp_ptr != NULL){
        last_temp_ptr = temp_ptr;
        temp_ptr = (temp_ptr->next);
    }
    return last_temp_ptr;
}

node_t* create_new_node(linked_list_t* list, void* data){
    uint8_t* data_new = (uint8_t*)malloc(list->element_size_in_byte);
    for (size_t i = 0; i < list->element_size_in_byte ; ++i) {
        ((uint8_t*)data_new)[i] = ((uint8_t*)data)[i];
    }
    node_t* new = calloc(sizeof(node_t), 1);
    new->next = NULL;
    new->data = data_new;
    return new;
}

void* element_at_linked_list(linked_list_t* list, int index) {
    if (index > list->size -1 || index < 0) {
        return NULL;
    }
    node_t *temp_ptr = list->head->next;
    node_t *last_temp_ptr = list->head;
    int i = 0;
    while(index != i){
        last_temp_ptr = temp_ptr;
        temp_ptr = temp_ptr->next;
        i++;
    }
    return last_temp_ptr;
}
void* data_at_linked_list(linked_list_t* list, int index) {
    if (index > list->size -1 || index < 0) {
        return NULL;
    }
    node_t *temp_ptr = list->head->next;
    node_t *last_temp_ptr = list->head;
    int i = 0;
    while(index  != i){
        last_temp_ptr = temp_ptr;
        temp_ptr = temp_ptr->next;
        i++;
    }
    return last_temp_ptr->data;
}

void delete_elemet_at_index_linked_list(linked_list_t* list,  int index){
    if(index <= list->size || index > 0) {
        node_t *temp_before = element_at_linked_list(list, index - 1);
        node_t *temp = element_at_linked_list(list, index);
        node_t *temp_after = element_at_linked_list(list, index + 1);
    if(temp_after != NULL) {
        temp_before->next = temp_after;

    }else{
        temp_before->next = NULL;
    }
    free((void*)temp->data);
    free((void*)temp);
    list->size--;
    }
}

size_t get_size_linked_list(linked_list_t* list){
    return list->size;
}