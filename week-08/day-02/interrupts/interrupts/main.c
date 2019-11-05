#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT0_vect){
	PINB = 0b00001111;
}


void init(){
	

	

}

int main(void)
{
    DDRB = 0b00001111;
	PCICR = 1 << 0;
	PCMSK0 = 1 << 7;
	sei();

    while (1) {

    }
}