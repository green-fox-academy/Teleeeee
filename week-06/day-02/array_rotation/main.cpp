#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t byte) {
    printf("%c%c%c%c %c%c%c%c ",
           (byte & 0x80 ? '1' : '0'),
           (byte & 0x40 ? '1' : '0'),
           (byte & 0x20 ? '1' : '0'),
           (byte & 0x10 ? '1' : '0'),
           (byte & 0x08 ? '1' : '0'),
           (byte & 0x04 ? '1' : '0'),
           (byte & 0x02 ? '1' : '0'),
           (byte & 0x01 ?'1' : '0'));
}

void array_rotator(void *ptr, uint32_t bytes, uint32_t rotation_count, uint8_t right) {
    /* This function should rotate the ptr buffer bits by rotation_count to left or right direction.
     * The rotation direction is right if the right parameter is positive, left otherwise.
     * E.g. ptr ->  |   0xAA    |    0x55   |    0x23   |
     *              | 1010 1010 | 0101 0101 | 0010 0011 |
     * array_rotator(ptr, 3, 2, 1) result is:
     *              |   0xEA    |    0x95   |    0x48   |
     *              | 1110 1010 | 1001 0101 | 0100 1000 |
     */
    uint8_t * pChar;

    pChar = (uint8_t *)ptr;

    uint8_t  temp;

    if(rotation_count >= 8){
        uint32_t rotation_cirlce = rotation_count / 8;
        for (int j = 0; j < rotation_cirlce ; ++j) {

            uint8_t  temp_first = pChar[0];
            uint8_t  temp_last = pChar[bytes - 1] ;

            if (right > 0) {
                for (uint8_t i = bytes - 1; i > 0; --i) {
                    pChar[i] = pChar[i - 1];
                } pChar[0] = temp_last;
            }

            if (right == 0) {
                for (uint8_t i = 0; i < bytes - 1; ++i) {
                    pChar[i] = pChar[i + 1];
                }pChar[bytes - 1] = temp_first;
            }

        }
    }

    uint16_t temp_first_element = pChar[0] | 0b0000000000000000;
    uint16_t temp_first_last = pChar[bytes -1]| 0b0000000000000000;
    uint16_t temp_first_first;

    rotation_count = rotation_count % 8;
    if (right > 0) {
        for (int i = bytes - 1; i > 0; --i) {
            temp_first_first = pChar[i-1] | 0b0000000000000000;
            pChar[i] = pChar[i] >> rotation_count | temp_first_first << (8 - rotation_count);
        }
        pChar[0] = pChar[0] >> rotation_count | temp_first_last << (8 - rotation_count);
    }
    if (right <= 0) {
        for (int i = 0; i < bytes - 1; ++i) {
            temp_first_first = pChar[i + 1] | 0b0000000000000000;
            pChar[i] = pChar[i] << rotation_count | temp_first_first >> (8 - rotation_count);
        }
        pChar[bytes - 1] = pChar[bytes - 1] << rotation_count | temp_first_element >> (8 - rotation_count);
    }

}

int main() {

    uint8_t pChar[7] = {0xAA , 0x55 , 0x23, 0x59, 0x56, 0x53, 0x35};

    for (int i = 0; i < 7 ; ++i) {
        printf("| ");
        print_binary(pChar[i]);
        printf(" |");
    }
    printf("\n");
    array_rotator(pChar, 7, 65, 1);
    for (int i = 0; i < 7 ; ++i) {
        printf("| ");
        print_binary(pChar[i]);
        printf(" |");
    }
    printf("\n");
    array_rotator(pChar, 7, 65, 0);
    for (int i = 0; i < 7 ; ++i) {
        printf("| ");
        print_binary(pChar[i]);
        printf(" |");
    }
    printf("\n");

    return 0;
}