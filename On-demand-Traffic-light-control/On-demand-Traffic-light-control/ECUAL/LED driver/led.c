/*
 * led.c
 *
 * Created: 9/24/2022 9:51:56 AM
 *  Author: Mohamed
 */ 


#include "led.h"
//#include "../../utilities/types.h"

EN_LED_ERROR_t LED_init (uint8_t portNum, uint8_t pinNum)
{
	if(DIO_init(portNum, pinNum, OUT) != OK) return LED_INIT_ERROR;
	return OK;
}


EN_LED_ERROR_t LED_on (uint8_t portNum, uint8_t pinNum)
{
	
	if(DIO_write(portNum, pinNum, HIGH) != OK) return LED_ON_ERROR;
	return OK;

}

EN_LED_ERROR_t LED_off (uint8_t portNum, uint8_t pinNum)
{
	if(DIO_write(portNum, pinNum, LOW) != OK) return LED_OFF_ERROR;
	return OK;

}

EN_LED_ERROR_t LED_toggle (uint8_t portNum, uint8_t pinNum)
{
	if(DIO_toggle(portNum, pinNum) != OK) return LED_TOGGLE_ERROR;
	return OK;
 
}