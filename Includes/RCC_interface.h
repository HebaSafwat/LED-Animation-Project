/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 8 August 2020
 **********************************************************************************************/

#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H


#define RCC_AHB  0x00
#define RCC_APB1 0x01
#define RCC_APB2 0x02

/********************************************************************************************
 *                             functions prototype
 *******************************************************************************************/

/*function  to enable the clock of the system*/
void RCC_voidInitSysClock(void);
/*enable the clock for a peripheral*/
void RCC_voidEnableClock(u8 copy_u8BusId,u8 copy_u8perId);
/*disable the clock for a peripheral*/
void RCC_voidDisableClock(u8 copy_u8BusId,u8 copy_u8perId);

#endif
