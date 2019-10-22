#include <stdio.h>
#include <stdint.h>

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

uint8_t set_clear(uint8_t byte, int position){
    uint8_t temp = 0b00000001;
    return(~(temp << position) & byte);

    /*uint8_t temp_second = byte;
    if(position >= 0 || position < 8) {
        temp = temp << position;
        temp_second = temp_second ^ temp;
        if(temp_second != byte){
            return byte & temp_second;
        }
        else{
            return byte ^ temp;
        }
    }

    return byte;
     */
}

int main() {
    /*
     * Write a function called ClearBit which takes a byte and a bit position
     * and clears the bit of byte in the specified bit position to 0.
     * E.g. byte = 0b1100, bit position = 2 => returns with 0b1000
     */
    uint8_t byte = 0b1100;
    PrintBinary(byte);
    PrintBinary(set_clear(byte, 4));

    return 0;
}