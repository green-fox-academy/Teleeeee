// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#define F_CPU 16000000UL
#include <avr/delay.h>

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1

#define TC74_adrress 0b10010000

void TWI_init(void);
void TWI_start(void);
void TWI_write(uint8_t u8data);
void TWI_stop(void);
uint8_t TWI_read_nack(void);
uint8_t TWI_read_ack(void);
int8_t read_temperature(void);
int8_t read_data(void);
void reset();

#endif // _TC74_DRIVER_H