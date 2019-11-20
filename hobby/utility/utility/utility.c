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
			// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
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
			// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
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
				// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
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
				// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
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