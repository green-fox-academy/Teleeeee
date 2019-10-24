#include <stdio.h>
#include <stdint.h>

#ifndef CYRCULAR_BUFFER_CIRCULAR_BUFFER_H
#define CYRCULAR_BUFFER_CIRCULAR_BUFFER_H

typedef enum BOOL{
    FALSE,
    TRUE
}bool;


typedef struct circular_buffer{

    int current_index;
    size_t size;
    uint8_t first_array[256];
    int capacity;

}cbuf_handle_t;

void circular_buffer_init(cbuf_handle_t* cbuf, uint8_t* buffer, size_t size);
void circular_buf_reset(cbuf_handle_t *cbuf);
void circular_buf_put_ow(cbuf_handle_t *cbuf, uint8_t data);
int circular_buf_put(cbuf_handle_t *cbuf, uint8_t data);
int circular_buf_get(cbuf_handle_t *cbuf, uint8_t * data);
bool circular_buf_empty(cbuf_handle_t *cbuf);
bool circular_buf_full(cbuf_handle_t *cbuf);
size_t circular_buf_capacity(cbuf_handle_t *cbuf);
size_t circular_buf_size(cbuf_handle_t *cbuf);
void print_circlebuf(cbuf_handle_t *cbuf);



#endif //CYRCULAR_BUFFER_CIRCULAR_BUFFER_H
