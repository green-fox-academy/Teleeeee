#include "pwm.h"

void init_fast_pwm(){
	
	DDRD = 1 << 6;
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000011;
	
}

void init_phase_correct_pwm(){
	
	DDRD = 1 << 6;
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000001;
	
}

void set_duty(uint8_t duty){
	OCR0A = (duty * 255)/100;
}