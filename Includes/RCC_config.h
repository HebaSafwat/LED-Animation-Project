/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 8 August 2020
 **********************************************************************************************/

#ifndef  RCC_CONFIG_H
#define  RCC_CONFIG_H


/*============================================================================================*/
/*Options : RCC_HSE_CRYSTAL
 *          RCC_HSE_RC
 *          RCC_HSI
 *          RCC_PLL*/
#define  RCC_CLOCK_TYPE RCC_HSI
/*============================================================================================*/
/*Note: select value for this parameter only if you choice the input clock parameter as PLL*/
/*Options : RCC_PLL_IN_HSI_DIV_2
 *          RCC_PLL_IN_HSE_DIV_2
 *          RCC_PLL_IN_HSE*/
#if(RCC_CLOCK_TYPE == RCC_PLL)
#define RCC_PLL_INPUT RCC_PLL_IN_HSE_DIV_2
    #if (RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2)
        #define PLL_EXTERNAL_TYPE RCC_HSE_CRYSTAL        /*(RCC_HSE_CRYSTAL) or(RCC_HSE_RC) */
    #elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE)
        #define PLL_EXTERNAL_TYPE RCC_HSE_CRYSTAL        /*(RCC_HSE_CRYSTAL) or(RCC_HSE_RC) */
#endif
/*============================================================================================*/
/*Note: select value for this parameter only if you choice the input clock parameter as PLL*/
/*Options: PLL_input_clock_x2
 *         PLL_input_clock_x3
 *         PLL_input_clock_x4
 *         PLL_input_clock_x5
 *         PLL_input_clock_x6
 *         PLL_input_clock_x7
 *         PLL_input_clock_x8
 *         PLL_input_clock_x9
 *         PLL_input_clock_x10
 *         PLL_input_clock_x11
 *         PLL_input_clock_x12
 *         PLL_input_clock_x13
 *         PLL_input_clock_x14
 *         PLL_input_clock_x15
 *         PLL_input_clock_x16*/
#if(RCC_CLOCK_TYPE == RCC_PLL)
#define RCC_PLL_MUL_VAL PLL_input_clock_x4
#endif
/*============================================================================================*/
#endif

#endif
