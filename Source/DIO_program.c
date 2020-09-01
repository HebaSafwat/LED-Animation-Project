/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 13 August 2020
 **********************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_voidSetPinDirection (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
	case GPIOA:
		if(copy_u8Pin <=7)                  /*for low pins -write in CRL-*/
		{
			/*if you have a logical operation don't overwrite on the register, clear it at first*/
			GPIOA_CRL &= ~((0b1111)<<(copy_u8Pin*4));
			GPIOA_CRL |= ((copy_u8Mode)<<(copy_u8Pin*4));
		}
		else if(copy_u8Pin <=15 )           /*for high pins -write in CRH-*/
		{
			copy_u8Pin = copy_u8Pin - 8;
			GPIOA_CRH &= ~((0b1111)<<(copy_u8Pin*4));
			GPIOA_CRH |= ((copy_u8Mode)<<(copy_u8Pin*4));			
		}
		break;
	case GPIOB:
		if(copy_u8Pin <=7)                  /*for low pins -write in CRL-*/
		{
			GPIOB_CRL &= ~((0b1111)<<(copy_u8Pin*4));
			GPIOB_CRL |= ((copy_u8Mode)<<(copy_u8Pin*4));
		}
		else if(copy_u8Pin <=15)           /*for high pins -write in CRH-*/
		{
			copy_u8Pin = copy_u8Pin - 8;
			GPIOB_CRH &= ~((0b1111)<<(copy_u8Pin*4));
			GPIOB_CRH |= ((copy_u8Mode)<<(copy_u8Pin*4));			
		}
		break;
	case GPIOC:
		if(copy_u8Pin <=7)                  /*for low pins -write in CRL-*/
		{
			GPIOC_CRL &= ~((0b1111)<<(copy_u8Pin*4));
			GPIOC_CRL |= ((copy_u8Mode)<<(copy_u8Pin*4));
		}
		else if(copy_u8Pin <=15)           /*for high pins -write in CRH-*/
		{
			copy_u8Pin = copy_u8Pin - 8;
			GPIOC_CRH &= ~((0b1111)<<(copy_u8Pin*4));
			GPIOC_CRH |= ((copy_u8Mode)<<(copy_u8Pin*4));			
		}
		break;
	}
}

void MGPIO_voidSetPinValue (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value)
{
	switch(copy_u8Port)
	{
	case GPIOA:
		if(copy_u8Value==GPIO_HIGH)
		{
			SET_BIT(GPIOA_ODR , copy_u8Pin);
		}
		else if(copy_u8Value==GPIO_LOW)
		{
			CLEAR_BIT(GPIOA_ODR , copy_u8Pin);
		}
		break;
	case GPIOB:
		if(copy_u8Value==GPIO_HIGH)
		{
			SET_BIT(GPIOB_ODR , copy_u8Pin);
		}
		else if(copy_u8Value==GPIO_LOW)
		{
			CLEAR_BIT(GPIOB_ODR , copy_u8Pin);
		}
		break;
	case GPIOC:
		if(copy_u8Value==GPIO_HIGH)
		{
			SET_BIT(GPIOC_ODR , copy_u8Pin);
		}
		else if(copy_u8Value==GPIO_LOW)
		{
			CLEAR_BIT(GPIOC_ODR , copy_u8Pin);
		}
		break;
	}
}

u8 MGPIO_voidGetPinValue (u8 copy_u8Port , u8 copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT(GPIOA_IDR,copy_u8Pin);
		break;
	case GPIOB:
		LOC_u8Result = GET_BIT(GPIOB_IDR,copy_u8Pin);
		break;
	case GPIOC:
		LOC_u8Result = GET_BIT(GPIOC_IDR,copy_u8Pin);
		break;
	}
	return LOC_u8Result;
}

void MGPIO_voidResetPort(u8 copy_u8Port)
{
	switch(copy_u8Port)
	{
	case GPIOA:
		GPIOA_ODR = RESET_VALUE ;
		break;
	case GPIOB:
		GPIOB_ODR = RESET_VALUE ;
		break;
	case GPIOC:
		GPIOC_ODR = RESET_VALUE ;
		break;
	}
}

void MGPIO_SetPortValue(u8 copy_u8Port , u32 copy_u8Value)
{
	switch(copy_u8Port)
	{
	case GPIOA:
		GPIOA_ODR = copy_u8Value ;
		break;
	case GPIOB:
		GPIOB_ODR = copy_u8Value ;
		break;
	case GPIOC:
		GPIOC_ODR = copy_u8Value ;
		break;
	}
}

