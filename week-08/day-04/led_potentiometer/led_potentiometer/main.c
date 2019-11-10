#include <avr/io.h>
#include "pwm.h"
#include <avr/interrupt.h>
#include <math.h>
#include "hsv_to_rgb.h"

uint16_t duty = 0;
uint16_t all_result_x = 0;
uint16_t all_result_y = 0;

void init_ADC(){
	sei();
	ADMUX = 0b00000000;
	ADCSRA = 0b11101111;
	ADCSRB = 0b00000000;
}

ISR(ADC_vect){
	uint8_t result_ADCH;
	uint8_t result_ADCL;
	result_ADCL = ADCL;
	result_ADCH = ADCH;
	//duty = abs(100 - all_result_first / 10) ;
	//set_duty(duty);
	if(ADMUX == 0b00000000){
		all_result_x = (((uint16_t)result_ADCH << 8) | result_ADCL);	
		ADMUX = 0b00000001;
	}else{
		all_result_y = (((uint16_t)result_ADCH << 8) | result_ADCL);
		ADMUX = 0b00000000;
	}
	cli();
}



int main(void)
{
	
	init_fast_pwm_first_channel();
	init_fast_pwm_second_channel();
	init_fast_pwm_third_channel();
	init_ADC();
	
    while (1) 
    {
		volatile float x =  (((float)all_result_x - 512.0)) / 512.0;
		volatile float y =  (((float)all_result_y - 512.0)) / 512.0;
		float T = (sqrtf((x * x) + (y * y)))/ 1.414;
		float fi = atan2( y, x);
		float degree = (fi/M_PI) * 180.0;
		
		uint32_t RGB = hsvColor(degree, T, 1.0);
		
		uint8_t R = 0 | (RGB >> 16);
		uint8_t G = 0 | (RGB >> 8);
		uint8_t B = 0 | (RGB >> 0);
		
		
			
		set_duty_R(R);
		set_duty_B(B);
		set_duty_G(G);
		sei();
    }
}

