#include <stdio.h>
#include <stdint.h>
#include "circular_buffer.h"


int main()
{

    uint8_t array[4] = {'a','b','c','d'};

    cbuf_handle_t cbuf;

    circular_buffer_init(&cbuf,array, 4 );

    printf("%d\n", circular_buf_empty(&cbuf));
    printf("%d\n", circular_buf_size(&cbuf));
    print_circlebuf(&cbuf);
    circular_buf_put(&cbuf, '0');
    printf("%d\n", circular_buf_size(&cbuf));
    print_circlebuf(&cbuf);
    circular_buf_put_ow(&cbuf, 'f');
    print_circlebuf(&cbuf);
    circular_buf_put_ow(&cbuf, 'g');
    print_circlebuf(&cbuf);
    circular_buf_put_ow(&cbuf, 'a');
    circular_buf_put_ow(&cbuf, 'a');
    print_circlebuf(&cbuf);
    circular_buf_put(&cbuf, 'y');
    print_circlebuf(&cbuf);

    return 0;
}