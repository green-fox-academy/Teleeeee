#include <avr/io.h>
#include <avr/interrupt.h>


volatile uint8_t i = 0;

ISR(INT0_vect){
	cli();
	PIND = 1 << 1;
	TCCR0B = 0;
	PORTD = 0;
	i = 0;
}

ISR(TIMER0_COMPA_vect){
	i++;
}

void external_interrupt_setup(){
	DDRD |= 1 << 1;
	EICRA = 0b00000011;
	EIMSK |= 1 << 0;
}

void mesurement_start(){
	TIMSK0 = 0b00000010; //match OCR0A interrupt enable
	TCCR0A = 0b00000000;
	sei();
	OCR0A = 127;
	PIND = 1 << 1;
	TCCR0A = 0b11000000;
	TCCR0B = 0b00000001;  // prescale
}

int main(void)
{
	volatile uint16_t k =0;
	external_interrupt_setup();
    while (1) 
    {
		if(i == 0){
		mesurement_start();
		}
		if(i < 200){
			DDRD |= 1 << 5;
			PIND = 1 << 5;
		}
    }
}

