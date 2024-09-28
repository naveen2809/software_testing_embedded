#include <string.h>
#include "stm32f4xx.h"
#include "unity.h"

uint32_t NVICPriorityRegisters[21];

void setUp(void)
{
    
}

void tearDown(void)
{

}

void test_NVIC_SetPriority_Interrupt0_Priority0(void)
{
    NVICPriorityRegisters[0] = 0xFF;
    NVIC_SetPriority(NVICPriorityRegisters,0,0);
    TEST_ASSERT_EQUAL_UINT32(0,NVICPriorityRegisters[0]);
}

void test_NVIC_SetPriority_Interrupt0_Priority15(void)
{
    NVICPriorityRegisters[0] = 0xFFFFFFFF;
    NVIC_SetPriority(NVICPriorityRegisters,0,15);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFF0F,NVICPriorityRegisters[0]);
}

void test_NVIC_SetPriority_Interrupt0_Priority100(void)
{
    NVICPriorityRegisters[0] = 0x0A;
    NVIC_SetPriority(NVICPriorityRegisters,0,100);
    TEST_ASSERT_EQUAL_UINT32(100,NVICPriorityRegisters[0]);
}

void test_NVIC_SetPriority_Interrupt1_Priority25(void)
{
    NVICPriorityRegisters[0] = 0xFF00;
    NVIC_SetPriority(NVICPriorityRegisters,1,25);
    TEST_ASSERT_EQUAL_UINT32(0x1900,NVICPriorityRegisters[0]);
}

void test_NVIC_SetPriority_Interrupt2_Priority200(void)
{
    NVICPriorityRegisters[0] = 0xAA12FF00;
    NVIC_SetPriority(NVICPriorityRegisters,2,200);
    TEST_ASSERT_EQUAL_UINT32(0xAAC8FF00,NVICPriorityRegisters[0]);
}

void test_NVIC_SetPriority_Interrupt3_Priority64(void)
{
    NVICPriorityRegisters[0] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,3,64);
    TEST_ASSERT_EQUAL_UINT32(0x40AAFFCC,NVICPriorityRegisters[0]);
}

void test_NVIC_SetPriority_Interrupt4_Priority89(void)
{
    NVICPriorityRegisters[1] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,4,89);
    TEST_ASSERT_EQUAL_UINT32(0x12AAFF59,NVICPriorityRegisters[1]);
}

void test_NVIC_SetPriority_Interrupt79_Priority75(void)
{
    NVICPriorityRegisters[19] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,79,75);
    TEST_ASSERT_EQUAL_UINT32(0x4BAAFFCC,NVICPriorityRegisters[19]);
}

void test_NVIC_SetPriority_Interrupt80_Priority190(void)
{
    NVICPriorityRegisters[20] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,80,190);
    TEST_ASSERT_EQUAL_UINT32(0x12AAFFBE,NVICPriorityRegisters[20]);
}

/*****************************************************************************************************************/

void test_NVIC_GetPriority_Interrupt0_Priority0(void)
{
    uint8_t ret_priority;

    NVICPriorityRegisters[0] = 0xFF;
    NVIC_SetPriority(NVICPriorityRegisters,0,0);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,0);
    TEST_ASSERT_EQUAL_UINT8(0,ret_priority);
}

void test_NVIC_GetPriority_Interrupt0_Priority15(void)
{
    uint8_t ret_priority;

    NVICPriorityRegisters[0] = 0xFFFFFFFF;
    NVIC_SetPriority(NVICPriorityRegisters,0,15);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,0);
    TEST_ASSERT_EQUAL_UINT8(0x0F,ret_priority);
}

void test_NVIC_GetPriority_Interrupt0_Priority100(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[0] = 0x0A;
    NVIC_SetPriority(NVICPriorityRegisters,0,100);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,0);
    TEST_ASSERT_EQUAL_UINT8(100,ret_priority);
}

void test_NVIC_GetPriority_Interrupt1_Priority25(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[0] = 0xFF00;
    NVIC_SetPriority(NVICPriorityRegisters,1,25);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,1);
    TEST_ASSERT_EQUAL_UINT8(25,ret_priority);
}

void test_NVIC_GetPriority_Interrupt2_Priority200(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[0] = 0xAA12FF00;
    NVIC_SetPriority(NVICPriorityRegisters,2,200);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,2);
    TEST_ASSERT_EQUAL_UINT8(200,ret_priority);
}

void test_NVIC_GetPriority_Interrupt3_Priority64(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[0] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,3,64);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,3);
    TEST_ASSERT_EQUAL_UINT8(64,ret_priority);
}

void test_NVIC_GetPriority_Interrupt4_Priority89(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[1] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,4,89);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,4);
    TEST_ASSERT_EQUAL_UINT8(89,ret_priority);
}

void test_NVIC_GetPriority_Interrupt79_Priority75(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[19] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,79,75);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,79);
    TEST_ASSERT_EQUAL_UINT8(75,ret_priority);
}

void test_NVIC_GetPriority_Interrupt80_Priority190(void)
{
    uint8_t ret_priority;
    
    NVICPriorityRegisters[20] = 0x12AAFFCC;
    NVIC_SetPriority(NVICPriorityRegisters,80,190);
    ret_priority = NVIC_GetPriority(NVICPriorityRegisters,80);
    TEST_ASSERT_EQUAL_UINT8(190,ret_priority);
}

/****************************************************************************************************************************/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_NVIC_SetPriority_Interrupt0_Priority0);
    RUN_TEST(test_NVIC_SetPriority_Interrupt0_Priority15);
    RUN_TEST(test_NVIC_SetPriority_Interrupt0_Priority100);
    RUN_TEST(test_NVIC_SetPriority_Interrupt1_Priority25);
    RUN_TEST(test_NVIC_SetPriority_Interrupt2_Priority200);
    RUN_TEST(test_NVIC_SetPriority_Interrupt3_Priority64);
    RUN_TEST(test_NVIC_SetPriority_Interrupt4_Priority89);
    RUN_TEST(test_NVIC_SetPriority_Interrupt79_Priority75);
    RUN_TEST(test_NVIC_SetPriority_Interrupt80_Priority190);

    RUN_TEST(test_NVIC_GetPriority_Interrupt0_Priority0);
    RUN_TEST(test_NVIC_GetPriority_Interrupt0_Priority15);
    RUN_TEST(test_NVIC_GetPriority_Interrupt0_Priority100);
    RUN_TEST(test_NVIC_GetPriority_Interrupt1_Priority25);
    RUN_TEST(test_NVIC_GetPriority_Interrupt2_Priority200);
    RUN_TEST(test_NVIC_GetPriority_Interrupt3_Priority64);
    RUN_TEST(test_NVIC_GetPriority_Interrupt4_Priority89);
    RUN_TEST(test_NVIC_GetPriority_Interrupt79_Priority75);
    RUN_TEST(test_NVIC_GetPriority_Interrupt80_Priority190);

    return UNITY_END();
}