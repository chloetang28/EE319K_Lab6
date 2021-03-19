// Lab6.c
// Runs on TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 1/17/21  
// Lab number: 6
// Hardware connections
#include "DAC.h"  // TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "../inc/LaunchPad.h"
#include "../inc/CortexM.h"
#include "Sound.h"
#include "Key.h"
#include "Music.h"
#include "TExaS.h"

void DAC_Init(void);         // your lab 6 solution
void DAC_Out(uint8_t data);  // your lab 6 solution
uint8_t Testdata;

// lab video Lab6_voltmeter
int voltmetermain(void){ //voltmetermain(void){     
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  DAC_Init(); // your lab 6 solution
  Testdata = 15;
  EnableInterrupts();
  while(1){                
    Testdata = (Testdata+1)&0x0F;
    DAC_Out(Testdata);  // your lab 6 solution
  }
}

// lab video Lab6_static
int staticmain(void){   uint32_t last,now;  
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  LaunchPad_Init();
  DAC_Init(); // your lab 6 solution
  Testdata = 15;
  EnableInterrupts();
  last = LaunchPad_Input();
  while(1){                
    now = LaunchPad_Input();
    if((last != now)&&now){
       Testdata = (Testdata+1)&0x0F;
       DAC_Out(Testdata); // your lab 6 solution
    }
    last = now;
    Clock_Delay1ms(25);   // debounces switch
  }
}

/*int testMain(void){
	DAC_Init();
	for(int data=0; data<16; data++){
		DAC_Out(data);
		for(int j=0; j<10000000; j++); // delay 
	}
}
*/
int main(void){ uint32_t data; // 0 to 15 DAC output
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);
  DAC_Init();
  for(;;) {
    DAC_Out(data);
    data = 0x0F&(data+1); // 0,1,2...,14,15,0,1,2,...
  }
}


//**************Lab 6 solution below*******************
/*
int main(void){      
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  Key_Init();
  LaunchPad_Init();
  Sound_Init();
  // other initialization
  EnableInterrupts();
  while(1){ 
  }           
}
*/


