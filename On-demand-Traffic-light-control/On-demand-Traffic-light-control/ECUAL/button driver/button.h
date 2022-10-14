/*
 * button.h
 *
 * Created: 9/24/2022 11:28:43 AM
 *  Author: Mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO driver/dio.h"

//pedestrian button 
#define pedestrianButtonPort  'D'
#define pedestrianButtonPin    2

typedef enum EN_BUTTON_ERROR_t
{
	BUTTON_OK, BUTTON_INIT_ERROR, BUTTON_READ_ERROR
}EN_BUTTON_ERROR_t;


//initialize button pin
EN_BUTTON_ERROR_t button_init(uint8_t buttonPort, uint8_t buttonPin);

//read button state
EN_BUTTON_ERROR_t button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);



#endif /* BUTTON_H_ */