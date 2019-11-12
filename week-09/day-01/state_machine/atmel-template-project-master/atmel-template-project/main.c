#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>
#include <string.h>

// TODO:
/* Create an enum type which represents the following program states:
	- LED blinker mode
	- LED-Pushbutton mode
	- LED on mode
	- LED off mode
*/

typedef enum STATES{
	LED_BLINKER,
	LED_PUSHBUTTON,
	TURN_LED_ON,
	TURN_LED_OFF
}led_states;

void init() {
    // Initialize the UART interface with 115200 baud/sec
    STDIO_init();

    // Initialize the LED pin
    DDRB =  0b00000001;

    // Enable interrupts globally
    sei();
}

int main(void)
{
	// Don't forget to call the Init() function :)
	init();

	// TODO:
	// Create a variable with your custom program state type enum
	
	led_states state_flag = TURN_LED_ON;

	// TODO:
	// Initialize the state to LED blinker mode

	// Infinite loop
	char buffer[32];
	char blink[6] = "blink";
	// SDIO lib is initialed with 115200 baud rate with 8N1 settings
	// Interrupts must be enabled as STDIO lib uses interrupts for receive


	
	while (1)
	{
		gets(buffer);
		if(strcmp(blink ,buffer)){
		state_flag = LED_BLINKER;
		}
		if(strcmp(buffer, "push")){
			state_flag = LED_PUSHBUTTON;
		}
		if(strcmp( "turn on", buffer)){
			state_flag = TURN_LED_ON;
		}
		if(strcmp(buffer, "turn off")){
			state_flag = TURN_LED_OFF;
		}
		
		switch( state_flag ) {
			case LED_BLINKER :
			PORTB ^= 1 << 0;
			break;
			case LED_PUSHBUTTON:
			PORTB = 0 << 5;
			break;
			case TURN_LED_ON:
			PORTB = 0b00000001;
			break;
			case TURN_LED_OFF:
			PORTD = 0;
			break;
		}
		puts(buffer);
			// TODO:
			// Check the UART input buffer. If it's not empty process the string in it,
			// maybe it is a command!

			// TODO:
			// Do the tasks based on the state, hint: use switch-case
			
		}
}

