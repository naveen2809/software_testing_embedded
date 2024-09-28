/*
 * common_utils.h
 *
 *  Created on: 24-Dec-2023
 *      Author: naveen
 */

#ifndef INC_COMMON_UTILS_H_
#define INC_COMMON_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx.h"
#include "gpio_driver.h"
#include "usart_driver.h"

#define UART_GPIO_PORT		GPIOC
#define UART_TX_PIN			GPIO_PIN_10
#define UART_RX_PIN			GPIO_PIN_11

void delay_us(uint32_t delay);
void configure_uart(void);
void UART_SendChar(uint8_t ch);

#endif /* INC_COMMON_UTILS_H_ */
