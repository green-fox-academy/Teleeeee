#define F_CPU 16000000
#include <util/delay.h>

#include <avr/io.h>

#define PIN0 0
#define PIN1 1 
#define PIN2 2
#define PIN3 3

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
void setup(){
	DDRB = 0b00001111;
	PORTB = 0;
}

int8_t _step = 0;


int main(void)
{
	uint8_t dir = 1;
	setup();
    while (1) 
    {
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

