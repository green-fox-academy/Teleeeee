#include <avr/io.h>
#include "pwm.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
	uint8_t duty = 0;
	init_fast_pwm();
	
    /* Replace with your application code */
    while (1) 
    {
		duty +=1;
		set_duty(duty);
		if(duty > 100){
			duty = 0;
		}
		_delay_ms(100);
    }
}

