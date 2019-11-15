#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
	TWSR |= 1; 
	
	TWBR = 16;

	TWCR |= 1 << TWEN;

}

void TWI_start(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & 1 << TWINT));
}

void TWI_stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) |( 1 << TWSTO);
}

uint8_t TWI_read_ack(void)
{
	if(!(TWSR == 0b01000001)){
		return 255;
	}
	return 0;
}


uint8_t TWI_read_nack(void)
{
	if(!(TWSR == 0b01001001)){
		return 255;
	}
	return 0;
}

void TWI_write(uint8_t u8data)
{
	TWDR = u8data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & 1 << TWINT));
}

int8_t read_data(){
	while (!(TWCR & 1 << 7));
	TWCR |= 1 << TWINT;
	_delay_ms(1);
	int8_t data = TWDR;
	return data;
}

void reset(){
	TWSR = 0b11111001;
	TWAR = 0b11111110;
	TWDR = 0b11111111;
	TWCR = 0b01000100;
}

//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf


int8_t read_temperature(void){
	int8_t temprature = 0;
	TWI_start();
	TWI_write(0b10010000);
	TWI_write(0);
	TWI_start();
	TWI_write(0b10010001);
	temprature = read_data();
	TWI_stop();
	return temprature;
}