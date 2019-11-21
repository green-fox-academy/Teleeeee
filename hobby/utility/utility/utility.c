#include "utility.h"


void set_pin_port(uint8_t pin_number, enum STATE pin_state, enum PORT_TO_SET port_name){
	switch(port_name){
		case 0 :
		if(pin_state == 1){
			PORTB |= 1 << pin_number;
		};
		if(pin_state == 0){
			// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
			if( (PORTB | (1 << pin_number)) == PORTB){
				PORTB ^= 1 << pin_number;
			}
		}
			break;
		case 1 :
		if(pin_state == 1){
			PORTC |= 1 << pin_number;
		};
		if(pin_state == 0){
			// if PORTC and bit on 1 are the same we need to change it to 0 else its already 0
			if( (PORTC | (1 << pin_number)) == PORTC){
				PORTC ^= 1 << pin_number;
			}
		}
			break;
		case 2 :
		if(pin_state == 1){
			PORTD |= 1 << pin_number;
		};
		if(pin_state == 0){
			// if PORTD and bit on 1 are the same we need to change it to 0 else its already 0
			if( (PORTD | (1 << pin_number)) == PORTD){
				PORTD ^= 1 << pin_number;
			}
		}
			break;
		default:
			PORTB = PORTC = PORTD = 0;
			break;
			
	}
	
}

void set_pin_datadirection(uint8_t pin_number, enum STATE pin_state, enum PORT_TO_SET port_name){
	switch(port_name){
		case 0 :
		if(pin_state == 1){
			DDRB |= 1 << pin_number;
		};
		if(pin_state == 0){
			// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
			if( (DDRB | (1 << pin_number)) == DDRB){
				DDRB ^= 1 << pin_number;
			}
		}
		break;
		case 1 :
		if(pin_state == 1){
			DDRC |= 1 << pin_number;
		};
		if(pin_state == 0){
			// if PORTC and bit on 1 are the same we need to change it to 0 else its already 0
			if( (DDRC | (1 << pin_number)) == DDRC){
				DDRC ^= 1 << pin_number;
			}
		}
		break;
		case 2 :
		if(pin_state == 1){
			DDRD |= 1 << pin_number;
		};
		if(pin_state == 0){
			// if PORTD and bit on 1 are the same we need to change it to 0 else its already 0
			if( (DDRD | (1 << pin_number)) == DDRD){
				DDRD ^= 1 << pin_number;
			}
		}
		break;
		default:
		PORTB = PORTC = PORTD = 0;
		break;	
	}		
};

void start_timer(enum TIMER_TO_WORK timer, uint16_t prescale){
	switch (timer)
	{
	case 0 : 
		switch (prescale)
		{
			case 1    : TCCR0B |= 1 << 0;
			break;
			case 8    : TCCR0B |= 1 << 1;
			break;
			case 64   : TCCR0B = (1 << 0) | (1 << 1);
			break;
			case 256  : TCCR0B |= 1 << 2;
			break;
			case 1024 : TCCR0B = (1 << 0) | (1 << 2);
			break;
		}
		break;
	case 1 : 
		switch (prescale)
		{
			case 1    : TCCR1B |= 1 << 0;
			break;
			case 8    : TCCR1B |= 1 << 1;
			break;
			case 64   : TCCR1B = (1 << 0) | (1 << 1);
			break;
			case 256  : TCCR1B |= 1 << 2;
			break;
			case 1024 : TCCR1B = (1 << 0) | (1 << 2);
			break;
		}
		break;
	case 2 : 
		switch (prescale)
		{
			case 1    : TCCR2B |= 1 << 0;
			break;
			case 8    : TCCR2B |= 1 << 1;
			break;
			case 64   : TCCR2B = (1 << 0) | (1 << 1);
			break;
			case 256  : TCCR2B |= 1 << 2;
			break;
			case 1024 : TCCR2B = (1 << 0) | (1 << 2);
			break;
		}
		break;		
	}
};

void stop_timer(enum TIMER_TO_WORK timer) {
	switch (timer)
	{
		case 0: 
			for (uint8_t i = 0; i < 3; i++)
			{
				// checks all 3 bits for timer if they are not 0 changes it to 0
				//which stops timer
				if( (TCCR0B | (1 << i)) == TCCR0B){
					TCCR0B ^= 1 << i;
				}
			}
			break;
		case 1:
			for (uint8_t i = 0; i < 3; i++)
			{
				// checks all 3 bits for timer if they are not 0 changes it to 0
				//which stops timer
				if( (TCCR1B | (1 << i)) == TCCR1B){
					TCCR1B ^= 1 << i;
				}
			}
			break;
		case 2:
			for (uint8_t i = 0; i < 3; i++)
			{
				// checks all 3 bits for timer if they are not 0 changes it to 0
				//which stops timer
				if( (TCCR2B | (1 << i)) == TCCR2B){
					TCCR2B ^= 1 << i;
				}
			}
			break;	
		};
};