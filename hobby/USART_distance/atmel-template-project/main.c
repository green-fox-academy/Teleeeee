#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3

//counter unit
uint8_t counter = 0;
uint8_t save_counter = 0;
int8_t _step = 0;

enum STATE{
	LOW,
	HIGH,
};

void digitalWrite(uint8_t pin_number, enum STATE pin_state){
	if(pin_state == 1){
		PORTB |= 1 << pin_number;
	};
	if(pin_state == 0){
		// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
		if( (PORTB | (1 << pin_number)) == PORTB){
			PORTB ^= 1 << pin_number;
		}
	}
}

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

ISR(TIMER0_COMPA_vect){
	//every overflow interrupt increases the counter until external interrupt turns timer off
	counter++;
}

void setup(){
	DDRB = 0b00001111;
	PORTB = 0;
	//set  PD1 on output
	DDRD |= 1 << 1;
	// enable INT0 external interrupt
	EICRA = 0b00000011;
	// enable external interrupts
	EIMSK |= 1 << 0;
	OCR0A = 128;
}

void mesurement_start(){
	// timer OVF interrpt enable
	TIMSK0 = 0b00000010;
	//genereal interrupt enabled
	sei();
	// output high
	PIND = 1 << 1;
	//start timer with 8 preascale
	TCCR0A = 0b11000000;
	TCCR0B = 0b00000010;
	// output low
	PIND = 1 << 1;
}


int main(void)
{
	STDIO_init();
	setup();
	uint8_t dir = 1;
	while (1)
	{
		if(counter == 0){
			mesurement_start();
		}
		printf("%d \n", save_counter);
		dir ^= 1;
		for(uint32_t round = 0; round < 64 * 64 ; round++){
			switch(_step){
				case 0:
				digitalWrite(PIN0, LOW);
				digitalWrite(PIN1, LOW);
				digitalWrite(PIN2, LOW);
				digitalWrite(PIN3, HIGH);
				break;
				case 1:
				digitalWrite(PIN0, LOW);
				digitalWrite(PIN1, LOW);
				digitalWrite(PIN2, HIGH);
				digitalWrite(PIN3, HIGH);
				break;
				case 2:
				digitalWrite(PIN0, LOW);
				digitalWrite(PIN1, LOW);
				digitalWrite(PIN2, HIGH);
				digitalWrite(PIN3, LOW);
				break;
				case 3:
				digitalWrite(PIN0, LOW);
				digitalWrite(PIN1, HIGH);
				digitalWrite(PIN2, HIGH);
				digitalWrite(PIN3, LOW);
				break;
				case 4:
				digitalWrite(PIN0, LOW);
				digitalWrite(PIN1, HIGH);
				digitalWrite(PIN2, LOW);
				digitalWrite(PIN3, LOW);
				break;
				case 5:
				digitalWrite(PIN0, HIGH);
				digitalWrite(PIN1, HIGH);
				digitalWrite(PIN2, LOW);
				digitalWrite(PIN3, LOW);
				break;
				case 6:
				digitalWrite(PIN0, HIGH);
				digitalWrite(PIN1, LOW);
				digitalWrite(PIN2, LOW);
				digitalWrite(PIN3, LOW);
				break;
				case 7:
				digitalWrite(PIN0, HIGH);
				digitalWrite(PIN1, LOW);
				digitalWrite(PIN2, LOW);
				digitalWrite(PIN3, HIGH);
				break;
				default:
				digitalWrite(PIN0, LOW);
				digitalWrite(PIN1, LOW);
				digitalWrite(PIN2, LOW);
				digitalWrite(PIN3, LOW);
				break;
			}
			if(dir == 0){
				_step++;
				}else{
				_step--;
			}
			if(_step > 7){
				_step = 0;
			}
			if(_step < 0){
				_step = 7;
			}
			_delay_ms(1);
		}
		_delay_ms(1000);
	}
}
