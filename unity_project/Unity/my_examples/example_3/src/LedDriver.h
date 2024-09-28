#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>

void LedDriver_Init(uint16_t *address);
void LedDriver_TurnOn(int LedNum);
void LedDriver_TurnOff(int LedNum);

#endif