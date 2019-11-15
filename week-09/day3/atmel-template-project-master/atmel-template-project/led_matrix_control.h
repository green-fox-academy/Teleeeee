#include <avr/io.h>
#include <stdio.h>
#include "array_rotator.h"
#include "TC74_driver.h"

#define LED_MATRIX_ADDRESS 0b11100000

#define F_CPU 16000000UL
#include <avr/delay.h>

#ifndef INCFILE1_H_
#define INCFILE1_H_



void led_turn_on_osc();
void led_general_turn_on();
void led_turn_off_osc();
void led_general_turn_off();
void led_screen_print(uint8_t* array );
void led_screen_rotate_vertical(uint8_t* array );
void led_screen_rotate_horizontal(uint8_t* array );
void led_screen_rotate_horizontal_double(uint8_t* array_first, uint8_t* array_second );


#endif /* INCFILE1_H_ */