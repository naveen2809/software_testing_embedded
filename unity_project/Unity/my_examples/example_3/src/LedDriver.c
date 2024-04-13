#include <stdint.h>
#include "LedDriver.h"

static uint16_t *pLEDs;

void LedDriver_Init(uint16_t *address)
{
    pLEDs = address;
    *address = 0;
}

void LedDriver_TurnOn(int LedNum)
{
    *pLEDs = 1;
}

void LedDriver_TurnOff(int LedNum)
{
     *pLEDs = 0;
}