#include "utility.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <time.h>

uint16_t counter = 0;

void init(){
	srand(time(0));
	sei();
	DDRC = 0b00000111;
	PORTC = 0b00000111;
}
ISR(INT0_vect){ //PD2
	cli();
	counter = 0;
	blink_led_1HZ(5);
	light_up_start_game();
}
ISR(INT1_vect){ //PD3
	TCCR1B = 0b00000000;
	if(counter > 80){
		PORTC = 0b00000110;
	}else{
		PORTC = 0b00000101;
	}
}

ISR(TIMER1_OVF_vect){
	counter++;
}


int main(void)
{
    init();
	set_external_interrupt_setup();
    while (1) 
    {
    }
}

