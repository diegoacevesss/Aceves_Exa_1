/*
 * secuence.c
 *
 *  Created on: 25 oct 2021
 *      Author: diegoacevess
 */

#include "GPIO.h"
#include "RGB.h"
#include "PushB.h"
#include "PIT.h"

void color_secuence(){

	switch(led){

	case 1:
		GPIO_LED_ON(LED_BLU);
		break;
	case 2:
		GPIO_LED_ON(LED_GRN);
		break;
	case 3:
		GPIO_LED_ON(LED_RED);
		break;
	case 4:
		GPIO_LED_ON(LED_YLW);
		break;
	case 5:
		GPIO_LED_ON(LED_PRP);
		break;
	default:
		GPIO_LED_ON(LED_CYAN);
		break;
	}
}//end function
