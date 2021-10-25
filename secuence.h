/*
 * secuence.h
 *
 *  Created on: 25 oct 2021
 *      Author: diegoacevess
 */

#ifndef SECUENCE_H_
#define SECUENCE_H_

#include "GPIO.h"
#include "RGB.h"
#include "PushB.h"
#include "PIT.h"

typedef struct
{

}seq_t;

void color_secuence();
void color_secuence_interrupt(void);
uint8_t secuence read(void);

#endif /* SECUENCE_H_ */
