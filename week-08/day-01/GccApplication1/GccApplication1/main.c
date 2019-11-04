/*
 * GccApplication1.c
 *
 * Created: 04/11/2019 10:23:38
 * Author : User
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

//void blink_2_hz(){
//	 PORTB = 1 << 5;
//	 _delay_ms(250);
//	PORTB = 0;
//	_delay_ms(250);
//}
//

void delay_125ms(uint8_t times){
	for (uint8_t l = 0; l < 3; l++)
	{
		for (uint8_t i = 0; i < times; i++)
		{
			PORTB = 1 << 5;
			_delay_ms(125);
		}
		PORTB = 0;
		_delay_ms(125);
	}
}


int main(void)
{
	DDRB = 1 << 5;
	
	//uint8_t button_push_counter = 0;
	uint8_t counter = 0;


    while (1) 
    {
		uint8_t arr[] = {1, 2, 4, 8};
			
		for (uint8_t k = 0; k < 4; k++)
		{
			delay_125ms(arr[k]);
		}
		for (uint8_t k = 4; k >= 1; k--)
		{
			delay_125ms(arr[k - 1]);
		}
		
		
		/*
		//if(!(PINB & (1 << 7) && button_push_counter < 5 )){
		//	_delay_ms(200);
		//	button_push_counter++;
		//}
		//
		//
		//if(button_push_counter > 4){
		//	PORTB = 1 << 5;
		//}
		
		
		//PUSHBUTTON 2HZ
		//if(!(PINB & (1 << 7))){
		//	flag = 1;
		//}
		//if(flag == 1){
		//	blink_2_hz();
		//}
		
		//TOGGLE:
		//uint8_t flag = 0;
		//uint8_t flag1 = 1;
		//if(!(PINB & (1 << 7))){
		//	_delay_ms(200);
		//	flag = flag1;
		//
		//}
		//if(flag == flag1){
		//	PORTB = PORTB ^ 1 << 5;
		//}
		//
		//TOGGLE: 2
		//if(!(PINB & (1 << 7))){
		//	_delay_ms(200);
		//	PINB = 1 << 5;
		//}
		
		//DELAY:
		//if(!(PINB & (1 << 7))){
		//   PORTB = 1 << 5;
		//   _delay_ms(500);
		//   PORTB = 0;
		//   _delay_ms(500);
		//}*/
		
    }
	
}

