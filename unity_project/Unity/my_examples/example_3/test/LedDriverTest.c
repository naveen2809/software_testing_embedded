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
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x0080,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOnLEDAlreadyTunedOn)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x0080,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOffLEDOne)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOffLEDAlreadyTurnedOff)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOff(8);
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOnMultipleLEDs)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);
    TEST_ASSERT_EQUAL_HEX16(0x180,virtualLeds);
}

TEST(LedDriver,Test_LedDriver_TurnOffSingleAfterTurnOnMultipleLEDs)
{
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(10);
    LedDriver_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16(0x0280,virtualLeds);
}