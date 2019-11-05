#include <avr/io.h>

void init()
{
	TCCR0B = 0b00000101;
	DDRB = 1 << 5;
	
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	// With this you also set the clock source to CLK_io and you will also turn on the timer!

	// Set the PB5 LED pin to output
}

int main(void)
{
	// Don't forget to call the init function!
	init();
	const uint8_t cntr_max = 30;
	uint8_t counter = 0;

	while (1)
	{
		
		if(TIFR0 & 1){
			counter++;
			TIFR0  = TIFR0 & 1;
		}
		if(counter == cntr_max){
			PINB = 1 << 5;
			counter = 0;
		}
		// If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag
		// (this will clear it, it's confusing, but this is how it works)

	}
}