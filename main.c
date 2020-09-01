/*********************************************************************************************
 * Author      : Heba Safwat
 * Date        : 26 / 8 / 2020
 * Version     : v01
 * Description : code to do the LED animation
 *********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"

/*function to start the Animation*/
void LED_voidSTARTAnimation(void);
/*function to make a delay*/
void Delay_Void500MS(void);
/*function to do the first sequence */
void LED_VoidShiftRightShiftLeft(void);
/*function to do the second sequence*/
void LED_VoidTwoLedOnOff(void);
/*function to do the third sequence*/
void LED_VoidFlashLeds(void);

int main (void)
{
	/*initialize the clock of the system*/
	RCC_voidInitSysClock();                /*configure the internal clock*/
	/*initialize the clock for the GPIO port A*/
	RCC_voidEnableClock(RCC_APB2 , 2); /*PORTA is in AHP2 and has the ID 2*/
	/*configure 8 pins in PORTA as output port with speed 2MHz push pull*/
	MGPIO_voidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN4 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN5 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN6 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA , PIN7 , OUTPUT_SPEED_2MHZ_PP);

	/*Reset PORTA*/
	MGPIO_voidResetPort(GPIOA);
	while (1)
	{
		LED_voidSTARTAnimation();
	}
	return 0;
}

/*******************************function to start the Animation*************************/
void LED_voidSTARTAnimation(void)
{
	u8 count = 0;                  /*local variable for counting*/
	while(count <4)
	{
		LED_VoidShiftRightShiftLeft();
		count ++;
	}
	while ((count >=4) && (count <8))
	{
		LED_VoidTwoLedOnOff();
		count ++;
	}
	while ((count >=8) && (count <12))
	{
		LED_VoidFlashLeds();
		count ++;
	}
}
/*******************************function to make a delay*******************************/
void Delay_Void500MS(void)
{
	u32 i;
	for(i=0;i<100000;i++)
	{

	}
}
/*******************************function to do the first sequence******************************/
void LED_VoidShiftRightShiftLeft(void)
{
	/*                    the Right sequence                     */
	LED_VoidLedON (GPIOA,PIN0 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN1 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN2 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN3 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN4 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN5 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN6 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN7 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	/*                 the left sequence                       */
	LED_VoidLedON (GPIOA,PIN7 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN6 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN5 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN4 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN3 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN2 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN1 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
	LED_VoidLedON (GPIOA,PIN0 );
	Delay_Void500MS();
	MGPIO_voidResetPort(GPIOA);
}
/*******************************function to do the second sequence*******************************/
void LED_VoidTwoLedOnOff(void)
{
	/*Make the LEDs ON*/
	LED_VoidLedON (GPIOA,PIN3 );
	LED_VoidLedON (GPIOA,PIN4 );
	Delay_Void500MS();
	LED_VoidLedON (GPIOA,PIN2 );
	LED_VoidLedON (GPIOA,PIN5 );
	Delay_Void500MS();
	LED_VoidLedON (GPIOA,PIN1 );
	LED_VoidLedON (GPIOA,PIN6 );
	Delay_Void500MS();
	LED_VoidLedON (GPIOA,PIN0 );
	LED_VoidLedON (GPIOA,PIN7 );
	Delay_Void500MS();
	/*Make the LEDs OFF*/
	LED_VoidLedOFF (GPIOA,PIN0 );
	LED_VoidLedOFF (GPIOA,PIN7 );
	Delay_Void500MS();
	LED_VoidLedOFF (GPIOA,PIN1 );
	LED_VoidLedOFF (GPIOA,PIN6 );
	Delay_Void500MS();
	LED_VoidLedOFF (GPIOA,PIN2 );
	LED_VoidLedOFF (GPIOA,PIN5 );
	Delay_Void500MS();
	LED_VoidLedOFF (GPIOA,PIN3 );
	LED_VoidLedOFF (GPIOA,PIN4 );
	Delay_Void500MS();
}
/*******************************function to do the third sequence*******************************/
void LED_VoidFlashLeds(void)
{
	/*make All the LEDs ON*/
	LED_VoidLedON (GPIOA,PIN0 );
	LED_VoidLedON (GPIOA,PIN1 );
	LED_VoidLedON (GPIOA,PIN2 );
	LED_VoidLedON (GPIOA,PIN3 );
	LED_VoidLedON (GPIOA,PIN4 );
	LED_VoidLedON (GPIOA,PIN5 );
	LED_VoidLedON (GPIOA,PIN6 );
	LED_VoidLedON (GPIOA,PIN7 );
	Delay_Void500MS();
	/*make All the LEDs OFF*/
	LED_VoidLedOFF (GPIOA,PIN0 );
	LED_VoidLedOFF (GPIOA,PIN1 );
	LED_VoidLedOFF (GPIOA,PIN2 );
	LED_VoidLedOFF (GPIOA,PIN3 );
	LED_VoidLedOFF (GPIOA,PIN4 );
	LED_VoidLedOFF (GPIOA,PIN5 );
	LED_VoidLedOFF (GPIOA,PIN6 );
	LED_VoidLedOFF (GPIOA,PIN7 );
	Delay_Void500MS();
}
