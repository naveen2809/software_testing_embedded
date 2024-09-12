#include <string.h>
#include "gpio_driver.h"
#include "Unity/src/unity.h"

static struct GPIO_RegDef_t GPIO_Port;

void setUp(void)
{
    
}

void tearDown(void)
{

}

void test_gpio_write_set_pin_0(void)
{
    memset((char *)&GPIO_Port,0,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)&GPIO_Port, 0, 1);
    TEST_ASSERT_EQUAL_UINT32(0x1,GPIO_Port.ODR);
}

void test_gpio_write_reset_pin_0(void)
{
    memset((char *)&GPIO_Port,0xff,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)&GPIO_Port, 0, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE,GPIO_Port.ODR);
}

void test_gpio_write_set_pin_15(void)
{
    memset((char *)&GPIO_Port,0,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)&GPIO_Port, 15, 1);
    TEST_ASSERT_EQUAL_UINT32(0x8000,GPIO_Port.ODR);
}

void test_gpio_write_reset_pin_15(void)
{
    memset((char *)&GPIO_Port,0xff,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)&GPIO_Port, 15, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFF7FFF,GPIO_Port.ODR);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gpio_write_set_pin_0);
    RUN_TEST(test_gpio_write_reset_pin_0);
    RUN_TEST(test_gpio_write_set_pin_15);
    RUN_TEST(test_gpio_write_reset_pin_15);

    return UNITY_END();
}