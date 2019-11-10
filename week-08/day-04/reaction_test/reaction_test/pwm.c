#include "pwm.h"


void firs_channel_pwm(){
	DDRD = 1 << 6;
	TCCR0A = 0b10000111;
	TCCR0B = 0b00000011;
}
