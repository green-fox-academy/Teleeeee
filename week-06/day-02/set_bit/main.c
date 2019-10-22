#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

uint8_t set_bit(uint8_t byte, int position){
    if(position >= 0 || position < 8) {
        if (position == 0) { byte = byte | 0b00000001; }
        if (position == 1) { byte = byte | 0b00000010; }
        if (position == 2) { byte = byte | 0b00000100; }
        if (position == 3) { byte = byte | 0b00001000; }
        if (position == 4) { byte = byte | 0b00010000; }
        if (position == 5) { byte = byte | 0b00100000; }
        if (position == 6) { byte = byte | 0b01000000; }
        if (position == 7) { byte = byte | 0b10000000; }
    }
    return byte;
}

int main() {
    /*
     * Write a function called SetBit which takes a byte and a bit position
     * and sets the bit of byte in the specified bit position to 1.
     * E.g. byte = 0b1100, bit position = 1 => returns with 0b1110
     */
    uint8_t byte = 0b1100;
    PrintBinary(byte);
    PrintBinary(set_bit(byte, 0));

    return 0;
}