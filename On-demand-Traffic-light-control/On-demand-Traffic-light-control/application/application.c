/*
 * application.c
 *
 * Created: 9/28/2022 7:01:19 PM
 *  Author: Mohamed
 */ 

#include "application.h"
#include "../MCAL/Interrupt/interrupt.h"

void app_init(void)
{
	
	//initialize car LEDs
	LED_init(carLEDsPort, carGreenLEDpin);
	LED_init(carLEDsPort, carYellowLEDpin);
	LED_init(carLEDsPort, carRedLEDpin);
	
	//initialize pedestrian LEDs
	LED_init(pedestrianLEDsPort, pedestrianGreenLEDpin);
	LED_init(pedestrianLEDsPort, pedestrianYellowLEDpin);
	LED_init(pedestrianLEDsPort, pedestrianRedLEDpin);

	//initialize pedestrian button
	button_init(pedestrianButtonPort, pedestrianButtonPin);

	//enable global interrupts
	sei();
	
	//choose sense: rising edge
	INT0_risingEdge();
	
	//enable external interrupts
	INT0_enable();
	
	timer0_init();
}

EN_MODE_t mode=normal;

void app_start()
{
	while(1)
	{
		mode = normal;
	LED_on(carLEDsPort, carGreenLEDpin);                             //GREEN for cars
	LED_on(pedestrianLEDsPort, pedestrianRedLEDpin);                //RED for pedestrian
	timer0_delay(5000);                                            //if interrupted here. will stop delay and go to blink y led
																	//num3 in pedestrian mode in rubric
	LED_off(carLEDsPort, carGreenLEDpin);
	LED_off(pedestrianLEDsPort, pedestrianRedLEDpin);
		
		for(int i=0;i<10;i++)
		{                                     //interrupt stops the previus delay
		if(mode == pedestrian)               //interrupt start blinking for 5 sec==> num3 in pedestrian mode in rubric
		{
			i = 0;
			LED_on(pedestrianLEDsPort, pedestrianRedLEDpin);                //RED for pedestrian
			mode = pedestrian_press;                //to prevent double press
		}
		LED_toggle(carLEDsPort,carYellowLEDpin);
		LED_toggle(pedestrianLEDsPort,pedestrianYellowLEDpin);
		timer0_delay(500);	
				
		}
		
		LED_off(carLEDsPort, carYellowLEDpin);
		LED_off(pedestrianLEDsPort, pedestrianYellowLEDpin);	
		
	mode = normal;
	
	LED_off(pedestrianLEDsPort, pedestrianRedLEDpin);
	LED_on(carLEDsPort, carRedLEDpin);                              //RED for Cars
	LED_on(pedestrianLEDsPort, pedestrianGreenLEDpin);              //GREEN for pedestrian
	
	timer0_delay(5000); //interrupt should cancel this delay !?
	
	if(mode == pedestrian)               //interrupt extends the delay==> num2 in pedestrian mode in rubric
	{
		 timer0_delay(5000);         // this will not listen to another button press
		mode = normal;
	}
	LED_off(carLEDsPort, carRedLEDpin);
	LED_off(pedestrianLEDsPort, pedestrianGreenLEDpin);
	
		for(int i=0;i<10;i++)
		{
			LED_toggle(carLEDsPort,carYellowLEDpin);
			LED_toggle(pedestrianLEDsPort,pedestrianYellowLEDpin);
			timer0_delay(500);
		}
	
	}
	
}


ISR(INT_EXT_0)
{
	 
	if(mode == normal)
	{	
	 delay_stop();            ///to prevent delay stop in double press
	
	 mode = pedestrian;
	}
}