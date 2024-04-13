#include "unity_fixture.h"
#include "LedDriver.h"


TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{

}

TEST_TEAR_DOWN(LedDriver)
{

}

TEST(LedDriver,Test_LedDriver_Init)
{
    uint16_t virtualLeds;
 
    virtualLeds = 0xFFFF;
    LedDriver_Init(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOnLEDOne)
{
    uint16_t virtualLeds;

    LedDriver_Init(&virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOffLEDOne)
{
    uint16_t virtualLeds;

    LedDriver_Init(&virtualLeds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}