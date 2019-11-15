#include "led_matrix_control.h"


void led_turn_on_osc(){
	TWI_start();
	TWI_write(LED_MATRIX_ADDRESS);
	TWI_write(0b00100001); //led matrix oscillator on register/command
	TWI_stop();
}

void led_turn_off_osc(){
	TWI_start();
	TWI_write(LED_MATRIX_ADDRESS);
	TWI_write(0b00100000); //led matrix oscillator off register/command
	TWI_stop();
}

void led_general_turn_on(){
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b10000001);
	TWI_stop();
}

void led_general_turn_off(){
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b10000000);
	TWI_stop();
}

void led_screen_print(uint8_t* array ){
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b00000000);
	for (uint8_t i = 0; i < 8; i++)
	{
		TWI_write(array[i] >> 1 | array[i] << 7);
		TWI_write(0);
	}

	TWI_stop();
}


void led_screen_rotate_vertical(uint8_t* array ){
	for (uint8_t l = 0; l < 8; l++)
	{
		for(uint8_t i = 0; i < 8; i++)
		{
			array[i] = array[i] >> 1 | array[i] << 7;
		}
		TWI_start();
		TWI_write(0b11100000);
		TWI_write(0b00000000);
		for (uint8_t i = 0; i < 8; i++)
		{
			TWI_write(array[i] >> 1 | array[i] << 7);
			TWI_write(0);
		}
		TWI_stop();
		_delay_ms(100);
	}
}

void led_screen_rotate_horizontal(uint8_t* array ){
	uint8_t vertical_shift = 0;
	while( vertical_shift < 9){
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b00000000);
	for (uint8_t m = 0; m < vertical_shift; m++)
	{
		TWI_write(0);
		TWI_write(0);
	}
	
	for (uint8_t i = 0; i < 8; i++)
	{
		TWI_write(array[i] >> 1 | array[i] << 7);
		TWI_write(0);
	}
	TWI_stop();
	_delay_ms(500);
	vertical_shift++;
	}
}

void led_screen_rotate_horizontal_double(uint8_t* array_first, uint8_t* array_second ){
	uint8_t vertical_shift = 0;
	uint8_t final_number_array[8];
	for (uint8_t k =0; k < 8; k++)
	{
		if(k < 3){
		final_number_array[k] = array_first[k + 2];
		}else{
		final_number_array[k] = array_second[k - 2];
		}
	}
	while( vertical_shift < 9){
	TWI_start();
	TWI_write(0b11100000);
	TWI_write(0b00000000);
	for (uint8_t m = 0; m < vertical_shift; m++)
	{
		TWI_write(0);
		TWI_write(0);
	}
	
	for (uint8_t i = 0; i < 8; i++)
	{
		TWI_write((final_number_array[i] >> 1) | (final_number_array[i] << 7));
		TWI_write(0);
	}
	TWI_stop();
	_delay_ms(500);
	vertical_shift++;
	}
}