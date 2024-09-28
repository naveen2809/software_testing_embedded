CC=arm-none-eabi-gcc 
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0 -g -ffunction-sections -fdata-sections -fstack-usage -I Unity/src/ 
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft -T stm32_discovery.ld -Wl,-Map=gpio_test.map -Wl,--gc-sections

all: test_gpio_driver.elf

test_gpio_driver.o: test_gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^

Unity/src/unity.o: Unity/src/unity.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f4xx.o: stm32f4xx.c
	$(CC) $(CFLAGS) -o $@ $^

gpio_driver.o: gpio_driver.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o: stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

usart_driver.o: usart_driver.c
	$(CC) $(CFLAGS) -o $@ $^

common_utils.o: common_utils.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o: syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

sysmem.o: sysmem.c
	$(CC) $(CFLAGS) -o $@ $^		

test_gpio_driver.elf: test_gpio_driver.o Unity/src/unity.o stm32f4xx.o gpio_driver.o stm32_startup.o usart_driver.o common_utils.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.su *.elf *.map
	rm Unity/src/unity.o
