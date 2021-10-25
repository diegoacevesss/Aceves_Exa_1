/*
 * RGB.c
 *
 *  Created on: 13 sep 2021
 *  @author: diegoacevess
 *      ITESO
 *      Sistemas embebidos.
 */

#include "MK64F12.h"
#include "GPIO.h"
#include "Bits.h"
#include "RGB.h"

void RED_on(){

	GPIO_clock_gating(GPIO_B); /* Se activa el clock gating para GPIOB */
	GPIO_pin_control_register(GPIO_B,bit_22,&pcr_gpiob_red_led);/* */
	GPIO_set_pin(GPIO_B,bit_22);/* */
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,bit_22);/*Configuramos como output pin 22*/
	return(TRUE);

}/* End function */

void GREEN_on(){

	GPIO_clock_gating(GPIO_E); /*Se activa el clock gating para GPIOE */
	GPIO_pin_control_register(GPIO_E,bit_26,&pcr_gpiob_green_led);/* */
	GPIO_set_pin(GPIO_E,bit_26); /* */
	GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,bit_26);/*Configuramos como output pin 26*/
	return(TRUE);

}/* End function */

void BLUE_on(){

	GPIO_clock_gating(GPIO_B); /* Se activa el clock gating para GPIOB */
	GPIO_pin_control_register(GPIO_B,bit_21,&pcr_gpiob_red_led);/* */
	GPIO_set_pin(GPIO_B,bit_21);/* */
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,bit_21);/*Configuramos como output pin 21*/
	return(TRUE);

}/* End function */

void RGB_all_on(void){

	RED_on(); /* Configuracion del rojo*/
	GREEN_on(); /* Configuracion del verde*/
	BLUE_on(); /* Configuracion del azul*/
	return(TRUE);

}/* End function */

void RGB_on(uint32_t led){

	switch(){
		case RED:
			GPIO_clear_pin(GPIO_B, bit_22);
			break;
		case GREEN:
			GPIO_clear_pin(GPIO_E, bit_26);
			break;
		case BLUE:
			GPIO_clear_pin(GPIO_B, bit_21);
			break;
		case PURPLE:
			GPIO_clear_pin(GPIO_B, bit_22);
			GPIO_clear_pin(GPIO_B, bit_21);
			break;
		case CYAN:
			GPIO_clear_pin(GPIO_E, bit_26);
			GPIO_clear_pin(GPIO_B, bit_21);
			break;
		case WHITE:
			GPIO_clear_pin(GPIO_B, bit_21);
			GPIO_clear_pin(GPIO_B, bit_22);
			GPIO_clear_pin(GPIO_E, bit_26);
		case YELLOW:
			GPIO_clear_pin(GPIO_B, bit_22);
			GPIO_clear_pin(GPIO_E, bit_26);
			break;
		default:
			return(FALSE);
		break;
	}/* End switch */
}/* End function */

void RGB_off(uint32_t led){
	switch()
	{
		case RED:
			GPIO_set_pin(GPIO_B, bit_22);
			break;
		case GREEN:
			GPIO_set_pin(GPIO_E, bit_26);
			break;
		case BLUE:
			GPIO_set_pin(GPIO_B, bit_21);
			break;
		case PURPLE:
			GPIO_set_pin(GPIO_B, bit_22);
			GPIO_set_pin(GPIO_B, bit_21);
			break;
		case CYAN:
			GPIO_set_pin(GPIO_E, bit_26);
			GPIO_set_pin(GPIO_B, bit_21);
			break;
		case WHITE:
			GPIO_set_pin(GPIO_B, bit_22);
			GPIO_set_pin(GPIO_B, bit_21);
			GPIO_set_pin(GPIO_E, bit_26);
			break;
		case YELLOW:
			GPIO_set_pin(GPIO_B, bit_22);
			GPIO_set_pin(GPIO_E, bit_26);
			break;
		default:
			return(FALSE);
	}/* End switch*/
}/* End function */

