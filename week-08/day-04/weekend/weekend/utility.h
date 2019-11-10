#define F_CPU 16000000

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#ifndef PWM_H_
#define PWM_H_

void set_external_interrupt_setup();
void blink_led_1HZ(uint8_t delay_in_sec);
void light_up_start_game();




#endif