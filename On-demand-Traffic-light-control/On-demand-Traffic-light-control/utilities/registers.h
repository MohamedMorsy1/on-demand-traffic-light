/*
 * registers.h
 *
 * Created: 9/23/2022 9:48:35 PM
 *  Author: Mohamed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

//portA
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

//portB
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

//portC
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

//portD
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)


//timer 0
#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR  *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)


//ISR
#define MCUCSR *((volatile uint8_t*)0x54)
#define MCUCR  *((volatile uint8_t*)0x55)
#define GIFR   *((volatile uint8_t*)0x5A)
#define GICR   *((volatile uint8_t*)0x5B)
#define SREG   *((volatile uint8_t*)0x5F)



#endif /* REGISTERS_H_ */