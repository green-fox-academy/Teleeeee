/*
 * multipleled.c
 *
 * Created: 04/11/2019 15:44:28
 * Author : User
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0b00001111;
	uint8_t flag = 0; 
 
    while (1) 
    {
	
		
		while(flag == 0){
		for (uint8_t i = 4; i >= 1; i--)
			{
				PORTB = PORTB ^ (1 << (i - 1));
				_delay_ms(2000);
				PORTB = 0;
			}
			if((PINC & 1 << 5)){
				_delay_ms(200);
				flag = 1;
			}
		}
		while (flag == 1)
			{
			for (uint8_t i = 0; i < 4; i++)
				{
					PORTB = PORTB ^ (1 << i);
					_delay_ms(2000);
					PORTB = 0;
				}
				if((PINC & 1 << 5)){
					_delay_ms(200);
					flag = 0;
				}
			}
	}
}

