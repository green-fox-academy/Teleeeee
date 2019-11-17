#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>


//counter unit
uint8_t counter = 0;
uint8_t save_counter = 0;

ISR(INT0_vect){
	//disable timer
	TCCR0B = 0;
	//disable interrupts
	cli();
	//port D output set 0
	PORTD = 0;
	//save time in k
	save_counter = counter;
	//reset timer
	counter = 0;
}

ISR(TIMER0_OVF_vect){
	//every overflow interrupt increases the counter until external interrupt turns timer off
	counter++;
}

void setup(){
	//set  PD1 on output
	DDRD |= 1 << 1;
	// enable INT0 external interrupt
	EICRA = 0b00000011;
	// enable external interrupts
	EIMSK |= 1 << 0;
}

void mesurement_start(){
	// timer OVF interrpt enable
	TIMSK0 = 0b00000001;
	//genereal interrupt enabled
	sei();
	// output high
	PIND = 1 << 1;
	//start timer with 8 preascale
	TCCR0A = 0b00000000;
	TCCR0B = 0b00000010;
	// output low
	PIND = 1 << 1; 
}


int main(void)
{
	STDIO_init();
	setup();
    while (1) 
    {
		if(counter == 0){
		mesurement_start();
		}
		printf("%d \n", save_counter);
		
		
    }
}

