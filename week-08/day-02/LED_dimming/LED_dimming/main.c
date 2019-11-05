#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// Create an aplication which changes the LED brightness by switching it on/off
// regullary for different length of time.
// How does it works? Let's say that you turn on the LED for 100us and off for
// 900us and you repeate this pattern. Your eyes are not so fast, so it will
// percieve that on avarage the LED is turned on for 10% of the time, so it is
// 10% bright.

// To achieve this behaviour you should configure the timer to overflow with
// about 240Hz frequency. You should use the Output Compare A Match Interrupt
// and the Overflow Interrupt to implement the behaviour!




void init()
{
	sei();
	DDRB = 1 << 0;
	TCCR0B = 0b00000100;
	TIMSK0 =  0b00000111; 
	//TIFR0 = 0b00000111;
	
	
}

ISR(TIMER0_COMPB_vect){
	PORTB = 1 << 0;
}

ISR(TIMER0_OVF_vect){
	PORTB = 0;
}


int main(void)
{
	init();
	
	OCR0B = 240;
	
	while (1)
	{
	}
}
