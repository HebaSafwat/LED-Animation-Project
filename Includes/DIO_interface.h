/**********************************************************************************************
 * Auther : Heba Safwat
 * Version: V01
 * date   : 13 August 2020
 **********************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define GPIOA            0x00
#define GPIOB            0x01
#define GPIOC            0x02

#define GPIO_HIGH        0x01
#define GPIO_LOW         0x00

#define PIN0             0x00
#define PIN1             0x01
#define PIN2             0x02
#define PIN3             0x03
#define PIN4             0x04
#define PIN5             0x05
#define PIN6             0x06
#define PIN7             0x07
#define PIN8             0x08
#define PIN9             0x09
#define PIN10            0x0A
#define PIN11            0x0B
#define PIN12            0x0C
#define PIN13            0x0D
#define PIN14            0xE
#define PIN15            0x0F



#define INPUT_ANALOG              0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULL_UP_DOWN        0b1000

#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111



void MGPIO_voidSetPinDirection (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode);

void MGPIO_voidResetPort(u8 copy_u8Port);

void MGPIO_SetPortValue(u8 copy_u8Port , u32 copy_u8Value);

void MGPIO_voidSetPinValue (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value);

u8 MGPIO_voidGetPinValue (u8 copy_u8Port , u8 copy_u8Pin);

void MGPIO_voidLockPin (u8 copy_u8Port , u8 copy_u8Pin);

#endif
