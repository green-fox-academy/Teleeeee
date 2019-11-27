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
	LED_DDR |= 1 << LED_DDR_POS;
	ac_driver_init();
	freq_meas_init();
	STDIO_init();
	sei();
}

ISR(ANALOG_COMP_vect){}

void init_ADC(){
	ADMUX = 0b00000000;
	ADCSRA = 0b11101111;
	ADCSRB = 0b00000000;
}

ISR(ADC_vect){
	uint8_t result_ADCH;
	uint8_t result_ADCL;
	uint16_t all_result;
	result_ADCL = ADCL;
	result_ADCH = ADCH;
	all_result = (((uint16_t)result_ADCH << 8) | result_ADCL);	
	ref = 7 * all_result;
}

void P_controller(uint16_t disired_value_rpm, uint16_t actual_rpm){
	if(disired_value_rpm > actual_rpm && duty < 100 ){
		duty++;
	}
	if (disired_value_rpm < actual_rpm && duty > 1){
		duty--;
	}
};


int main(void)
{
	char buffer[8];	
	// Don't forget to call the init function :)
	system_init();
	init_ADC();

	// Try printf
	printf("Startup...\n");

	// Infinite loop
	while (1) {
		// Generating an about 1Hz signal on the LED pin.
		// The printf call will also take some time, so this won't be exactly 1Hz.
		for (uint8_t i = 0; i < 100; i++ ){
			P_controller(ref, get_rpm());
			set_duty(duty);
			printf("%f RPM\n", get_rpm());
			_delay_ms(100);
		}
		printf("%f RPM\n", get_rpm());
	}
}