#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
	// TODO:
	// Set Prescaler to 4
	TWSR |= 1 << 0; 

	// TODO:
	// Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40Khz
	//So set the correct register to 0x30
	TWBR = 0x30;

	// TODO
	//Enable TWI
	TWCR |= 1 << TWEN;

}

void TWI_start(void)
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(!(TWCR & 1 << TWINT));
}

void TWI_stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | ( 1 << TWSTO);
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
	_delay_ms(100);
	int8_t data = TWDR;
	return data;
}

void reset(){
	TWSR = 0b11111001;
	TWAR = 1111111110;
	TWDR = 1111111111;
	TWCR = 0100000100;
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
	reset();
	return temprature;
}

//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.