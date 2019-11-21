#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000
#include <util/delay.h>

uint8_t led_brightness_cyle_flag = 0;

void setup(){
	//enable general interrupt
	sei();
	//enable PB7 pin change interrupt -->PCINT7
	PCICR |= 1 << 0;
	PCMSK0 |= 1 << 7;
	//set fast PWM
	TCCR0A  = (1 << 7) | (1 << 1) | (1 << 0);
	//start timer with 8 prescale
	TCCR0B |= 1 << 1;
}

void set_duty(uint8_t duty){
	OCR0A = (255 * duty)/ 100;
}

ISR(PCINT0_vect){
	led_brightness_cyle_flag = 1;
}

int main(void)
{
   setup();
   uint8_t duty = 0;
    while (1) 
    {
		if(led_brightness_cyle_flag){
			//set PWM output PD6 on output
			DDRD |= 1 << 6;
			if(duty < 100){
				duty += 2;
			}else{
				led_brightness_cyle_flag = 0;
			}
		}else{
			if(duty > 0){
				duty -= 2;
			}
			if(duty == 0){
				//set PWM output PD6 on input
				DDRD = 0;
			}
		}
		set_duty(duty);
		//about 50 steps to reach 100% dutycyle 50*40ms = 2000ms = 2s
		_delay_ms(40);
    }
}

