#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "cd4017.h"

#define CD4017_DDR      DDRB
#define CD4017_PORT     PORTB
#define CD4017_SC       PINB2    //Shift clock
#define CD4017_RESET    PINB1    //Reset

void CD4017Init(void){
     CD4017_DDR |= 1 << CD4017_SC;
     CD4017_PORT &= ~ 1 << CD4017_SC;
}

void CD4017Pulse(void){
     //Send a pulse to the clock
     _delay_ms(500);
     CD4017_PORT |= 1 << CD4017_SC;
     _delay_ms(500);
     CD4017_PORT &= ~ 1 << CD4017_SC;
}

void CD4017Reset(void){
     //Send a pulse to the reset pin
     _delay_ms(10);
     CD4017_PORT |= 1 << CD4017_RESET;
     _delay_ms(10);
     CD4017_PORT &= ~ 1 << CD4017_RESET;
}
