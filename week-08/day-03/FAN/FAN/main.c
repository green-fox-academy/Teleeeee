#include <avr/io.h>

void init(){
	DDRD = 1 << 6;
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000101;
}

void set_duty(uint8_t duty){
	OCR0A = (duty * 255)/ 100;
}


int main(void)
{
    init();
	OCR0A = 200;
    while (1) 
    {
    }
}

