#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "cd4017.h"
#include "74hc595.h"
#include "stdint.h"

//Data related
uint8_t matrix[8][8] = {
     {1,0,1,0,1,0,1,0},
     {0,1,0,1,0,1,0,1},
     {1,0,1,0,1,0,1,0},
     {0,1,0,1,0,1,0,1},
     {1,0,1,0,1,0,1,0},
     {0,1,0,1,0,1,0,1},
     {1,0,1,0,1,0,1,0},
     {0,1,0,1,0,1,0,1}
};

int main(void){
     CD4017Init();
     CD4017Reset();
     // DDRB |= 1 << PINB2;
     while(1){
	  //for(uint8_t i = 0; i < 8; i++){
	  // HC595Write();
	  CD4017Pulse();
	
	  //_delay_ms(2000);
	  //CD4017Pulse();
	  //}
	  //	_delay_ms(2000);
     }
}
