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

void set_pin_port(uint8_t pin_number, enum STATE pin_state, enum PORT_TO_SET port_name);
void set_pin_datadirection(uint8_t pin_number, enum STATE pin_state, enum PORT_TO_SET port_name);


#endif /* UTILITY_H_ */