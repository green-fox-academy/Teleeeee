#include "pwm.h"



void init_fast_pwm_first_channel(){
	
	DDRD = 1 << 6;
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000011;
	
}

void init_fast_pwm_second_channel(){
	
	DDRB |= 1 << 1;
	TCCR1A = 0b10000001;
	TCCR1B = 0b00001011;
	
}

void init_fast_pwm_third_channel(){
	
	DDRB |= 1 << 3;
	TCCR2A = 0b10000011;
	TCCR2B = 0b00000011;
	
}

void init_phase_correct_pwm(){
	
	DDRD |= 1 << 6;
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000001;
	
}

void set_duty_R(uint8_t duty){
	OCR0A = duty;
}

void set_duty_B(uint8_t duty){
	OCR1A = duty;
}

void set_duty_G(uint8_t duty){
	OCR2A = duty ;
}

