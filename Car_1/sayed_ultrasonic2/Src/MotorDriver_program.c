/* LIB */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "MotorDriver_config.h"
#include "MotorDriver_interface.h"

void H_MotorDriver_voidInit(void) {
	// Configure Control Pins for direction control
	MGPIO_voidSetPinMode(MOTION_MOTOR_ONE_PORT, MOTION_MOTOR_ONE_PIN_1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(MOTION_MOTOR_ONE_PORT, MOTION_MOTOR_ONE_PIN_2, OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinMode(MOTION_MOTOR_TWO_PORT, MOTION_MOTOR_TWO_PIN_1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(MOTION_MOTOR_TWO_PORT, MOTION_MOTOR_TWO_PIN_2, OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinMode(MOTION_MOTOR_THREE_PORT, MOTION_MOTOR_THREE_PIN_1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(MOTION_MOTOR_THREE_PORT, MOTION_MOTOR_THREE_PIN_2, OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinMode(MOTION_MOTOR_FOUR_PORT, MOTION_MOTOR_FOUR_PIN_1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(MOTION_MOTOR_FOUR_PORT, MOTION_MOTOR_FOUR_PIN_2, OUTPUT_SPEED_10MHZ_PP);
}



void H_MotorDriver_voidForward(void) {

	MGPIO_voidSetPinValue(MOTION_MOTOR_ONE_PORT, MOTION_MOTOR_ONE_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_ONE_PORT, MOTION_MOTOR_ONE_PIN_2, GPIO_HIGH);

	MGPIO_voidSetPinValue(MOTION_MOTOR_TWO_PORT, MOTION_MOTOR_TWO_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_TWO_PORT, MOTION_MOTOR_TWO_PIN_2, GPIO_HIGH);

	MGPIO_voidSetPinValue(MOTION_MOTOR_THREE_PORT, MOTION_MOTOR_THREE_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_THREE_PORT, MOTION_MOTOR_THREE_PIN_2, GPIO_HIGH);

	MGPIO_voidSetPinValue(MOTION_MOTOR_FOUR_PORT, MOTION_MOTOR_FOUR_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_FOUR_PORT, MOTION_MOTOR_FOUR_PIN_2, GPIO_HIGH);

}


void H_MotorDriver_voidStop(void){

	MGPIO_voidSetPinValue(MOTION_MOTOR_ONE_PORT, MOTION_MOTOR_ONE_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_ONE_PORT, MOTION_MOTOR_ONE_PIN_2, GPIO_LOW);

	MGPIO_voidSetPinValue(MOTION_MOTOR_TWO_PORT, MOTION_MOTOR_TWO_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_TWO_PORT, MOTION_MOTOR_TWO_PIN_2, GPIO_LOW);

	MGPIO_voidSetPinValue(MOTION_MOTOR_THREE_PORT, MOTION_MOTOR_THREE_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_THREE_PORT, MOTION_MOTOR_THREE_PIN_2, GPIO_LOW);

	MGPIO_voidSetPinValue(MOTION_MOTOR_FOUR_PORT, MOTION_MOTOR_FOUR_PIN_1, GPIO_LOW);
	MGPIO_voidSetPinValue(MOTION_MOTOR_FOUR_PORT, MOTION_MOTOR_FOUR_PIN_2, GPIO_LOW);
}
