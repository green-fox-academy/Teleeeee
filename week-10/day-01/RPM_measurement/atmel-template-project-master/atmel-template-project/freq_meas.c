#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

int timer_first_state = 0;
int timer_second_state = 0;
uint8_t timer_overflow_number = 0;
uint8_t timer_capture_state = 0;
double previous_frequency = 0;
double steps = 0;
uint16_t time_out_overflow = 0;

//this needed to handle non measured times
ISR(TIMER0_OVF_vect){
	//need to measure time between calculations
	time_out_overflow++;
}

ISR(TIMER1_OVF_vect){
	//need to count every overflow to be able to calculate steps
	timer_overflow_number++;
}

ISR(TIMER1_CAPT_vect){
	timer_second_state = ICR1;
	//previous value is saved in timer_first_state therefor able to calculate the diff. with  current value and overflow count
	steps = (timer_overflow_number * 65535) + (timer_second_state - timer_first_state);
	//save the value for next calculation
	timer_first_state = ICR1;
	//reset overflows
	timer_overflow_number = 0;
	//should reset time out so therefor 'new signal measurement'
	time_out_overflow = 0;
}

void freq_meas_init()
{
	//noise canceler and edge selector on rising edge and 8 prescale
	TCCR1B = 0b11000010;
	//enable timer input capture and overflow interrupt
	TIMSK1 = 0b00100001;
	//initiate timer 0 for more steady measurement
	timer_0_setup();
}

float get_freq()
{
	double period = ( 0.0000005 * steps);
	previous_frequency = 1.00 / period;
	//if there where no measurement in 81ms( 5 * 1024 * 255 * 1 / 16000000 ) the freq should be 0
	if(time_out_overflow > 5){
		return 0;
	}
	return (float)previous_frequency;
}

void timer_0_setup(){
	//set on 1024 prescale
	TCCR0B = 0b00000101;
	//enable overflow interrupt
	TIMSK0 = 1 << 0;	
}