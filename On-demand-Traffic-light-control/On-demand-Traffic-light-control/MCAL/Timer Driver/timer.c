/*
 * timer.c
 *
 * Created: 9/28/2022 7:02:07 PM
 *  Author: Mohamed
 */ 

#include "timer.h"
#include <math.h>    // to use ceil()

void timer0_init()
{
	TCCR0 = 0x00;      //normal mode
	
//	TCNT0 = 0x00;     //timer initial value
}


int overFlowCounter = 0;
int numberOfOverflows = 1;

void timer0_delay(unsigned int millisecond)
{
	overFlowCounter = 0;
	//no prescaler
	//and Fcpu= 1 Mhz
	
	//1 tick time in ms
	float tick_time = 0.001;        //              //(1/1000000)   
	//2 max delay time in ms
	float max_delay = 0.256;      //         //ticktime * 2^8
	//3 number of over flows
	//uint8_t numberOfOverflows = 1; //= ;
	
	if(millisecond > max_delay)               //if required delay > max delay time
	{
		//3 get number of over flows
		numberOfOverflows = ceil(millisecond/max_delay);
		//int num = (millisecond/max_delay);
		//numberOfOverflows = num +1 ;
		//4 timer initial value
		TCNT0 = 256 - (millisecond/tick_time)/numberOfOverflows ;
	}
	
	else if(millisecond < max_delay)           // else if required delay < max delay
	{
		//4 timer initial value
		TCNT0 = (max_delay - millisecond)/tick_time ;		
	}
	
	else                                      // required delay = max delay
	{
		//4 timer initial value
		TCNT0 = 0;
	}
	
	
	//TCCR0 |= (1<<1) | (1<<0); //set 64 Prescaler   //start timer
	
	//TCCR0 |= (1<<2) | (1<<0); //set 1024 Prescaler   //start timer
	TCCR0 |= (1<<0);     //no prescaler

	while(overFlowCounter < numberOfOverflows)
	{
		//wait until over flow flag is set
		while((TIFR & (1<<0)) == 0 );

		//clear over flow flag
		TIFR |= (1<<0);

		overFlowCounter++;

	}

	TCCR0 = 0x00;           //stop timer

}



void delay_stop()
{
	overFlowCounter = numberOfOverflows;
}