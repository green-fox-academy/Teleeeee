#include <stdio.h>
#include <stdint.h>
#include "stdlib.h"

void PrintBinary(uint8_t byte) {
    printf("%c%c%c%c %c%c%c%c\n",
           (byte & 0x80 ? '1' : '0'),
           (byte & 0x40 ? '1' : '0'),
           (byte & 0x20 ? '1' : '0'),
           (byte & 0x10 ? '1' : '0'),
           (byte & 0x08 ? '1' : '0'),
           (byte & 0x04 ? '1' : '0'),
           (byte & 0x02 ? '1' : '0'),
           (byte & 0x01 ? '1' : '0'));
}

uint8_t rotate_right(uint8_t byte, int direction ){

    uint8_t temp_first = byte << abs(direction - 8);
    byte = byte >> direction;
    return byte | temp_first;
}

uint8_t rotate_left(uint8_t byte, int direction ){

    uint8_t temp_first = byte >> abs(direction - 8);
    byte = byte << direction;
    return byte | temp_first;
}

int main() {
    /* 1.
     * Write a function called RotateRight which takes a byte and a number
     * and rotates the bits of byte in right direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b01000000
     * E.g. byte = 0b1000001, number = 2 => returns 0b01100000
     */

    /* 2.
     * Write a function called RotateLeft which takes a byte and a number
     * and rotates the bits of byte in left direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b00000001
     * E.g. byte = 0b1000001, number = 2 => returns 0b00000110
     */

    uint8_t byte = 0b10101101;

    PrintBinary(rotate_right(byte, 2));
    PrintBinary(rotate_left(byte, 2));

    return 0;
}