#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

#ifndef SPI_SETUP_H_
#define SPI_SETUP_H_

void setup_SPI();
void send_byte_SPI(uint8_t data);
void end_SPI();
void start_SPI();


#endif /* SPI_SETUP_H_ */