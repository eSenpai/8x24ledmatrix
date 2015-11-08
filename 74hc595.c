#include <avr/io.h>
#include <util/delay.h>
#include "74hc595.h"
#include "stdint.h"

#define HC595_PORT        PORTD
#define HC595_DDR         DDRD
#define HC595_DS_POS      PIND7      //Data pin (DS) pin location
#define HC595_SH_CP_POS   PIND6      //Shift Clock (SH_CP) pin location
#define HC595_ST_CP_POS   PIND5      //Store Clock (ST_CP) pin location
 
//74HC595 INIT
void HC595Init(void){
     //Make the Data(DS), Shift clock (SH_CP), Store Clock (ST_CP) lines output
     HC595_DDR |= ((1 << HC595_SH_CP_POS) | (1 << HC595_ST_CP_POS) | (1 << HC595_DS_POS));
}

//Set data bit high
void HC595DataHigh(void){
     HC595_PORT |= (1 << HC595_DS_POS);
}

//Set data bit low
void HC595DataLow(void){
     HC595_PORT &= (~(1 << HC595_DS_POS));
}

//Sends a clock pulse on SH_CP line
void HC595Pulse(void){
     //Pulse the Shift Clock
     HC595_PORT |= (1 << HC595_SH_CP_POS);     //HIGH
     _delay_ms(10);
     HC595_PORT &= (~(1 << HC595_SH_CP_POS));  //LOW
}

//Sends a clock pulse on ST_CP line
void HC595Latch(void){
     //Pulse the Store Clock
     HC595_PORT |= (1 << HC595_ST_CP_POS);//HIGH
     _delay_loop_1(1);
     HC595_PORT &= (~(1 << HC595_ST_CP_POS));//LOW
     _delay_loop_1(1);
}

uint8_t test[8] = {0, 0, 0, 0, 1, 0, 0, 0};


void HC595Write(void){
     DDRC |= 1 << PINC5;
     DDRC |= 1 << PINC4;
     //8 is the ammount of LED's in a row
     for(uint8_t z = 0; z < 8; z++){
	  //Set's data pin to low (0) or high (1)
	  if(test[z] == 0){
	       PORTC |= 1 << PINC5;	 
	       HC595DataLow();
	       _delay_ms(200);
	       PORTC &= ~ 1 << PINC5;
	       
	  }else{
	       PORTC |= 1 << PINC4;
	       HC595DataHigh();
	       _delay_ms(200);
	       PORTC &= ~ 1 << PINC4;
	  }
	  //Pulse in a 1 or 0 to the LED
	  HC595Pulse();
	  //Latch. the entire row
	  /*if(z == 7){
	    HC595Latch();
	    _delay_ms(500);
	    }*/
     }
     HC595Latch();
     //CD4017Pulse();
    

     /*

     //Send each 8 bits serially
     //Order is MSB first
     for(uint8_t i=0;i<8;i++){
     //Output the data on DS line according to the
     //Value of MSB
     if(data & 0b10000000){
     //MSB is 1 so output high
	    
     HC595DataHigh();
     }else{
     //MSB is 0 so output high
     HC595DataLow();
     }
     HC595Pulse();  //Pulse the Clock line
     data=data<<1;  //Now bring next bit at MSB position
     }
     //Now all 8 bits have been transferred to shift register
     //Move them to output latch at one
     HC595Latch();*/
}



