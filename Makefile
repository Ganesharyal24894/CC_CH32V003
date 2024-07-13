
CC = riscv64-unknown-elf-gcc

CFLAGS = -march=rv32ec -mabi=ilp32e -Wall

LDFLAGS = -march=rv32ec -mabi=ilp32e -nostdlib 

all: final.bin

# final.elf : main.c ch32v003_startup.c ch32v003_link.ld 
# 	$(CC) -o $@ main.c ch32v003_startup.c -g -Os -flto -ffunction-sections -fdata-sections -fmessage-length=0 -msmall-data-limit=8 -march=rv32ec -mabi=ilp32e -static-libgcc -nostdlib -I. -Wall $(LDFLAGS)

final.bin : final.elf
	riscv64-unknown-elf-objcopy -O binary $^ $@

final.elf : main.o ch32v003_startup.o
	$(CC) $(LDFLAGS) -T ch32v003_link.ld   *.o -o final.elf -Wl,-Map=final.map


#for seeing the sections
sections : main.o
	riscv64-unknown-elf-objdump -h $^

%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@ 


clean:
	rm *.o *.bin *.elf *.out *.map || true

