#include <stdio.h>
#include <stdint-gcc.h>
#include "string.h"
#include "stdlib.h"

#ifndef ASCII_ART_COMMAND_LINE_READ_H
#define ASCII_ART_COMMAND_LINE_READ_H

#define HEADER 58

typedef enum COMMAND{
    GET_DEFAULT,
    GET_WIDTH,
    GET_SIZE,
    GET_HEIGHT,
    GET_BIT_DEPTH,
    GET_OUT_PUT_TXT,
    GET_MONOCRONIC_TXT,
}command;

void input_read(int argc, char *argv[]);
void print_default();

#endif //ASCII_ART_COMMAND_LINE_READ_H
