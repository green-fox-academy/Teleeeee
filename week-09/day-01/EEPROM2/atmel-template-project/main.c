#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>
#include <avr/eeprom.h>

// TODO:
/*
	1) Do the other TODOs first!
	2) Run the code
		You will notice that memory garbage is shown on the serial port
	3) Try to give default values to the variables (in global scope)
		You will notie that this did not help
	4) The compiler makes a special file that contains the default values of the EEPROM variable's,
		you have to load it to the MCU manually
		At first you have to switch the programmer back to ISP mode from debugWIRE.
		To do this you have to enter debugging mode, so hit the "F5" button on your keyboard,
		this will start a debugging process.
		While in debugging mode pause the program (by pressing "Ctrl+F5", or by Debug->Break all)
		If the program is paused click on Debug->Disable debugWIRE and close. This will stop debugging
		and reverts the programmer back to ISP mode.
		Now follow the following steps:
		- Tools->Device programming
		- Click on "Apply"
		- Click on "Memories" on the right
		- In the EEPROM field you should give the location of the .eep file
			- Click on the "Browse" button to open a file picker window
			- Search for a file in your project folder with the extension of .eep
		- After you found this file and browsed it click on the "Program" button
		- After the programming finished you can close the Device programming windows and
		rerun the program.
		- Now if you run your program the correct values will be shown
*/

// TODO:
// Create a 8bit, 16bit, 32bit wide unsigned integer variable in the EEPROM (using "EEMEM")
// Also create a float variable and also create an array which holds 6 8bit wide unsigned integers in the EEPROM
// Note that these can't be used as regular variables, but we can use them to get a pointer to them, which will point
// somewhere to a the EEPROM.

	uint8_t EEMEM var_8bit_oneprom;
	uint16_t EEMEM var_16bit_oneprom;
	uint32_t EEMEM var_32bit_oneprom ;
	float EEMEM var_float_oneprom ;
	uint8_t EEMEM array_oneprom[6];
		
void init(){
	STDIO_init();
	sei();
}

int main(void)
{
	init();
	
	
	//uint8_t first_array[6] = {1, 2, 3, 4, 5, 6};

	//eeprom_update_byte(&var_8bit_oneprom, 99);
	//eeprom_update_word(&var_16bit_oneprom, 65000);
	//eeprom_update_dword(&var_32bit_oneprom, 43234532);
	//eeprom_update_float(&var_float_oneprom, 2.0f);
	//eeprom_update_block(first_array, array_oneprom, sizeof(uint8_t) * 6);
	// Create variables in the SRAM
	uint8_t var_8bit = eeprom_read_byte(&var_8bit_oneprom);
	uint16_t var_16bit = eeprom_read_word(&var_16bit_oneprom);
	uint32_t var_32bit = eeprom_read_dword(&var_32bit_oneprom);
	float var_float = eeprom_read_float(&var_float_oneprom);
	uint8_t array[6];
	eeprom_read_block((void*)array, (void*)array_oneprom, sizeof(uint8_t)*6 );


	// TODO:
	// Load the values from the EEPROM to the SRAM variables!
	// Use the eeprom_read_xxxxx functions with th EEMEM variables as pointers.

	// Print out the variables
	// printf can't print out floating point numbers (float) by deafault :(
	// Just don't care, it's okay
	printf("var_8bit %d\n", var_8bit);
	printf("var_16bit %d\n", var_16bit);
	printf("var_32bit %f\n", var_32bit);
	printf("var_float %f\n", var_float);
	printf("array ");
	for(uint8_t i = 0; i < sizeof(array); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	while (1)
	{
	}
}

