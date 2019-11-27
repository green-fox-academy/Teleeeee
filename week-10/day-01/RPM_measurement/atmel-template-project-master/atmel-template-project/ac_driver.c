#include <avr/io.h>
#include "ac_driver.h"
#include "freq_meas.h"

void ac_driver_init()
{

	//digital input disable
	DIDR1 = 0b00000011;

	//analog comparator output on PE0 enable
	ACSRB |= 1 << 0;

	//analog comparator output is synchronized   --> ACO
	//analog comparator interrupt enable		 --> ACIE
	//input capture to timer1 enable		     --> ACIC
	//analog comparator on falling edge			 --> ACIS1 	
	ACSR = (1 << ACO) | (1 << ACIE) | (1 << ACIC) | (1 << ACIS1);
	
}
void set_fast_PWM(){
		//set fast PWM
		TCCR2A  = (1 << 7) | (1 << 1) | (1 << 0);
		//start timer with 8 prescaler
		TCCR2B |= 1 << 1;
		//set OCR2A output--> PB3
		DDRB |= 1 << 3;
}

void set_duty(uint8_t duty){
	OCR2A = (255 * duty)/ 100;
}

float get_rpm()
{
	//7 blades on fan
	return get_freq()/7 * 60;	
}