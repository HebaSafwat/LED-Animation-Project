/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 18 August 2020
 **********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include"LED_interface.h"

#include"LED_private.h"
#include"LED_config.h"
/*SEVEN*/
	//display(common_anodeOrCasode,number) to display the number 

/*function to make the LED ON*/
void LED_VoidLedON (u8 copy_PortNum , u8 copy_PinNum )
{
	/*told the DIO to make this pin in that port output pin and set it's value to be one*/
	MGPIO_voidSetPinDirection (copy_PortNum , copy_PinNum , GPIO_HIGH);
	MGPIO_voidSetPinValue (copy_PortNum , copy_PinNum , LED_ON);
}

/*function to make the LED OFF*/
void LED_VoidLedOFF (u8 copy_PortNum , u8 copy_PinNum )
{
	/*told the DIO to make this pin in that port output pin and set it's value to be zero*/
	MGPIO_voidSetPinDirection (copy_PortNum , copy_PinNum , GPIO_HIGH);
	MGPIO_voidSetPinValue (copy_PortNum , copy_PinNum , LED_OFF);
}

/*function to toggle the LED*/
void LED_VoidLedToggle (u8 copy_PortNum , u8 copy_PinNum )
{
	/*told the DIO to make this pin in that port output pin */
	MGPIO_voidSetPinDirection (copy_PortNum , copy_PinNum , LED_ON);
	/*set the pin value to be high*/
	MGPIO_voidSetPinValue (copy_PortNum , copy_PinNum , LED_OFF);
	/*delay*/
	u8 i;
	for(i=0;i<5000;i++){}
	/*set the pin value to be low*/
	MGPIO_voidSetPinValue (copy_PortNum , copy_PinNum , LED_ON);
}
