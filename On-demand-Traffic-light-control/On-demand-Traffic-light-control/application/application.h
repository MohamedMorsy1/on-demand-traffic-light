/*
 * application.h
 *
 * Created: 9/28/2022 7:01:32 PM
 *  Author: Mohamed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED driver/led.h"
#include "../ECUAL/button driver/button.h"
#include "../MCAL/Timer Driver/timer.h"

//mode enum

typedef enum EN_MODE_t
{
	normal, pedestrian, pedestrian_press
}EN_MODE_t;


void app_init(void);

void app_start(void);


#endif /* APPLICATION_H_ */