#include <stdio.h>
#include <stdint-gcc.h>
#include "string.h"
#include "stdlib.h"

#ifndef ASCII_ART_BMP_READER_H
#define ASCII_ART_BMP_READER_H

uint8_t* read_file(char filename[],size_t bytes_to_read);
int get_size_bmp(uint8_t* buffer_of_header);
int get_width_bmp(uint8_t* buffer_of_header);
int get_height_bmp(uint8_t* buffer_of_header);
int get_depth_bmp(uint8_t* buffer_of_header);
char* generate_new_name(char* name_of_bmp, int size);
int get_img_size_bmp(uint8_t* buffer_of_header);

#endif //ASCII_ART_BMP_READER_H
