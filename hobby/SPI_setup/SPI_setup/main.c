#include <avr/io.h>
#include "SPI_setup.h"

int main(void)
{	
	setup_SPI();
	start_SPI();
	send_byte_SPI(0b11111110);
	send_byte_SPI(0);
	end_SPI();
	PORTB |= 1 <<2;
    while (1) 
    {
		
		
    }
}

