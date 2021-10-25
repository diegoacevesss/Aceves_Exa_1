/*
 * RGB.h
 *
 *  Created on: 13 sep 2021
 *  @author: diegoacevess
 *      ITESO
 *      Sistemas embebidos.
 */

#ifndef RGB_H_
#define RGB_H_

#include "MK64F12.h"
#include "GPIO.h"
#include "Bits.h"

/* Definition of the constants to select an specific from the different combinations
 * of the RGB
 */
typedef enum{
		RED,	/*!< Definition to select the color red */
		GREEN,	/*!< Definition to select the color green */
		BLUE,	/*!< Definition to select the color blue */
		PURPLE, /*!< Definition to select the color purple */
		YELLOW, /*!< Definition to select the color yellow */
		CYAN,	/*!< Definition to select the color cyan */
		WHITE,	/*!< Definition to select the color white */
		OFF     /*!< Definition to select turn off colors */
} led;

/* Functions to turn on each LED */
/*This was modified because I had a switch in this part
 * so it was necessary to make an especific function
 * for each one.
 */

void RED_on(void);
void GREEN_on(void);
void BLUE_on(void);
void RGB_all_on(void);
void RGB_on(uint32_t led);
void RGB_off(uint32_t led);


#endif /* RGB_H_ */
