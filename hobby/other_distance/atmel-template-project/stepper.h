#ifndef STEPPER_H_
#define STEPPER_H_

#define F_CPU 16000000
#include <util/delay.h>

#include <avr/io.h>

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3

enum STATE{
	LOW,
	HIGH,
};

void digitalWrite(uint8_t pin_number, enum STATE pin_state);
void setup_stepper();
int stepper_move(uint8_t dir, uint8_t steps);


#endif /* STEPPER_H_ */