#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "circular_buffer.h"

#define F_CPU	16000000	
#include <util/delay.h>		


#define RX_CIRC_BUFF_LEN 25

struct circular_buffer my_circ_buffer;

char UART_GetCharacter() {
	
}

ISR(USART_RX_vect) {
	circular_buf_put_ow(&my_circ_buffer, UDR0);
}

void UART_Init() {

	UBRR0  = 103;
	UCSR0B = 0b10011000;
	sei();
	
	my_circ_buffer.size = RX_CIRC_BUFF_LEN;
	my_circ_buffer.capacity = 26;
	my_circ_buffer.current_index = 0;
	my_circ_buffer.current_read = 0;
}

void UART_SendCharacter(char character) {
	while( !(UCSR0A & (1 << UDRE0))){
		;
	}
	UDR0 = circular_buf_get(&my_circ_buffer);
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
		_delay_ms(500);
		puts(buffer);
		_delay_ms(500);
	}
}
