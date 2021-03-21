// Key.c
// This software configures the off-board piano keys
// Lab 6 requires a minimum of 3 keys, but you could have more
// Runs on TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 1/17/21  
// Lab number: 6
// Hardware connections
#include "key.h" // TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************Key_Init*********************
// Initialize piano key inputs on PA5-2 PB3-0 or PE3-0
// Input: none 
// Output: none
void Key_Init(void){ 
  // write this
	SYSCTL_RCGCGPIO_R |= 0x10; // Port E
	
	__asm__ {
		NOP
		NOP
	}
	
	GPIO_PORTE_DIR_R &= ~(0x0F); //PE0-3 = inputs
	GPIO_PORTE_DEN_R |= 0x0F;
	
	GPIO_PORTE_PDR_R |= 0x0F; // pull down for PE0-3
	
}
// **************Key_In*********************
// Input from piano key inputs on PA5-2 PB3-0 or PE3-0
// Input: none 
// Output: 0 to 15 depending on keys
//   0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2, 0x08 is just Key3
uint32_t Key_In(void){ 
  // write this
	uint8_t keyIn = GPIO_PORTE_DATA_R;
	keyIn &= 0x0F;
	return keyIn;
}