#ifndef HC595_H
#define HC595_H

#include "stdint.h"

//Initialize HC595 System
void HC595Init(void);

//Sends a clock pulse on SH_CP line
void HC595Pulse(void);

//Sends a clock pulse on ST_CP line
void HC595Latch(void);
/*uint8_t data[]*/
void HC595Write(void);


#endif
