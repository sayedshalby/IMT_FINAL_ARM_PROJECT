

/*LIB */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "LCD_int.h"
#include "TIMERx_interface.h"
#include "ULTRASONIC_interface.h"
#include "USART_INTERFACE.h"
#include "MotorDriver_interface.h"


u16 B_SIDE_Distance =0;
u16 F_SIDE_Distance =0;


int main()
{


	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2,APB2_AFIOEN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOAEN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOBEN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOCEN);
	MRCC_voidEnableClock(RCC_APB1,APB1_TIM2EN);
	MRCC_voidEnableClock(RCC_APB2, APB2_USART1EN);

	MNVIC_voidEnableInterrupt(37);
	MNVIC_voidEnableInterrupt(28);

	MGPIO_voidSetPinMode(GPIO_A,PIN9,OUTPUT_SPEED_2MHZ_AFPP);//TX
	MGPIO_voidSetPinMode(GPIO_A,PIN9,INPUT_FLOATING);//RX

	MGPIO_voidSetPinMode(GPIO_B,PIN0,OUTPUT_SPEED_10MHZ_PP); //LED
	MGPIO_voidSetPinValue(GPIO_B,PIN0,GPIO_LOW);

		HUS_voidInit();
		MSTK_voidInit();
		MUSART_VidInit();
		H_MotorDriver_voidInit();
		H_MotorDriver_voidForward();


	  	while(1)
	  	{

	  		MGPIO_voidSetPinValue(GPIO_B,PIN0,GPIO_LOW);
	  		HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);//front


	  		HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance); //back

			MSTK_voidSetBusyWait(50);

			if(F_SIDE_Distance > 20 && B_SIDE_Distance > 30){

				H_MotorDriver_voidForward();
				MUSART1_VidSendCharSync('S');
				HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);//front
			    HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance); //back
			}

			else if (F_SIDE_Distance <= 20 && B_SIDE_Distance <= 30){
				MGPIO_voidSetPinValue(GPIO_B,PIN0,GPIO_HIGH);
				H_MotorDriver_voidStop();
				MUSART1_VidSendCharSync('A');
				HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);//front
				HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance); //back
				MSTK_voidSetBusyWait(50);
			}

			else if(B_SIDE_Distance <= 30){
				MGPIO_voidSetPinValue(GPIO_B,PIN0,GPIO_HIGH);
				H_MotorDriver_voidForward();
				MUSART1_VidSendCharSync('B');
				HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);//front
			    HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance); //back
				MSTK_voidSetBusyWait(50);
			}

			else if(F_SIDE_Distance <= 20){
				MGPIO_voidSetPinValue(GPIO_B,PIN0,GPIO_HIGH);
				 H_MotorDriver_voidStop();
				MUSART1_VidSendCharSync('C');
				HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);//front
				HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance); //back
				MSTK_voidSetBusyWait(50);
			}




/*

			if(F_SIDE_Distance <= 20 && B_SIDE_Distance > 30){  //back ultra

				H_MotorDriver_voidStop();
				MSTK_voidSetBusyWait(3000);
				MUSART1_VidSendCharSync('A');
			    //MSTK_voidSetBusyWait(3000);
			    HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);
			  //  MSTK_voidSetBusyWait(1000);
			    HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance);
			 //   MSTK_voidSetBusyWait(1000);
			    //continue;
			}

			 else if(F_SIDE_Distance > 20 && B_SIDE_Distance <= 30 ){  //front ultra
				 MSTK_voidSetBusyWait(3000);
				 MUSART1_VidSendCharSync('B');
			//   MSTK_voidSetBusyWait(3000);
			   HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);
			 //  MSTK_voidSetBusyWait(1000);
			   HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance);
			  // MSTK_voidSetBusyWait(1000);
			  // continue;
			}

			 else if ((F_SIDE_Distance <= 20) && (B_SIDE_Distance <= 30) && (B_SIDE_Distance || F_SIDE_Distance != 0)){
			//MUSART1_VidSendCharSync('S');
				//MSTK_voidSetBusyWait(3000);
				 H_MotorDriver_voidStop();
				 MSTK_voidSetBusyWait(3000);
					MUSART1_VidSendCharSync('C');
					//MSTK_voidSetBusyWait(3000);
					HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);
					//MSTK_voidSetBusyWait(1000);
								HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance);
							//	MSTK_voidSetBusyWait(1000);
					//continue;
			 }

			 else if((F_SIDE_Distance > 20) && (B_SIDE_Distance > 30)){
				 H_MotorDriver_voidForward();
				 MUSART1_VidSendCharSync('S');
				 MSTK_voidSetBusyWait(3000);
				 HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);
				 //MSTK_voidSetBusyWait(1000);
				 HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance);
				// MSTK_voidSetBusyWait(1000);
				// continue;
			 }
			 else{

			 }
			 */

			//MSTK_voidSetBusyWait(3000);
/*
		//	else{

		//	}
			//res = (u32)F_SIDE_Distance;
			//MSTK_voidSetBusyWait(200);
			//Lcd_SetCursorPosition(0 , 9);
			//HLCD_voidShiftDisplayRight();
			//Lcd_SetCursorPosition(0 , 10);
			//Lcd_DisplayNumber(F_SIDE_Distance);
			//MSTK_voidSetBusyWait(4000);

			//HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance);
			//HLCD_voidDispIntNum(B_SIDE_Distance);

			//HUS_voidGetDistance(US_F_SIDE, &F_SIDE_Distance);
			//HUS_voidGetDistance(US_B_SIDE, &B_SIDE_Distance);
			//HUS_voidGetDistance(US_BACK, &BACK_Distance);
//	  		MGPIO_voidSetPinValue(GPIO_C,PIN13,GPIO_LOW);
	  		if(FRONT_Distance < 15)
	  		{
	  			MGPIO_voidSetPinValue(GPIO_A,PIN11,GPIO_HIGH);
	  		}
	  		else
	  		{
	  			MGPIO_voidSetPinValue(GPIO_A,PIN11,GPIO_LOW);

	  		}
*/

	  	}

}
