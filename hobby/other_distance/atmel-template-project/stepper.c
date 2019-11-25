#include "stepper.h"


void digitalWrite(uint8_t pin_number, enum STATE pin_state){
	if(pin_state == 1){
		PORTC |= 1 << pin_number;
	};
	if(pin_state == 0){
		// if PORTB and bit on 1 are the same we need to change it to 0 else its already 0
		if( (PORTC | (1 << pin_number)) == PORTC){
			PORTC ^= 1 << pin_number;
		}
	}
}
void setup_stepper(){
	DDRC = 0b00001111;
	PORTC = 0;
}

int stepper_move(uint8_t dir, uint8_t steps)
{
	setup_stepper();
	int8_t _step = 0;
	dir ^= 1;
	for(uint32_t round = 0; round < 64 * steps ; round++){
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
}
