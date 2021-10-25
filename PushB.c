/*
 * PushB.c
 *
 *  Created on: 23 oct 2021
 *      Author: diegoacevess
 */

#include "PushB.h"

typedef enum {
	Hz_5,
	Hz_10,
	Hz_15,
	Act_fre,
}State_name_tb;

typedef struct
{
	State_name_tb frec;
	uint8_t next[4];
}State_tb;

const State_tb FSM_Moore_PB[3]=
		{
			{Hz_5,{Hz_5,Hz_10,Hz_15,Hz_5}},/* 5Hz */
			{Hz_10,{Hz_5,Hz_10,Hz_15,Hz_10}},/* 10Hz */
			{Hz_15,{Hz_5,Hz_10,Hz_15,Hz_15}},/* 15Hz */
		};
/*Asignamos el default a la maquina de estados*/
State_name_tb  current_state_PB = Hz_5;
/*Configuramos los pines*/
gpio_pin_control_register_t pcr_gpioc_pin_10 = GPIO_MUX1|GPIO_PE|GPIO_PS;
gpio_pin_control_register_t pcr_gpioc_pin_11 = GPIO_MUX1|GPIO_PE|GPIO_PS;

void initialize_pb(void){
	GPIO_clock_gating(GPIO_C);
	GPIO_pin_control_register(GPIO_C,bit_10,&pcr_gpioc_pin_10);
	GPIO_pin_control_register(GPIO_C,bit_11,&pcr_gpioc_pin_11);
	GPIO_data_direction_pin(GPIO_C,GPIO_INPUT, bit_10);
	GPIO_data_direction_pin(GPIO_C,GPIO_INPUT, bit_11);
}

uint8_t next_freq(void){
	uint8_t total =0;
	State_name_tb  current_state0 = current_state_PB;
	uint8_t switch_value0 = GPIO_read_pin(GPIO_C, bit_10);
	uint8_t switch_value1 = GPIO_read_pin(GPIO_C, bit_11);
	switch_value0 = switch_value0 >> 10;
	switch_value1 = switch_value1 >> 10;
	total = switch_value0|switch_value1;
	current_state_PB = FSM_Moore_PB[current_state_PB].next[total];
	switch(current_state_PB){
	case 0:
		return 5;
		break;
	case 1:
		return 10;
		break;
	default:
		break;
	}
}

uint8_t next_freq2(void){
	uint8_t total =0;
	State_name_tb  current_state0 = current_state_PB;
	uint8_t switch_value0 = GPIO_read_pin(GPIO_C, bit_10);
	uint8_t switch_value1 = GPIO_read_pin(GPIO_C, bit_11);
	switch_value0 = switch_value0 >> 10;
	switch_value1 = switch_value1 >> 10;
	total = switch_value0|switch_value1;
	current_state_PB = FSM_Moore_PB[current_state_PB].next[total];
	switch(current_state_PB){
	case 0:
		return 5;
		break;
	case 2:
		return 15;
		break;
	default:
		break;
	}
}
