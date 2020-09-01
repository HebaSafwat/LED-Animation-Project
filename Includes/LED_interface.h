/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 18 August 2020
 **********************************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/**************************************************
 *                            functions prototypes
 *                            *****************************************************************/
/*function to make the LED ON*/
void LED_VoidLedON (u8 copy_PortNum , u8 copy_PinNum );
/*function to make the LED OFF*/
void LED_VoidLedOFF (u8 copy_PortNum , u8 copy_PinNum );
/*function to toggle the LED*/
void LED_VoidLedToggle (u8 copy_PortNum , u8 copy_PinNum);


#endif
