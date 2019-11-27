#include "freq_meas.h"
#include "ac_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <STDIO_lib.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

uint8_t duty = 100;
uint16_t all_result = 0;
uint16_t ref = 0;

void system_init(){
	ac_driver_init();
	freq_meas_init();
	STDIO_init();
	init_ADC();
	set_fast_PWM();
	sei();
}

//need it to run for hardware to clean interrupt flag in the right time
ISR(ANALOG_COMP_vect){}

void init_ADC(){
	//ADC0 is selected as input --> last 3 digits are 0
	ADMUX = 0b00000000;
	//ADC enable
	//ADC conversion start
	//ADC auto trigger
	//ADC interrupt enable
	//128 prescale
	ADCSRA = 0b11101111;
	//ADC free running mode
	ADCSRB = 0b00000000;
}

ISR(ADC_vect){
	uint8_t result_ADCH;
	uint8_t result_ADCL;
	uint16_t all_result;
	result_ADCL = ADCL;
	result_ADCH = ADCH;
	//set the reference rpm through potmeter
	all_result = (((uint16_t)result_ADCH << 8) | result_ADCL);	
	//will give a value between 0 and 1024 depending on the voltage between 0 to 5 V
	ref = 7 * all_result;
}

//closed loop controller
void P_controller(uint16_t disired_value_rpm, uint16_t actual_rpm){
	//duty is set in percentage 0 to 100
	if(disired_value_rpm > actual_rpm && duty < 100 ){
		//adjustable duty cycle jumps
		duty += 5;
	}
	if (disired_value_rpm < actual_rpm && duty > 1){
		//adjustable duty cycle jumps
		duty -= 5;
	}
};


int main(void)
{
	// Don't forget to call the init function :)
	system_init();

	// Try printf
	printf("Startup...\n");

	// Infinite loop
	while (1) {
		//calculate the output signal
		P_controller(ref, get_rpm());
		//set duty cycle
		set_duty(duty);
		printf("         %f RPM\n", get_rpm());
		printf("%d RPM\n", ref);
		_delay_ms(10);
	}
}