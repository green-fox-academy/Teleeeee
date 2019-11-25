#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

int timer_first_state = 0;
int timer_second_state = 0;
uint8_t timer_overflow_number = 0;
uint8_t timer_capture_state = 0;
double previous_frequency = 0;

// TODO:
// Write the interrupt handlers

ISR(TIMER1_OVF_vect){
	timer_overflow_number++;
}

ISR(TIMER1_CAPT_vect){
	if(timer_capture_state == 0){
		timer_first_state = ICR1;
		timer_capture_state = 1;
		timer_overflow_number = 0;
		}else{
		timer_second_state = ICR1;
		timer_capture_state = 0;
		//cli();
	}
}

void freq_meas_init()
{
	TCCR1B = 0b11000010;
	TIMSK1 = 0b00100001;
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
	if(timer_capture_state == 0){
	double steps = (timer_overflow_number * 65535) + (timer_second_state - timer_first_state);
	double period = ( 0.0000005 * steps);
	previous_frequency = 1.00 / period;
	timer_overflow_number = 0;
	}
	//sei();
	return (float)previous_frequency;
}