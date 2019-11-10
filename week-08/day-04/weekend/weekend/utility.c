#include "utility.h"

void set_external_interrupt_setup(){
	EICRA |= 0b00001111;
	EIMSK |= 0b00000011; 
}

void blink_led_1HZ(uint8_t delay_in_sec){
	for (uint8_t i = 0; i < delay_in_sec; i++)
	{
		PORTC = 0b00001111;
		_delay_ms(1000);
		PORTC = 0b00000111;
	}
}
void light_up_start_game(){
	PORTC &= 0b00000011;
	_delay_ms(1000);
	PORTC = 0b00000111;
	sei();
	TIMSK1 = 0b00000001;
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000001; // prescle : 1024 ---> every overflow 0.000064? sec
}