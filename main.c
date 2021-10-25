/**
 * @file    Examen 1.c
 * @brief   Application entry point.
 * @author  Diego Aceves
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

	void RGB_initialize();
	initialize_pb();
	GPIO_LED_ON(LED_WHITE);
	GPIO_LED_ON(LED_GRN);



	}//end switch




	return 0 ;
}
