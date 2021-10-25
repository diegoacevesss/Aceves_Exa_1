/*
 * GPIO.c
 *
 *  Created on: 17 sept 2021
 *      Author: diegoacevess & Alejandro Covarrubias
 */

#include "MK64F12.h"
#include "GPIO.h"
#include <sw3.h>

static void (*gpio_C_callback)(void) = 0;
static void (*gpio_A_callback)(void) = 0;

static gpio_interrupt_flags_t g_intr_status_flag = {0};

void GPIO_clear_interrupt(gpio_port_name_t port_name)
{
	switch(port_name)/** Selecting the GPIO for clock enabling*/
		{
			case GPIO_A: /** GPIO A is selected*/
				PORTA->ISFR=0xFFFFFFFF;
				break;
			case GPIO_B: /** GPIO B is selected*/
				PORTB->ISFR=0xFFFFFFFF;
				break;
			case GPIO_C: /** GPIO C is selected*/
				PORTC->ISFR = 0xFFFFFFFF;
				break;
			case GPIO_D: /** GPIO D is selected*/
				PORTD->ISFR=0xFFFFFFFF;
				break;
			default: /** GPIO E is selected*/
				PORTE->ISFR=0xFFFFFFFF;
				break;
		}//end function
}

uint8_t GPIO_clock_gating(gpio_port_name_t port_name)
{
	switch(port_name)/** Selecting the GPIO for clock enabling*/
		{
			case GPIO_A: /** GPIO A is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA; /** Bit 9 of SIM_SCGC5 is  set*/
				break;
			case GPIO_B: /** GPIO B is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTB; /** Bit 10 of SIM_SCGC5 is set*/
				break;
			case GPIO_C: /** GPIO C is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTC; /** Bit 11 of SIM_SCGC5 is set*/
				break;
			case GPIO_D: /** GPIO D is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTD; /** Bit 12 of SIM_SCGC5 is set*/
				break;
			case GPIO_E: /** GPIO E is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTE; /** Bit 13 of SIM_SCGC5 is set*/
				break;
			default: /**If doesn't exist the option*/
				return(FALSE);
		}// end switch
	/**Successful configuration*/
	return(TRUE);
}// end function

uint8_t GPIO_pin_control_register(gpio_port_name_t port_name, uint8_t pin,const gpio_pin_control_register_t*  pinControlRegister)
{

	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			PORTA->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_B:/** GPIO B is selected*/
			PORTB->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_C:/** GPIO C is selected*/
			PORTC->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_D:/** GPIO D is selected*/
			PORTD->PCR[pin] = *pinControlRegister;
			break;
		case GPIO_E: /** GPIO E is selected*/
			PORTE->PCR[pin]= *pinControlRegister;
		default:/**If doesn't exist the option*/
			return(FALSE);
		break;
		}
	/**Successful configuration*/
	return(TRUE);
}

void GPIO_data_directionPORT(gpio_port_name_t port_name, uint32_t direction)
{
	switch(port_name)	/*Selecting the port*/
		{
		case GPIO_A:  /** GPIO A is selected*/
			GPIOA->PDDR |= direction;
			break;
		case GPIO_B:  /** GPIO B is selected*/
			GPIOB->PTOR |= direction;
			break;
		case GPIO_C:  /** GPIO C is selected*/
			GPIOC->PTOR |= direction;
			break;
		case GPIO_D:  /** GPIO D is selected*/
			GPIOD->PTOR |= direction;
			break;
		case GPIO_E:  /** GPIO E is selected*/
			GPIOE->PTOR |= direction;
			break;
		default:	  /**Port doesn't exist*/
		break;
		}//end switch
}//end function


void GPIO_data_direction_pin(gpio_port_name_t port_name, uint8_t state, uint8_t pin)
{
	switch(port_name)
		{
			case GPIO_A: /** GPIO A is selected*/
				GPIOA->PDDR &= ~(TRUE << pin);
				GPIOA->PDDR |= state << pin;
				break;

			case GPIO_B: /** GPIO B is selected*/
				GPIOB->PDDR &= ~(TRUE << pin);
				GPIOB->PDDR |= state << pin;
				break;

			case GPIO_C: /** GPIO C is selected*/
				GPIOC->PDDR &= ~(TRUE << pin);
				GPIOC->PDDR |= state << pin;
				break;

			case GPIO_D: /** GPIO D is selected*/
				GPIOD->PDDR &= ~(TRUE << pin);
				GPIOD->PDDR |= state << pin;
				break;

			case GPIO_E: /** GPIO E is selected*/
				GPIOE->PDDR &= ~(TRUE << pin);
				GPIOE->PDDR |= state << pin;
				break;

			default:
				break;
		}// end switch
} //end function

uint32_t GPIO_read_port(gpio_port_name_t port_name)
{
	uint32_t data;
	switch(port_name)/** Selecting the port*/
		{
		case GPIO_A: /** GPIO A is selected*/
			data = GPIOA->PDIR;/**Reads data from port A*/
			break;
		case GPIO_B: /** GPIO B is selected*/
			data = GPIOB->PDIR;/**Reads data from port A*/
			break;
		case GPIO_C: /** GPIO C is selected*/
			data = GPIOC->PDIR;/**Reads data from port A*/
			break;
		case GPIO_D: /** GPIO D is selected*/
			data = GPIOD->PDIR;/**Reads data from port A*/
			break;
		case GPIO_E: /** GPIO E is selected*/
			data = GPIOE->PDIR;/**Reads data from port A*/
		default: /** Port doesn't exist*/
		break;
		} // end switch
	/** Return data read from the port*/
	return data;
}//end function

uint8_t GPIO_read_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name) /** Selecting the port*/
		{
			case GPIO_A: /** GPIO A is selected*/
				return((GPIOA->PDIR >> pin) & 0x01);
				break;
			case GPIO_B: /** GPIO B is selected*/
				return((GPIOB->PDIR >> pin) & 0x01);
				break;
			case GPIO_C: /** GPIO C is selected*/
				return((GPIOC->PDIR >> pin) & 0x01);
				break;
			case GPIO_D: /** GPIO D is selected*/
				return((GPIOD->PDIR >> pin) & 0x01);
				break;
			case GPIO_E: /** GPIO E is selected*/
				return((GPIOE->PDIR >> pin) & 0x01);
				break;
			default: /**If doesn't exist the option*/
				return(FALSE);
				break;
		}//end switch
}//end Function

void GPIO_write_port(gpio_port_name_t port_name, uint32_t data)
{
	switch(port_name) /** Selecting the port*/
		{
			case GPIO_A: /** GPIO A is selected*/
				GPIOA->PDOR = data;
				break;
			case GPIO_B: /** GPIO B is selected*/
				GPIOB->PDOR = data;
				break;
			case GPIO_C: /** GPIO C is selected*/
				GPIOC->PDOR = data;
				break;
			case GPIO_D: /** GPIO D is selected*/
				 GPIOD->PDOR = data;
				break;
			case GPIO_E: /** GPIO E is selected*/
				 GPIOE->PDOR = data;
			default: /**Port does not exist*/
			break;
		}//end switch
}//end function


void GPIO_set_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name) /** Selecting the port*/
		{
			case GPIO_A: /** GPIO A is selected*/
				GPIOA->PSOR |= (TRUE << pin);
				break;
			case GPIO_B: /** GPIO B is selected*/
				GPIOB->PSOR |= (TRUE << pin);
				break;
			case GPIO_C: /** GPIO C is selected*/
				GPIOC->PSOR |= (TRUE << pin);
				break;
			case GPIO_D: /** GPIO D is selected*/
				GPIOD->PSOR |= (TRUE << pin);
				break;
			case GPIO_E: /** GPIO E is selected*/
				GPIOE->PSOR |= (TRUE << pin);
				break;
			default: /**Port does not exist*/

			break;
		}//end switch
}//end function

void GPIO_clear_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name) /** Selecting the port*/
		{
			case GPIO_A: /** GPIO A is selected*/
				GPIOA->PCOR |= (TRUE << pin);
				break;
			case GPIO_B: /** GPIO B is selected*/
				GPIOB->PCOR |= (TRUE << pin);
				break;
			case GPIO_C: /** GPIO C is selected*/
				GPIOC->PCOR |= (TRUE << pin);
				break;
			case GPIO_D: /** GPIO D is selected*/
				GPIOD->PCOR |= (TRUE << pin);
				break;
			case GPIO_E: /** GPIO E is selected*/
				GPIOE->PCOR |= (TRUE << pin);
				break;
			default: /**Port does not exist*/

			break;
		}//end switch
}//end function

void GPIO_toogle_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name) /** Selecting the port*/
		{
		case GPIO_A: /** GPIO A is selected*/
			GPIOA->PTOR |= (TRUE << pin);
			break;
		case GPIO_B: /** GPIO B is selected*/
			GPIOB->PTOR |= (TRUE << pin);
			break;
		case GPIO_C: /** GPIO C is selected*/
			GPIOC->PTOR |= (TRUE << pin);
			break;
		case GPIO_D: /** GPIO D is selected*/
			GPIOD->PTOR |= (TRUE << pin);
			break;
		case GPIO_E: /** GPIO E is selected*/
			GPIOE->PTOR |= (TRUE << pin);
			break;
			default: /**Port does not exist*/
			break;
		} //end switch
} //end function


void GPIO_callback_init(gpio_port_name_t port_name,void (*handler)(void))
{
	if(GPIO_A == port_name)
	{
		gpio_A_callback = handler;
	}
	else
	{
		gpio_C_callback = handler;
	}
}
