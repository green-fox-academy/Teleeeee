#include "TC74_driver.h"
#include "STDIO_lib.h"
#include "fonts.h"
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
	led_turn_on_osc();
	led_general_turn_on();
	sei();
}

uint8_t generate_second_temprature_display(uint8_t temperature){
	uint8_t number = temperature%10;
	return number;
}

uint8_t generate_first_temprature_display(uint8_t temperature){
	uint8_t number = (temperature/10)%10;
	return number;
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

	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b11100000);
	TWI_stop();
	
	// Infinite loop
	while (1) {
		//TODO
		//Write the temperature frequently.
		temperature = read_temperature();
		printf("%d \n",temperature);
		led_screen_rotate_vertical(celsius);
		led_screen_rotate_horizontal_double(all_fonts[generate_first_temprature_display(temperature)], all_fonts[generate_second_temprature_display(temperature)]);
		

		
		//TODO
		//Advanced: Don't use delay, use timer.

		//TODO
		//Blink the led to make sure the code is running

	}
}
