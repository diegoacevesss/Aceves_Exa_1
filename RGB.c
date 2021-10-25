/*
 * RGB.c
 *
 *  Created on: 13 sep 2021
 *  @author: diegoacevess
 *      Tarea 7 States Machine
 *      ITESO
 *      Sistemas embebidos.
 */

#include <sw3.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"

#define GPIOB_OFF_CONST (0xFFFFFFFFU)
#define GPIOE_OFF_CONST (0xFFFFFFFFU)

gpio_pin_control_register_t pcr_gpiob_pin_21 = GPIO_MUX1;
gpio_pin_control_register_t pcr_gpiob_pin_22 = GPIO_MUX1;
gpio_pin_control_register_t pcr_gpioe_pin_26 = GPIO_MUX1;

void RGB_initialize(void){
	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_E);

	GPIO_pin_control_register(GPIO_B,bit_21,&pcr_gpiob_pin_21);
	GPIO_pin_control_register(GPIO_B,bit_22,&pcr_gpiob_pin_22);
	GPIO_pin_control_register(GPIO_E,bit_26,&pcr_gpioe_pin_26);

	GPIO_write_port(GPIO_B, GPIOB_OFF_CONST);
	GPIO_write_port(GPIO_E, GPIOE_OFF_CONST);

	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT, bit_21);
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,bit_22);
	GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,bit_26);
}

//Led to light
void GPIO_LED_ON(led_color_t led)
{
	switch(led)
			{
				case LED_RED:
						GPIO_set_pin(GPIO_B, bit_21);/**Blue led off*/
						GPIO_set_pin(GPIO_E, bit_26);/**Green led off*/
						GPIOB->PDOR &= ~(0x00400000);/**Red led on*/
					break;
				case LED_BLU:
						GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
						GPIO_set_pin(GPIO_E, bit_26);/**Green led off*/
						GPIO_clear_pin(GPIO_B, bit_21);/**Blue led on*/
					break;
				case LED_YLW:
						GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
						GPIO_set_pin(GPIO_E, bit_26);
						GPIO_set_pin(GPIO_B, bit_21);/**Blue led off*/
						/**Red led on*/
						GPIO_clear_pin(GPIO_B, bit_22);
						GPIO_clear_pin(GPIO_E, bit_26);/**Green led on*/

					break;
				case LED_PRP:
						GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
						GPIO_set_pin(GPIO_B, bit_21);
						GPIO_set_pin(GPIO_E, bit_26);/**Green led off*/
						GPIO_clear_pin(GPIO_B, bit_22);
						GPIO_clear_pin(GPIO_B, bit_21);
					break;
				case LED_GRN:
						GPIO_set_pin(GPIO_B, bit_21);/**Blue led off*/
						GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
						GPIO_clear_pin(GPIO_E, bit_26);/**Green led on*/
					break;
				case LED_WHITE:
						GPIO_set_pin(GPIO_B, bit_21);
						GPIO_set_pin(GPIO_B, bit_22);
						GPIO_set_pin(GPIO_E, bit_26);
						GPIO_clear_pin(GPIO_B, bit_21);
						GPIO_clear_pin(GPIO_B, bit_22);
						GPIO_clear_pin(GPIO_E, bit_26);
					break;
				case LED_CYAN:
					GPIO_clear_pin(GPIO_E, bit_26);
					GPIO_clear_pin(GPIO_B, bit_21);
					break;
				case LED_NON_COLOR:
					GPIO_set_pin(GPIO_B, bit_21);
					GPIO_set_pin(GPIO_B, bit_22);
					GPIO_set_pin(GPIO_E, bit_26);
					break;
				default:
					return;
			}

		return;
}

//Led to turn off
void GPIO_LED_OFF(led_color_t led){
switch(led)
		{
			case LED_RED:
				GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
				break;
			case LED_BLU:
				GPIO_set_pin(GPIO_B, bit_21);/**Blue led off*/
				break;
			case LED_YLW:
				GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
				GPIO_set_pin(GPIO_E, bit_26);/**Green led off*/
				break;
			case LED_PRP:
				GPIO_set_pin(GPIO_B, bit_22);/**Red led off*/
				GPIO_set_pin(GPIO_B, bit_21);/**Blue led off*/
				break;
			case LED_GRN:
				GPIO_set_pin(GPIO_E, bit_26);/**Green led off*/
				break;
			case LED_WHITE:
				GPIO_set_pin(GPIO_B, bit_21);
				GPIO_set_pin(GPIO_B, bit_22);
				GPIO_set_pin(GPIO_E, bit_26);
				break;
			case LED_NON_COLOR:
				GPIO_set_pin(GPIO_B, bit_21);
				GPIO_set_pin(GPIO_B, bit_22);
				GPIO_set_pin(GPIO_E, bit_26);
				break;
			default:
				return;
		}

	return;
}
