/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 8 August 2020
 **********************************************************************************************/

#ifndef  RCC_PRIVATE_H
#define  RCC_PRIVATE_H

/*Register Definitions*/
#define RCC_CR          *((u32 *)0x40021000) /*clock on processor*/  /*RCC_CR is a pointer to this address and you make a dereferanse to access this address*/
#define RCC_CFGR        *((u32 *)0x40021004) /*clock on processor*/
#define RCC_CIR         *((u32 *)0x40021008)
#define RCC_APB2RSTR    *((u32 *)0x4002100C)
#define RCC_APB1RSTR    *((u32 *)0x40021010)
#define RCC_AHBENR      *((u32 *)0x40021014) /*clock on peripheral*/
#define RCC_APB2ENR     *((u32 *)0x40021018) /*clock on peripheral*/
#define RCC_APB1ENR     *((u32 *)0x4002101C) /*clock on peripheral*/
#define RCC_BDCR        *((u32 *)0x40021020)
#define RCC_CSR         *((u32 *)0x40021024)

/*clock types*/
#define RCC_HSE_CRYSTAL       0x00
#define RCC_HSE_RC            0x01
#define RCC_HSI               0x02
#define RCC_PLL               0x03

/*clock type with the PLL*/
#define RCC_PLL_IN_HSI_DIV_2  0x00
#define RCC_PLL_IN_HSE_DIV_2  0x01
#define RCC_PLL_IN_HSE        0x02

/*PLL multiplication factor*/
#define PLL_input_clock_x2    0b0000
#define PLL_input_clock_x3    0b0001
#define PLL_input_clock_x4    0b0010
#define PLL_input_clock_x5    0b0011
#define PLL_input_clock_x6    0b0100
#define PLL_input_clock_x7    0b0101
#define PLL_input_clock_x8    0b0110
#define PLL_input_clock_x9    0b0111
#define PLL_input_clock_x10   0b1000
#define PLL_input_clock_x11   0b1001
#define PLL_input_clock_x12   0b1010
#define PLL_input_clock_x13   0b1011
#define PLL_input_clock_x14   0b1100
#define PLL_input_clock_x15   0b1101
#define PLL_input_clock_x16   0b1110
//#define PLL_input_clock_x16 0b1111

#endif
