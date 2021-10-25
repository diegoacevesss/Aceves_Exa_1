/*
 * PushB.h
 *
 *  Created on: 23 oct 2021
 *      Author: diegoacevess
 */

#ifndef PUSHB_H_
#define PUSHB_H_

#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"
#include "PIT.h"
#include "GPIO.h"


/*Configuramos los puertos para los botones*/
void initialize_pb(void);

/*
 	 \brief
 	 	 This function configures the frecuency 5,10 or 15 Hz.
 	 \param[in] void.
 	 \return uint8_t frecuency
*/
uint8_t next_freq(void);
uint8_t next_freq2(void);


#endif /* PUSHB_H_ */

