#include <avr/io.h>
#ifndef _FREQ_MEAS_H
#define _FREQ_MEAS_H

void freq_meas_init();
float get_freq();
void timer_0_setup();

#endif // _FREQ_MEAS_H