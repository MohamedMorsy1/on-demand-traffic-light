/*
 * timer.h
 *
 * Created: 9/28/2022 7:02:17 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../utilities/registers.h"   ////

void timer0_init();

void timer0_delay(unsigned int millisecond);

void delay_stop();


#endif /* TIMER_H_ */