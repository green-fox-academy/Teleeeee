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


int count_ones(uint8_t byte){
    uint8_t temp = 0b0000001;
    int counter = 0;
    for (int i = 0; i < 8 ; ++i) {
        temp = temp << i;
        if((temp & byte) == temp){
            counter++;
        }
        temp = 0b0000001;
    }
    return counter;
}
int count_zeros(uint8_t byte){
    uint8_t temp = 0b0000001;
    int counter = 0;
    for (int i = 0; i < 8 ; ++i) {
        temp = temp << i;
        if((temp & byte) != temp){
            counter++;
        }
        temp = 0b0000001;
    }
    return counter;
}


int main() {
    /* 1.
     * Write a function called CountOnes which takes a byte returns
     * with the number of one bits in it.
     * E.g. byte = 0b1101 => returns with 3
     */

    /* 2.
     * Write a function called CountZeros which takes a byte returns
     * with the number of zero bits in it.
     * E.g. byte = 0b1000 => returns with 3
     */

    uint8_t byte = 0b01111010;

    printf("%d\n", count_ones(byte));
    printf("%d\n", count_zeros(byte));

    return 0;
}