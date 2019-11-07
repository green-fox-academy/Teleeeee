#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>




void init(){
	DDRD = 1 << 6;
	
	sei();
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000011;
	TCCR2A = 0b00000000;
	TCCR2B = 0b00000011;
	TIFR2  = 0b00000010;
	TIMSK2 = 0b00000100;
	OCR2B = 100;
}

void set_duty(uint8_t duty){
	OCR0A = (duty * 255)/ 100;
}

uint8_t duty = 0;
uint8_t flag = 0;

ISR(TIMER2_COMPB_vect){
	if(flag == 1){
     duty += 5;	
	  if(duty > 100){
		  flag = 0;
	  }
	}
	
	if(flag == 0){
		duty -= 5;
		if(duty < 10){
			flag = 1;
		}
	}
	
	set_duty(duty);
	_delay_ms(100);
}

int main(void)
{
    uint8_t duty = 0;
	init();
    while (1) 
    {		
    }
}

