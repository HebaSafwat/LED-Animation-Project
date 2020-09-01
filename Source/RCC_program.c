/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 8 August 2020
 **********************************************************************************************/
/*libraries*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
/*interface files of lower level*/
/*own driver files*/
#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"

/********************************************************************************************
 *                             functions Difinitions
 *******************************************************************************************/

/*function  to enable the clock of the system*/
void RCC_voidInitSysClock(void)
{
    #if(RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)
	    RCC_CR   = 0x00010000;                    /*enable HSE with no bypass*/
	    RCC_CFGR = 0x00000001;
    #elif(RCC_CLOCK_TYPE == RCC_HSE_RC)
	    RCC_CR   = 0x00050000;                    /*enable HSE_RC with bypass*/
	    RCC_CFGR = 0x00000001;
    #elif(RCC_CLOCK_TYPE == RCC_HSI)
	    RCC_CR   = 0x00000081;                   /*enable HSI*/
	    RCC_CFGR = 0x00000000;


    #elif(RCC_CLOCK_TYPE == RCC_PLL)
        #if(RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2)
	       /*disable the PLL to SET the Multiblication value*/
	       RCC_CR = 0x00000000;
	       /*PLL selected as system clock*/
           RCC_CFGR = (RCC_PLL_MUL_VAL<<18)| 0x00000002 ;
           /*enable the PLL and the HSI and the PLL and the Trimming with default value*/
           RCC_CR = 0x01000081;

        #elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2)
              #if(PLL_EXTERNAL_TYPE == RCC_HSE_CRYSTAL)
                  /*disable the PLL to write the Multiblication value*/
                  RCC_CR = 0x00000000;
                  /*PLL selected as system clock with External clock /2*/
                  RCC_CFGR = (RCC_PLL_MUL_VAL<<18)|0x00030002;
                  /*enable the PLL and the HSE oscillator*/
                  RCC_CR = 0x01010000;
              #elif(PLL_EXTERNAL_TYPE == RCC_HSE_RC)
                  /*disable the PLL to write the Multiblication value*/
                  RCC_CR = 0x00000000;
                  /*PLL selected as system clock with External clock /2*/
                  RCC_CFGR = (RCC_PLL_MUL_VAL<<18)|0x00030002;
                  /*enable the PLL and the HSE RC*/
                  RCC_CR = 0x01050000;
              #endif

        #elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE)
             #if(PLL_EXTERNAL_TYPE == RCC_HSE_CRYSTAL)
                 /*disable the PLL to write the Multiblication value*/
                 RCC_CR = 0x00000000;
                 /*PLL selected as system clock with External clock */
                 RCC_CFGR = (RCC_PLL_MUL_VAL<<18)|0x00010002;
                 /*enable the PLL and the HSE oscillator*/
                 RCC_CR = 0x01010000;
             #elif(PLL_EXTERNAL_TYPE == RCC_HSE_RC)
                 /*disable the PLL to write the Multiblication value*/
                 RCC_CR = 0x00000000;
                 /*PLL selected as system clock with External clock*/
                 RCC_CFGR = (RCC_PLL_MUL_VAL<<18)|0x00010002;
                 /*enable the PLL and the HSE RC*/
                 RCC_CR = 0x01050000;
             #endif
        #endif
    #else
        #error("you choose wrong clock type")
    #endif
}

/*enable the clock for a peripheral*/
void RCC_voidEnableClock(u8 copy_u8BusId,u8 copy_u8perId)
{
	/*input validation*/
	if(copy_u8perId <= 31)
	{
		switch(copy_u8BusId)
		{
		case RCC_AHB  : SET_BIT(RCC_AHBENR  , copy_u8perId);   break;
		case RCC_APB1 : SET_BIT(RCC_APB1ENR , copy_u8perId);   break;
		case RCC_APB2 : SET_BIT(RCC_APB2ENR , copy_u8perId);   break;	
		}
	}
	else
	{
		/*Return error*/
	}
}
/*disnable the clock for a peripheral*/
void RCC_voidDisableClock(u8 copy_u8BusId,u8 copy_u8perId)
{
	/*input validation*/
	if(copy_u8perId <= 31)
	{
		switch(copy_u8BusId)
		{
		case RCC_AHB  : CLEAR_BIT(RCC_AHBENR  , copy_u8perId);   break;
		case RCC_APB1 : CLEAR_BIT(RCC_APB1ENR , copy_u8perId);   break;
		case RCC_APB2 : CLEAR_BIT(RCC_APB2ENR , copy_u8perId);   break;
		}
	}
	else
	{
		/*Return error*/
	}
}
