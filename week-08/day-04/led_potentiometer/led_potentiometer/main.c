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
		volatile float x =  (((float)all_result_x - 512.0)) / 512; 
		volatile float y =  (((float)all_result_y - 512.0)) / 512;
		float T = sqrtf((x * x) + (y * y));
		float pszi = atan((y/x));
		struct HsvColor data = {pszi * 255, T * 255 , 255 };
		struct RgbColor value = HsvToRgb(data);
		
		volatile uint8_t R = value.r;
		volatile uint8_t B = value.b;
		volatile uint8_t G = value.g;
			
		set_duty_R(R);
		set_duty_B(B);
		set_duty_G(G);
		sei();
    }
}

