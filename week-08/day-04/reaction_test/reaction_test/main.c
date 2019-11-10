#include <avr/io.h>
#include "pwm.h"
#define F_CPU 16000000
#include <util/delay.h>
#include <time.h>
#include <avr/interrupt.h>

uint16_t counter = 0;
uint16_t result = 0;

void init(){
	srand(time(0));
	DDRB = 0b00000011;
	DDRC = 0b00000000; 
}
void init_interrupt_button(){
	PCICR = 0b00000010;
	PCMSK1 = 0b00000001;
}

void init_timer_counter(){
	sei();
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000001;
	TIMSK1 = 0b00100001;
}

void timer_counter_to_random_blink_led(uint8_t delay){
	for(uint8_t i = 0; i < delay; i++){
		_delay_ms(1000);
		PINB = 1 << 0;
		if(i == delay - 1){
			PORTB = 1 << 1;
			init_timer_counter();
			init_interrupt_button();
			break;
		}
	}
}

ISR(PCINT1_vect){
}

ISR(TIMER1_OVF_vect){
}



int main(void)
{
    
	uint8_t random_number_timer = rand()% 10 + 1;
	init();
	timer_counter_to_random_blink_led(random_number_timer);
    while (1) 
    {
		
	}
}

