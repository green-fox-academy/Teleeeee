#include "bmp_utility.h"

uint8_t* read_file(char filename[], size_t bytes_to_read){
    uint8_t* buffer = malloc(bytes_to_read * sizeof(uint8_t));
    FILE* file_in;
    file_in = fopen(filename,"rb");
    if(file_in == NULL)printf("Failed to open file\n");
    size_t elements_read = fread(buffer, sizeof(uint8_t), bytes_to_read, file_in);
    if(elements_read == 0 ) printf("Failed to read from file\n");
    fclose(file_in);
    return buffer;
}
int get_size_bmp(uint8_t* buffer_of_header){
    uint8_t size[4];
    size[0] = buffer_of_header[2];
    size[1] = buffer_of_header[3];
    size[2] = buffer_of_header[4];
    size[3] = buffer_of_header[5];
    return ((uint32_t* )size)[0];
}
int get_img_size_bmp(uint8_t* buffer_of_header){
    uint8_t size[4];
    size[0] = buffer_of_header[34];
    size[1] = buffer_of_header[35];
    size[2] = buffer_of_header[36];
    size[3] = buffer_of_header[37];
    return ((uint32_t* )size)[0];
}
int get_width_bmp(uint8_t* buffer_of_header){
    uint8_t width[4];
    width[0] = buffer_of_header[18];
    width[1] = buffer_of_header[19];
    width[2] = buffer_of_header[20];
    width[3] = buffer_of_header[21];
    return *(uint32_t* )width;
}
int get_height_bmp(uint8_t* buffer_of_header){
    uint8_t height[4];
    height[0] = buffer_of_header[22];
    height[1] = buffer_of_header[23];
    height[2] = buffer_of_header[24];
    height[3] = buffer_of_header[25];
    return *(uint32_t* )height;
}
int get_depth_bmp(uint8_t* buffer_of_header){
    uint8_t bit_depth[2];
    bit_depth[0] = buffer_of_header[28];
    bit_depth[1] = buffer_of_header[29];
    return *(uint16_t* )bit_depth;
}

char* generate_new_name(char* name_of_bmp, int size){
    char* new_name = calloc(sizeof(char), 128);
    for (int i = 0; i < size - 3 ; ++i) {
        new_name[i] = name_of_bmp[i];
    }
    new_name[ size - 4 ] = '.';
    new_name[ size - 3 ] = 't';
    new_name[ size - 2 ] = 'x';
    new_name[ size - 1 ] = 't';
    new_name[ size + 0 ] = '\0';
    return new_name;
}


