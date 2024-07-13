#include <stdint.h>

#define GPIOC 0x40011000
#define RCC 0x40021000

#define CFGLR_OFFSET 0x00
#define INDR_OFFSET 0x08
#define OUTDR_OFFSET 0x0C
#define BSHR_OFFSET 0x10
#define BCR_OFFSET 0x14
#define LCKR_OFFSET 0x18

#define APB2PCENR_OFFSET 0x18

int main(void)
{
    /*Lets blink LED on PC0*/

    // enable C port
    *((uint32_t *)(RCC + APB2PCENR_OFFSET)) |= (1 << 4);

    // configure PC0 as an output
    *((uint32_t *)(GPIOC + CFGLR_OFFSET)) |= (3 << 0);  // configuring it as an output at 30 MHz
    *((uint32_t *)(GPIOC + CFGLR_OFFSET)) &= ~(3 << 2); // configuring it as an output in push/pull mode

    while (1)
    {
        *((uint32_t *)(GPIOC + OUTDR_OFFSET)) ^= (1 << 0);
        // toggle the output pin to blink

        for (int i = 0; i < 400000; i++)
        {
            asm volatile("nop");
        }
    }

    return 0;
}
