#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>
#include "stepper.h"

//counter unit
uint16_t counter = 0;
uint16_t save_counter = 0;

ISR(PCINT0_vect){
	//disable timer
	TCCR0B = 0;
	//save timer
	save_counter = counter;
	//reset timer
	counter = 0;
	PCIFR |= 1 << 0;
}

ISR(TIMER0_OVF_vect){
	//every overflow interrupt increases the counter until external interrupt turns timer off
	counter++;
}

void setup(){
	//genereal interrupt enabled
	sei();
	// timer COMPA interrupt enable
	TIMSK0 = 0b00000001;
	// enable PCINT0 interrupt PB1
	PCICR |= 1 << 0;
	// enable pin change interrupt interrupts
	PCMSK0 |= 1 << 1;

}

void mesurement_start(){
	DDRB = 0;
	//set  PD1 on output
	DDRD |= 1 << 1;
	// output high
	PIND = 1 << 1;
	//start timer with 8 preascale
	_delay_ms(1);
	// output low
	PIND = 1 << 1;
	TCCR0B = 0b00000001;
	_delay_ms(200);
	DDRB |= 1 << 1;
}


int main(void)
{
	STDIO_init();
	setup();
	
	printf("System initialized\n");
	
	while (1)
	{
		mesurement_start();
		printf("%d \n", save_counter);
		for (uint8_t i = 0; i < 16; i++)
		{
			//takes 8 measurments before stepping forward 
			for(uint8_t k = 0; k < 8; k++){
			mesurement_start();
			printf("%d \n", save_counter);
			}
			stepper_move(1, 2);
		}
	}
}

