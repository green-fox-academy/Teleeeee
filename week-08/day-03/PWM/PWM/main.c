#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>


void init(){
	//set PD6 to OUTPUT
	DDRD = 1 << 6;
	//set timer with prescale
	TCCR0B = 0b00000010;
	//set PWM and set compare
	TCCR0A = 0b10000011;
	
}

void cicle(uint8_t duty){
	OCR0A = (duty * 255) /100;
}


int main(void)
{
    init();
	uint8_t duty = 0;
    while (1) 
    {
		duty +=5;
		_delay_ms(200);
		if(duty > 100){
			duty = 0;
		}
		cicle(duty);
    }
}

