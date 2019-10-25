#include <stdio.h>
#include <stdint.h>
#include "circular_buffer.h"


int main()
{

    uint8_t array[16] = {'a','b','c','d','e','f','g','h','j','k','l','m','n','o','p','q'};

    cbuf_handle_t cbuf;

    circular_buffer_init(&cbuf,array, 16 );

    printf("%d\n", circular_buf_empty(&cbuf));
    printf("%d\n", circular_buf_size(&cbuf));
    print_circlebuf(&cbuf);

    return 0;
}