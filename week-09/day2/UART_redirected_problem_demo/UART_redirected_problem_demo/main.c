#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function

void UART_Init() {
	// TODO:
	// Paste here your working function code
	UBRR0 = 103;
	UCSR0B |= 0b00001000;
	UCSR0B |= 0b00010000;
}

void UART_SendCharacter(char character) {
	// TODO:
	// Paste here your working function code
	while( !(UCSR0A & (1 << UDRE0))){
		;
	}
	UDR0 = character;
}

char UART_GetCharacter() {
	// TODO:
	// Paste here your working function code
	while( !(UCSR0A & (1 << RXC0))){
		;
	}
	return UDR0;
}

void ProcessorDoesSomethingElse(){
	// This function simulates a time-consuming task
	_delay_ms(500);
}

int main(void) {
	char buffer[255];

	//Don't forget to call the init function :)
	UART_Init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	printf("Startup...\r\n");

	// Loop that runs forever
	while (1) {
		// With gets and puts create a loopback, use the buffer variable!
		gets(buffer);
		ProcessorDoesSomethingElse();
		puts(buffer);
		ProcessorDoesSomethingElse();
	}
}