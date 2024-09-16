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

void test_gpio_write_set_multiple_pins(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)&GPIO_Port, 0, 1);
    TEST_ASSERT_EQUAL_UINT32(0x1,GPIO_Port.ODR);

    GPIOWritePin((uint32_t *)&GPIO_Port, 1, 1);
    TEST_ASSERT_EQUAL_UINT32(0x3,GPIO_Port.ODR);


    GPIOWritePin((uint32_t *)&GPIO_Port, 15, 1);
    TEST_ASSERT_EQUAL_UINT32(0x8003,GPIO_Port.ODR);

}

void test_gpio_write_reset_multiple_pins(void)
{
    memset((char *)&GPIO_Port,0xff,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)&GPIO_Port, 0, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE,GPIO_Port.ODR);

    GPIOWritePin((uint32_t *)&GPIO_Port, 4, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFEE,GPIO_Port.ODR);

    GPIOWritePin((uint32_t *)&GPIO_Port, 6, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFAE,GPIO_Port.ODR);

    GPIOWritePin((uint32_t *)&GPIO_Port, 9, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFDAE,GPIO_Port.ODR);    

    GPIOWritePin((uint32_t *)&GPIO_Port, 15, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFF7DAE,GPIO_Port.ODR);
}

void test_gpio_read_pin_0_high(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0x1;
    TEST_ASSERT_EQUAL_UINT8(0x1,GPIOReadPin((uint32_t *)&GPIO_Port, 0));   
}

void test_gpio_read_pin_0_low(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0xFFFFFFFEU;
    TEST_ASSERT_EQUAL_UINT8(0x0,GPIOReadPin((uint32_t *)&GPIO_Port, 0));   
}

void test_gpio_read_pin_15_high(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0x8000;
    TEST_ASSERT_EQUAL_UINT8(0x1,GPIOReadPin((uint32_t *)&GPIO_Port, 15));   
}

void test_gpio_read_pin_15_low(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0xFFFF7FFF;
    TEST_ASSERT_EQUAL_UINT8(0x0,GPIOReadPin((uint32_t *)&GPIO_Port, 15));   
}

void test_gpio_toggle_pin_0_low_to_high_1(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFFFFFFFE;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_0_low_to_high_2(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0x0;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0x1,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_0_high_to_low_1(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFFFFFFFF;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_0_high_to_low_2(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0x1;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_15_low_to_high_1(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFFFF7FFF;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_15_low_to_high_2(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0x0;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0x8000,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_15_high_to_low_1(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFFFFFFFF;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0xFFFF7FFF,GPIO_Port.ODR);
}

void test_gpio_toggle_pin_15_high_to_low_2(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0x8000;
    GPIOTogglePin((uint32_t *)&GPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIO_Port.ODR);
}

void test_gpio_write_port(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOWritePort((uint32_t *)&GPIO_Port,0xFFFFFFFF);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF,GPIO_Port.ODR);

    memset((char *)&GPIO_Port,0xFF,sizeof(struct GPIO_RegDef_t));
    GPIOWritePort((uint32_t *)&GPIO_Port,0x0);
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIO_Port.ODR); 

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFF00;
    GPIOWritePort((uint32_t *)&GPIO_Port,0xFF);
    TEST_ASSERT_EQUAL_UINT32(0xFF,GPIO_Port.ODR);

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFF;
    GPIOWritePort((uint32_t *)&GPIO_Port,0xFF00);
    TEST_ASSERT_EQUAL_UINT32(0xFF00,GPIO_Port.ODR); 
}

void test_gpio_read_idr(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0x00;
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIOReadIDR((uint32_t *)&GPIO_Port));

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0xFFFF;
    TEST_ASSERT_EQUAL_UINT32(0xFFFF,GPIOReadIDR((uint32_t *)&GPIO_Port));

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0xABCD;
    TEST_ASSERT_EQUAL_UINT32(0xABCD,GPIOReadIDR((uint32_t *)&GPIO_Port));

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.IDR = 0xFFFFABCD;
    TEST_ASSERT_EQUAL_UINT32(0xFFFFABCD,GPIOReadIDR((uint32_t *)&GPIO_Port));
}

void test_gpio_read_odr(void)
{
    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0x00;
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIOReadODR((uint32_t *)&GPIO_Port));

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFFFF;
    TEST_ASSERT_EQUAL_UINT32(0xFFFF,GPIOReadODR((uint32_t *)&GPIO_Port));

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFEFE;
    TEST_ASSERT_EQUAL_UINT32(0xFEFE,GPIOReadODR((uint32_t *)&GPIO_Port));

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIO_Port.ODR = 0xFEFEFEFE;
    TEST_ASSERT_EQUAL_UINT32(0xFEFEFEFE,GPIOReadODR((uint32_t *)&GPIO_Port));
}

void test_gpio_set_mode_pin(uint8_t pin_num)
{
    uint32_t expected_value;

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)&GPIO_Port,pin_num, 0x00);
    expected_value = (0x00 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.MODER);

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)&GPIO_Port,pin_num, 0x01);
    expected_value = (0x01 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.MODER);

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)&GPIO_Port,pin_num, 0x02);
    expected_value = (0x02 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.MODER);       

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)&GPIO_Port,pin_num, 0x03);
    expected_value = (0x03 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.MODER);
}

void test_gpio_set_mode_all_pins(void)
{
    for(uint8_t i=0; i<16;i++)
    {
        test_gpio_set_mode_pin(i);
    }
}

void test_gpio_set_altfn_pin(uint8_t pin_num)
{
    uint32_t expected_value;
    uint8_t reg_index, j;

    if(pin_num>=0 && pin_num<=7)
    {
        reg_index = 0;
    }
    else if(pin_num>=8 && pin_num<=15)
    {
        reg_index = 1;
    }

    for(j=0;j<16;j++)
    {
        memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
        GPIOSetAltFn((uint32_t *)&GPIO_Port,pin_num, j);
        expected_value = (j << 4*(pin_num%8));
        TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.AFR[reg_index]);
    }   
}

void test_gpio_set_altfn_all_pins(void)
{
    for(int i=0;i<16;i++)
    {
        test_gpio_set_altfn_pin(i);
    }
}

void test_gpio_set_optype_pin(uint8_t pin_num)
{
    uint32_t expected_value;

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetOutputType((uint32_t *)&GPIO_Port,pin_num, 0x0);
    expected_value = (0x0 << pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.OTYPER);

    memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetOutputType((uint32_t *)&GPIO_Port,pin_num, 0x1);
    expected_value = (0x1 << pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.OTYPER);
    
}

void test_gpio_set_optype_all_pins(void)
{
    for(int i=0;i<16;i++)
    {
        test_gpio_set_optype_pin(i);
    }
}

void test_gpio_set_opspeed_pin(uint8_t pin_num)
{
    uint32_t expected_value, i;

    for(i=0;i<4;i++)
    {
        memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
        GPIOSetOutputSpeed((uint32_t *)&GPIO_Port,pin_num, i);
        expected_value = (i << 2*pin_num);
        TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.OSPEEDR);
    }

}

void test_gpio_set_opspeed_all_pins(void)
{
    for(int i=0;i<16;i++)
    {
        test_gpio_set_opspeed_pin(i);
    }
}

void test_gpio_set_pupd_pin(uint8_t pin_num)
{
    uint32_t expected_value, i;

    for(i=0;i<4;i++)
    {
        memset((char *)&GPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
        GPIOSetPullUpDownConfig((uint32_t *)&GPIO_Port,pin_num, i);
        expected_value = (i << 2*pin_num);
        TEST_ASSERT_EQUAL_UINT32(expected_value,GPIO_Port.PUPDR);
    }    
}

void test_gpio_set_pupd_all_pins(void)
{
    for(int i=0;i<16;i++)
    {
        test_gpio_set_pupd_pin(i);
    }
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gpio_write_set_pin_0);
    RUN_TEST(test_gpio_write_reset_pin_0);
    RUN_TEST(test_gpio_write_set_pin_15);
    RUN_TEST(test_gpio_write_reset_pin_15);

    RUN_TEST(test_gpio_write_set_multiple_pins);
    RUN_TEST(test_gpio_write_reset_multiple_pins);

    RUN_TEST(test_gpio_read_pin_0_high);
    RUN_TEST(test_gpio_read_pin_0_low);
    RUN_TEST(test_gpio_read_pin_15_high);
    RUN_TEST(test_gpio_read_pin_15_low);
    
    RUN_TEST(test_gpio_toggle_pin_0_low_to_high_1);
    RUN_TEST(test_gpio_toggle_pin_0_low_to_high_2);
    RUN_TEST(test_gpio_toggle_pin_0_high_to_low_1);
    RUN_TEST(test_gpio_toggle_pin_0_high_to_low_2);
    RUN_TEST(test_gpio_toggle_pin_15_low_to_high_1);
    RUN_TEST(test_gpio_toggle_pin_15_low_to_high_2);
    RUN_TEST(test_gpio_toggle_pin_15_high_to_low_1);
    RUN_TEST(test_gpio_toggle_pin_15_high_to_low_2);

    RUN_TEST(test_gpio_write_port);

    RUN_TEST(test_gpio_read_idr);

    RUN_TEST(test_gpio_read_odr);

    RUN_TEST(test_gpio_set_mode_all_pins);

    RUN_TEST(test_gpio_set_altfn_all_pins);

    RUN_TEST(test_gpio_set_optype_all_pins);

    RUN_TEST(test_gpio_set_opspeed_all_pins);

    RUN_TEST(test_gpio_set_pupd_all_pins);   

    return UNITY_END();
}