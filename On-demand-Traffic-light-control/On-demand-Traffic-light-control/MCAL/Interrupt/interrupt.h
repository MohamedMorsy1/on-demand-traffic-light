/*
 * interrupt.h
 *
 * Created: 9/29/2022 9:55:03 PM
 *  Author: Mohamed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#define INT_EXT_0 __vector_1          //external interrupt request 0


#define sei() SREG|= (1<<7)           //enable global interrupts
#define cli() SREG&= ~(1<<7)          //clear global interrupts


//choose external interrupt sense
#define INT0_risingEdge() MCUCR|= (1<<0) | (1<<1)	   //rising edge    

#define INT0_fallingEdge() MCUCR|= (1<<0) & ~(1<<1)     //falling edge


#define INT0_enable() GICR|=(1<<6)    //enable external interrupt 0

//define ISR
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


#endif /* INTERRUPT_H_ */