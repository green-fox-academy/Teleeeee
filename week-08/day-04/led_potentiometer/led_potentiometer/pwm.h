#include <avr/io.h>

void init_fast_pwm();

void init_phase_correct_pwm();

void set_duty_R(uint8_t duty);
void set_duty_G(uint8_t duty);
void set_duty_B(uint8_t duty);
