#include <avr/io.h>

#ifndef UTILITY_H_
#define UTILITY_H_

enum STATE{
	LOW,
	HIGH,
};

enum PORT_TO_SET{
	B,
	C,
	D,
};

enum TIMER_TO_WORK{
	TIMER_0,
	TIMER_1,
	TIMER_2,
};


void set_pin_port(uint8_t pin_number, enum STATE pin_state, enum PORT_TO_SET port_name);
void set_pin_datadirection(uint8_t pin_number, enum STATE pin_state, enum PORT_TO_SET port_name);
void start_timer(enum TIMER_TO_WORK timer_num, uint16_t prescale);
void stop_timer(enum TIMER_TO_WORK timer);


#endif /* UTILITY_H_ */