/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_automatic.h"

void fsm_automatic_run(int lane){
	switch(LED_STATE[lane]){
		case INIT_STATE:
			setTrafficLightDefault(lane);
			if (lane == 0){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, 500);
			}
			else{
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, 300);
			}
			break;
		case RED_STATE:
			setTrafficLightRed(lane);
			if(timer_flag[lane] == 1){
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, 300);
			}
			break;
		case GREEN_STATE:
			setTrafficLightGreen(lane);
			if(timer_flag[lane] == 1){
				LED_STATE[lane] = AMBER_STATE;
				setTimer(lane, 200);
			}
			break;
		case AMBER_STATE:
			setTrafficLightAmber(lane);
			if(timer_flag[lane] == 1){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, 500);
			}
			break;
		default:
			break;
	}
}
