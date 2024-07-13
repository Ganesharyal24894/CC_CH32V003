ENTRY(Reset_Handler)


MEMORY
{

    /* although the user code area starts from 0x08000000 but system maps it to 0x00000000 */
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 16K
	RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 2K

}


SECTIONS
{
    .text :
    {   
        *(.vector_table)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        _etext = . ; 
    }> FLASH AT> FLASH

    .data :
    {
        . = ALIGN(4);
        _sdata = . ;
        *(.data)
        . = ALIGN(4);
        _edata = . ;    
    }>RAM AT> FLASH

    .bss :
    {   
        . = ALIGN(4);
        _sbss = . ;
        *(.bss)
        . = ALIGN(4);
        _ebss = . ;
    } >RAM 


}