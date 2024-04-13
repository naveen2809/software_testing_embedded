#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver,Test_LedDriver_Init);
    RUN_TEST_CASE(LedDriver,Test_LedDriver_TurnOnLEDOne);
    RUN_TEST_CASE(LedDriver,Test_LedDriver_TurnOffLEDOne);
    RUN_TEST_CASE(LedDriver,Test_LedDriver_TurnOnMultipleLEDs);
}