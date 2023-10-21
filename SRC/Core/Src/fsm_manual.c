/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(MODE){
		case MODE_1:
			fsm_automatic_run(0);
			fsm_automatic_run(1);
			if (isButton1Pressed() == 1){
				setTrafficLightDefault(0);
				setTrafficLightDefault(1);
				display7SEG(0, 2);
				display7SEG(1, 0);
				display7SEG(2, 0);
				display7SEG(3, 0);
				MODE = MODE_2;
				setTimer(2, 25);
			}

			break;
		case MODE_2:
			if (isButton1Pressed() == 1){
				display7SEG(0, 3);
				display7SEG(1, 0);
				display7SEG(2, 0);
				display7SEG(3, 0);
				MODE = MODE_3;
				setTimer(2, 25);
			}
			if (timer_flag[2] == 1){
				HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
				HAL_GPIO_TogglePin(GPIOA, RED2_Pin);
				setTimer(2, 25);
			}
			break;
		case MODE_3:
			if (isButton1Pressed() == 1){
				display7SEG(0, 4);
				display7SEG(1, 0);
				display7SEG(2, 0);
				display7SEG(3, 0);
				MODE = MODE_4;
				setTimer(2, 25);
			}
			if (timer_flag[2] == 1){
				HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);
				HAL_GPIO_TogglePin(GPIOA, YELLOW2_Pin);
				setTimer(2, 25);
			}
			break;
		case MODE_4:
			if (isButton1Pressed() == 1){
				MODE = MODE_1;
				setTimer(2, 25);
			}
			if (timer_flag[2] == 1){
				HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);
				HAL_GPIO_TogglePin(GPIOA, GREEN2_Pin);
				setTimer(2, 25);
			}
			break;
		default:
			 break;
	}
}
