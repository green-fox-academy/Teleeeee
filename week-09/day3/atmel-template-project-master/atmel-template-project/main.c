#include "TC74_driver.h"
#include "STDIO_lib.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
	//TODO
	// Call the TWI driver init function
	TWI_init();

	// SDIO lib is initialed with 115200 baud rate with 8N1 settings
	STDIO_init();
	// Interrupts must be enabled as STDIO lib uses interrupts for receive
	sei();
}

int main(void)
{
	// Don't forget to call the init function :)
	system_init();

	printf("System initialized\n");
	
	uint8_t temperature = 0;
	
	//I2C alltogether:::::::
	//TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	//while(!(TWCR & 1 << TWINT));
	//TWDR = 0b10010000;
	//TWCR = (1 << TWINT) | (1 << TWEN);
	//while(!(TWCR & 1 << TWINT));
	//TWDR = 0;
	//TWCR = (1 << TWINT) | (1 << TWEN);
	//while(!(TWCR & 1 << TWINT));
	//TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	//while(!(TWCR & 1 << TWINT));
	//TWDR = 0b10010001;
	//TWCR = (1 << TWINT) | (1 << TWEN);
	//while(!(TWCR & 1 << TWINT));
	//TWCR |= 1 << TWINT;
	//temperature = TWDR;
	//TWCR = (1 << TWINT) | (1 << TWEN) | ( 1 << TWSTO);
	//led slave adress 1110000
	//led system setup oscillator turn on 00100001;
	//led row/int set 10100011;
	//led dimming set 11100111;
	//led display on 10000011;
	//led test 11011001;
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b00100001);
	TWI_stop();
	reset();
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b00000001);
	TWI_write(0b00000001);
	TWI_write(0b00000001);
	TWI_write(0b00000000);	
	TWI_write(0b00000000);
	TWI_write(0b00000000);
	TWI_write(0b00000000);
	TWI_write(0b00000000);
	TWI_write(0b00000000);
	TWI_write(0b01111100);
	TWI_write(0b00010000);
	TWI_write(0b00111000);
	TWI_write(0b00010000);
	TWI_write(0b00000000);
	TWI_write(0b00000000);
	TWI_write(0b00000000);
	TWI_write(0b00010000);
	TWI_stop();
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b10000001);
	TWI_write(0b00100000);
	TWI_stop();
	reset();
	
	
	
	// Infinite loop
	while (1) {
		//TODO
		//Write the temperature frequently.
		temperature = read_temperature();
		_delay_ms(3000);
		printf("%d\n", temperature);
		//TODO
		//Advanced: Don't use delay, use timer.

		//TODO
		//Blink the led to make sure the code is running

	}
}
