#include "unity_fixture.h"
#include "LedDriver.h"

static uint16_t virtualLeds;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
    virtualLeds = 0xFFFF;
    LedDriver_Init(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{

}

TEST(LedDriver,Test_LedDriver_Init)
{
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOnLEDOne)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOffLEDOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}