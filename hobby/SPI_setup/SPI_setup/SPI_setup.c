#include "SPI_setup.h"


void setup_SPI(){
	
	//set MISO output and SCK output 
	DDRB |= 1 << 2;
	DDRB |= 1 << 3;
	DDRB |= 1 << 5;
	//enable SPI
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	
	//select master SPI mode
	//SPCR |= 1 << MSTR;
	
	//set clock
	//SPCR |= 1 << SPR0;
}

void end_SPI(){
	if(PORTB & 1 << 2){
		PORTB ^= 1 << 2;
	}
}

void start_SPI(){
	PORTB |= 1 << 2;

	//select master SPI mode
	SPCR |= 1 << MSTR;
	uint8_t data = SPDR;
	
}

void send_byte_SPI(uint8_t data){
	start_SPI();
	//transfer data to shift register
	SPDR = data;
	//wait for send finish flagb
	while(!(SPSR & (1 << SPIF)));
	data = SPDR;
}