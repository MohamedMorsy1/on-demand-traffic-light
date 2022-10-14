/*
 * button.c
 *
 * Created: 9/24/2022 11:28:54 AM
 *  Author: Mohamed
 */ 

#include "button.h"

//initialize button pin
EN_BUTTON_ERROR_t button_init(uint8_t buttonPort, uint8_t buttonPin)
{
	if(DIO_init(buttonPort, buttonPin , IN) != OK) return BUTTON_INIT_ERROR;
 }


//read button state
EN_BUTTON_ERROR_t button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	if(DIO_read(buttonPort, buttonPin, value) != OK) return BUTTON_READ_ERROR;
 }