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
	//TODO
	//Send start signal
	TWCR |= 1 << 7;
	TWCR |= 1 << 5;

	// TODO:
	// Wait for TWINT Flag set. This indicates that
	//the START condition has been transmitted.
	uint8_t counter = 0;
	TWCR ^= 1 << 5;
	while(!(TWCR & (1 << TWINT))){
		counter++;
		if(counter > 50){
			break;
		}
	}
	TWCR |= 1 << 7;
	
}

void TWI_stop(void)
{
	//TODO
	//Send stop signal
	TWCR |= 1 << 4;
	TWCR |= 1 << 7;
	
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
	//TODO
	//Load DATA into TWDR Register. Clear TWINT
	
	TWDR = u8data;
	TWCR |= 1 << TWEN;
	TWCR ^= 1 << 7;
	
	
	//TWCR |= 1 <<7;
	//TWCR |= 1 << TWEN;
	//bit in TWCR to start transmission of data.
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	while(!(TWCR & (1 << 7)));
	TWCR |= 1 << 7; 
}

int8_t read_data(){
	while (!(TWCR & 1 << 7));
	int8_t data = TWDR;
	TWCR |= 1 << 7;
	return data;
}

//TODO
//Write a function that communicates with the TC74A0.
//Thbe function need to be take the address of the ic as a parameter.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.
uint8_t read_temperature(void){
	uint8_t temprature = 180;
	TWI_start();
	TWI_write(0b10010000);
	//if(TWI_read_ack() == 255 ) return 255 ;
	TWI_write(0);
	TWI_start();
	TWI_write(0b10010001);
	//if(TWI_read_ack() == 255 ) return 254 ;
	temprature = read_data();
	TWI_stop();
	return temprature;
}

//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.