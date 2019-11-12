#include "circular_buffer.h"

/// Pass in a storage buffer and size
void circular_buffer_init(cbuf_handle_t* cbuf, uint8_t* buffer, size_t size){
    cbuf->size = size;
    cbuf->capacity = 25;
    for (size_t i = 0; i < cbuf->capacity ; ++i) {
        if(size >= i) {
            cbuf->first_array[i] = buffer[i];
            cbuf->current_index = i;
        }else{
            cbuf->first_array[i] = '\0';
        }
    }
}
/// Reset the circular buffer to empty
void circular_buf_reset(cbuf_handle_t* cbuf){
    for (size_t i = 0; i < cbuf->size ; ++i) {
        cbuf->first_array[i] = '\0' ;
    }
}
/// Put version 1 continues to add data if the buffer is full
/// Old data is overwritten
void circular_buf_put_ow(cbuf_handle_t *cbuf, uint8_t data){
    if(cbuf->current_index + 1 >= cbuf->size){
        cbuf->first_array[0] = data;
        cbuf->current_index = 0;
    }else {
        cbuf->first_array[cbuf->current_index + 1] = data;
        cbuf->current_index++;
    }
}
/// Put Version 2 rejects new data if the buffer is full
/// Returns 0 on success, -1 if buffer is full
uint8_t circular_buf_put(cbuf_handle_t *cbuf, uint8_t data){
    if(cbuf->current_index + 1 == cbuf->size){
        return -1;
    }else {
        cbuf->first_array[cbuf->current_index + 1] = data;
        cbuf->current_index++;
        return 0;
    }
}

/// Retrieve a value from the buffer
/// Returns 0 on success, -1 if the buffer is empty
uint8_t circular_buf_get(cbuf_handle_t* cbuf){
	if(cbuf->current_read + 1 > cbuf->size){
	cbuf->current_read = 0;
	return cbuf->first_array[cbuf->size];
	}
	cbuf->current_read += 1;
	return cbuf->first_array[cbuf->current_read - 1];
}
/// Returns true if the buffer is empty
bool circular_buf_empty(cbuf_handle_t *cbuf){
    uint8_t flag = FALSE;
    for (int i = 0; i < cbuf->size ; ++i) {
        if(cbuf->first_array[i] != '\0'){
            flag = TRUE;
        }
    }
    return flag;
}
/// Returns true if the buffer is full
bool circular_buf_full(cbuf_handle_t *cbuf){
    uint8_t flag = TRUE;
    for (int i = 0; i < cbuf->size ; ++i) {
        if(cbuf->first_array[i] == '\0'){
            flag = FALSE;
        }
    }
    return flag;
}
/// Returns the maximum capacity of the buffer
size_t circular_buf_capacity(cbuf_handle_t *cbuf){
    return cbuf->size;
}
/// Returns the current number of elements in the buffer
size_t circular_buf_size(cbuf_handle_t *cbuf){
    size_t counter = 0;
    for (size_t i = 0; i < cbuf->size ; ++i) {
        if(cbuf->first_array[i] != '\0'){
            counter++;
        }
    }
    return counter;
}

void print_circlebuf(cbuf_handle_t *cbuf){
    for (size_t i = 0; i < cbuf->size ; ++i) {
        if(cbuf->first_array[i] != '\0'){
            printf("%c\n", cbuf->first_array[i]);
        }
    }
}