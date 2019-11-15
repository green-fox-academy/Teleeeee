#include "array_rotator.h"

void array_rotator(void *ptr, uint32_t bytes, uint32_t rotation_count, uint8_t right) {
    uint8_t * pChar = (uint8_t *)ptr;

    if(rotation_count >= 8){
        uint32_t rotation_cirlce = rotation_count / 8;
        for (int j = 0; j < rotation_cirlce; ++j) {

            uint8_t  temp_first = pChar[0];
            uint8_t  temp_last = pChar[bytes - 1];

            if (right) {
                for (uint8_t i = bytes - 1; i > 0; --i) {
                    pChar[i] = pChar[i - 1];
                }
                pChar[0] = temp_last;
            }
            else {
                for (uint8_t i = 0; i < bytes - 1; ++i) {
                    pChar[i] = pChar[i + 1];
                }
                pChar[bytes - 1] = temp_first;
            }

        }
    }

    uint16_t temp_first_element = pChar[0];
    uint16_t temp_first_last = pChar[bytes -1];
    uint16_t temp_first_first;

    rotation_count = rotation_count % 8;
    if (right) {
        for (int i = bytes - 1; i > 0; --i) {
            temp_first_first = pChar[i-1];
            pChar[i] = pChar[i] >> rotation_count | temp_first_first << (8 - rotation_count);
        }
        pChar[0] = pChar[0] >> rotation_count | temp_first_last << (8 - rotation_count);
    }
    else {
        for (int i = 0; i < bytes - 1; ++i) {
            temp_first_first = pChar[i + 1];
            pChar[i] = pChar[i] << rotation_count | temp_first_first >> (8 - rotation_count);
        }
        pChar[bytes - 1] = pChar[bytes - 1] << rotation_count | temp_first_element >> (8 - rotation_count);
    }

}
