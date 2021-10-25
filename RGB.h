/*
 * RGB.h
 *
 *  Created on: 13 sep 2021
 *  @author: diegoacevess
 *      Tarea 7 Stataes Machine
 *      ITESO
 *      Sistemas embebidos.
 */

#ifndef RGB_H_
#define RGB_H_

#include <stdio.h>
#include <stdint.h>
#include <sw3.h>
#include "MK64F12.h"
#include "GPIO.h"

/*! These constants are used to select an specific LED in the different API functions*/
typedef enum{LED_RED,
			 LED_BLU,
			 LED_YLW,
			 LED_PRP,
			 LED_GRN,
			 LED_WHITE,
			 LED_CYAN,
			LED_NON_COLOR,
			} led_color_t;

/*eThese constant is used to select when we want to turn on the LED*/
typedef enum{ON_OFF, /* Turn on if True */
			} ON_OFF_t;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
	 \This function configures the GPIOs for the RGB LED and sets a safe value for PDOR.
	 \return void
*/
void RGB_initialize(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \Select the Led that we want and turn on
 	 \return void
*/
void GPIO_LED_ON(led_color_t led);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \Select the Led that we want and turn off
 	 \return void
*/
void GPIO_LED_OFF(led_color_t led);

#endif /* RGB_H_ */
