/*
 * button.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int TimerForKeyPress = 200;

void subKeyProcess(){
	button1_flag = 1;
	button2_flag = 1;
	button3_flag = 1;
}

void getKeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if (KeyReg3 != KeyReg2){
			KeyReg3 == KeyReg2;
			if (KeyReg2 == PRESSED_STATE){
				subKeyProcess();
				TimerForKeyPress = 200;
			}
		}
		else{
			TimerForKeyPress--;
			if (TimerForKeyPress <= 0){
				KeyReg3 = NORMAL_STATE;
			}
		}
	}
}
