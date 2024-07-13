#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (2 * 1024) /*2KB of SRAM*/
// for sp reg
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

void main(void);

void Reset_Handler(void) __attribute__((weak));
void NMI_Handler(void) __attribute__((weak));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SW_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_Handler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI7_0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void AWU_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_CH7_Handler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1BRK_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1UP_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1TRG_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1CC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t Vector_Table[] __attribute__((section(".vector_table"))) = {
    0,
    0,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)&SysTick_Handler,
    0,
    (uint32_t)&SW_Handler,
    0,
    (uint32_t)&WWDG_Handler,
    (uint32_t)&PVD_Handler,
    (uint32_t)&FLASH_Handler,
    (uint32_t)&RCC_Handler,
    (uint32_t)&EXTI7_0_Handler,
    (uint32_t)&AWU_Handler,
    (uint32_t)&DMA1_CH1_Handler,
    (uint32_t)&DMA1_CH2_Handler,
    (uint32_t)&DMA1_CH3_Handler,
    (uint32_t)&DMA1_CH4_Handler,
    (uint32_t)&DMA1_CH5_Handler,
    (uint32_t)&DMA1_CH6_Handler,
    (uint32_t)&DMA1_CH7_Handler,
    (uint32_t)&ADC_Handler,
    (uint32_t)&I2C1_EV_Handler,
    (uint32_t)&I2C1_ER_Handler,
    (uint32_t)&USART1_Handler,
    (uint32_t)&SPI1_Handler,
    (uint32_t)&TIM1BRK_Handler,
    (uint32_t)&TIM1UP_Handler,
    (uint32_t)&TIM1TRG_Handler,
    (uint32_t)&TIM1CC_Handler,
    (uint32_t)&TIM2_Handler

};

void Reset_Handler(void)
{
    /**/

    /*copy data from flash to ram*/

    /*set .bss section to zero*/

    /*call main*/

    main();
    while (1)
    {
    };
}

void NMI_Handler(void)
{
    while (1)
    {
    };
}
void Default_Handler(void)
{
    while (1)
    {
    };
}
