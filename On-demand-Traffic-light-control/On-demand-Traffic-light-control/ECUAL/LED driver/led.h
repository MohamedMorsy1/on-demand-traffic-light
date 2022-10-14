/*
 * led.h
 *
 * Created: 9/24/2022 9:51:46 AM
 *  Author: Mohamed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO driver/dio.h"

//car LEDs pins
#define carLEDsPort               'A'
#define carGreenLEDpin             0
#define carYellowLEDpin			   1
#define carRedLEDpin			   2

//pedestrian LEDs pins
#define pedestrianLEDsPort        'B'
#define pedestrianGreenLEDpin	   0
#define pedestrianYellowLEDpin     1
#define pedestrianRedLEDpin        2

typedef enum EN_LED_ERROR_t
{
	LED_OK, LED_INIT_ERROR, LED_ON_ERROR, LED_OFF_ERROR, LED_TOGGLE_ERROR
}EN_LED_ERROR_t;

EN_LED_ERROR_t LED_init (uint8_t portNum, uint8_t pinNum);
EN_LED_ERROR_t LED_on (uint8_t portNum, uint8_t pinNum);
EN_LED_ERROR_t LED_off (uint8_t portNum, uint8_t pinNum);
EN_LED_ERROR_t LED_toggle (uint8_t portNum, uint8_t pinNum);


#endif /* LED_H_ */