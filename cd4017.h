#ifndef CD4017_H
#define CD4017_H

//Initialize, call it once in the main fuction
void CD4017Init(void);

//Send a pulse to the clock pin
void CD4017Pulse(void);

//Send a pulse to the reset pin
void CD4017Reset(void);

#endif
