#include <string.h>
#include "gpio_driver.h"
#include "Unity/src/unity.h"
#include "usart_driver.h"
#include "common_utils.h"

static struct GPIO_RegDef_t * pGPIO_Port;
extern struct USART_Handle_t Test_USART;

void setUp(void)
{
    
}

void tearDown(void)
{

}

void test_gpio_write_set_pin_0(void)
{
    memset((char *)pGPIO_Port,0,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)pGPIO_Port, 0, 1);
    TEST_ASSERT_EQUAL_UINT32(0x1,pGPIO_Port->ODR);
}

void test_gpio_write_reset_pin_0(void)
{
    memset((char *)pGPIO_Port,0xff,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)pGPIO_Port, 0, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE,pGPIO_Port->ODR);
}

void test_gpio_write_set_pin_15(void)
{
    //memset((char *)pGPIO_Port,0,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)pGPIO_Port, 15, 1);
    TEST_ASSERT_EQUAL_UINT32(0x8000,pGPIO_Port->ODR);
}

void test_gpio_write_reset_pin_15(void)
{
    //memset((char *)pGPIO_Port,0xff,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)pGPIO_Port, 15, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFF7FFF,pGPIO_Port->ODR);
}

void test_gpio_write_set_multiple_pins(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)pGPIO_Port, 0, 1);
    TEST_ASSERT_EQUAL_UINT32(0x1,pGPIO_Port->ODR);

    GPIOWritePin((uint32_t *)pGPIO_Port, 1, 1);
    TEST_ASSERT_EQUAL_UINT32(0x3,pGPIO_Port->ODR);


    GPIOWritePin((uint32_t *)pGPIO_Port, 15, 1);
    TEST_ASSERT_EQUAL_UINT32(0x8003,pGPIO_Port->ODR);

}

void test_gpio_write_reset_multiple_pins(void)
{
    memset((char *)pGPIO_Port,0xff,sizeof(struct GPIO_RegDef_t));
    GPIOWritePin((uint32_t *)pGPIO_Port, 0, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE,pGPIO_Port->ODR);

    GPIOWritePin((uint32_t *)pGPIO_Port, 4, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFEE,pGPIO_Port->ODR);

    GPIOWritePin((uint32_t *)pGPIO_Port, 6, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFAE,pGPIO_Port->ODR);

    GPIOWritePin((uint32_t *)pGPIO_Port, 9, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFDAE,pGPIO_Port->ODR);    

    GPIOWritePin((uint32_t *)pGPIO_Port, 15, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFF7DAE,pGPIO_Port->ODR);
}

void test_gpio_read_pin_0_high(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0x1;
    TEST_ASSERT_EQUAL_UINT8(0x1,GPIOReadPin((uint32_t *)pGPIO_Port, 0));   
}

void test_gpio_read_pin_0_low(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0xFFFFFFFEU;
    TEST_ASSERT_EQUAL_UINT8(0x0,GPIOReadPin((uint32_t *)pGPIO_Port, 0));   
}

void test_gpio_read_pin_15_high(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0x8000;
    TEST_ASSERT_EQUAL_UINT8(0x1,GPIOReadPin((uint32_t *)pGPIO_Port, 15));   
}

void test_gpio_read_pin_15_low(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0xFFFF7FFF;
    TEST_ASSERT_EQUAL_UINT8(0x0,GPIOReadPin((uint32_t *)pGPIO_Port, 15));   
}

void test_gpio_toggle_pin_0_low_to_high_1(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFFFFFFFE;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_0_low_to_high_2(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0x0;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0x1,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_0_high_to_low_1(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFFFFFFFF;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFE,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_0_high_to_low_2(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0x1;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 0);
    TEST_ASSERT_EQUAL_UINT32(0x0,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_15_low_to_high_1(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFFFF7FFF;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_15_low_to_high_2(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0x0;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0x8000,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_15_high_to_low_1(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFFFFFFFF;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0xFFFF7FFF,pGPIO_Port->ODR);
}

void test_gpio_toggle_pin_15_high_to_low_2(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0x8000;
    GPIOTogglePin((uint32_t *)pGPIO_Port, 15);
    TEST_ASSERT_EQUAL_UINT32(0x0,pGPIO_Port->ODR);
}

void test_gpio_write_port(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOWritePort((uint32_t *)pGPIO_Port,0xFFFFFFFF);
    TEST_ASSERT_EQUAL_UINT32(0xFFFFFFFF,pGPIO_Port->ODR);

    memset((char *)pGPIO_Port,0xFF,sizeof(struct GPIO_RegDef_t));
    GPIOWritePort((uint32_t *)pGPIO_Port,0x0);
    TEST_ASSERT_EQUAL_UINT32(0x0,pGPIO_Port->ODR); 

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFF00;
    GPIOWritePort((uint32_t *)pGPIO_Port,0xFF);
    TEST_ASSERT_EQUAL_UINT32(0xFF,pGPIO_Port->ODR);

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFF;
    GPIOWritePort((uint32_t *)pGPIO_Port,0xFF00);
    TEST_ASSERT_EQUAL_UINT32(0xFF00,pGPIO_Port->ODR); 
}

void test_gpio_read_idr(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0x00;
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIOReadIDR((uint32_t *)pGPIO_Port));

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0xFFFF;
    TEST_ASSERT_EQUAL_UINT32(0xFFFF,GPIOReadIDR((uint32_t *)pGPIO_Port));

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0xABCD;
    TEST_ASSERT_EQUAL_UINT32(0xABCD,GPIOReadIDR((uint32_t *)pGPIO_Port));

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->IDR = 0xFFFFABCD;
    TEST_ASSERT_EQUAL_UINT32(0xFFFFABCD,GPIOReadIDR((uint32_t *)pGPIO_Port));
}

void test_gpio_read_odr(void)
{
    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0x00;
    TEST_ASSERT_EQUAL_UINT32(0x0,GPIOReadODR((uint32_t *)pGPIO_Port));

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFFFF;
    TEST_ASSERT_EQUAL_UINT32(0xFFFF,GPIOReadODR((uint32_t *)pGPIO_Port));

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFEFE;
    TEST_ASSERT_EQUAL_UINT32(0xFEFE,GPIOReadODR((uint32_t *)pGPIO_Port));

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    pGPIO_Port->ODR = 0xFEFEFEFE;
    TEST_ASSERT_EQUAL_UINT32(0xFEFEFEFE,GPIOReadODR((uint32_t *)pGPIO_Port));
}

void test_gpio_set_mode_pin(uint8_t pin_num)
{
    uint32_t expected_value;

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)pGPIO_Port,pin_num, 0x00);
    expected_value = (0x00 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->MODER);

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)pGPIO_Port,pin_num, 0x01);
    expected_value = (0x01 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->MODER);

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)pGPIO_Port,pin_num, 0x02);
    expected_value = (0x02 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->MODER);       

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetMode((uint32_t *)pGPIO_Port,pin_num, 0x03);
    expected_value = (0x03 << 2*pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->MODER);
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
        memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
        GPIOSetAltFn((uint32_t *)pGPIO_Port,pin_num, j);
        expected_value = (j << 4*(pin_num%8));
        TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->AFR[reg_index]);
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

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetOutputType((uint32_t *)pGPIO_Port,pin_num, 0x0);
    expected_value = (0x0 << pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->OTYPER);

    memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
    GPIOSetOutputType((uint32_t *)pGPIO_Port,pin_num, 0x1);
    expected_value = (0x1 << pin_num);
    TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->OTYPER);
    
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
        memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
        GPIOSetOutputSpeed((uint32_t *)pGPIO_Port,pin_num, i);
        expected_value = (i << 2*pin_num);
        TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->OSPEEDR);
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
        memset((char *)pGPIO_Port,0x00,sizeof(struct GPIO_RegDef_t));
        GPIOSetPullUpDownConfig((uint32_t *)pGPIO_Port,pin_num, i);
        expected_value = (i << 2*pin_num);
        TEST_ASSERT_EQUAL_UINT32(expected_value,pGPIO_Port->PUPDR);
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
    //Configuring the UART
    configure_uart();

    //pGPIO_Port = malloc(sizeof(struct GPIO_RegDef_t));
    //pGPIO_Port = malloc(sizeof(struct GPIO_RegDef_t))
    pGPIO_Port = (struct GPIO_RegDef_t *) 0x40020C00;

    EnablePeriClk(GPIOD);
	GPIOSetMode(GPIOD, GPIO_PIN_15, GPIO_MODE_OUTPUT);
	//GPIOSetMode(GPIOD, GPIO_PIN_13, GPIO_MODE_OUTPUT);
	//GPIOSetMode(GPIOD, GPIO_PIN_14, GPIO_MODE_OUTPUT);
	//GPIOSetMode(GPIOD, GPIO_PIN_15, GPIO_MODE_OUTPUT);


    if(pGPIO_Port == NULL)
    {
        return -1;
    }
 
    UNITY_BEGIN();

    RUN_TEST(test_gpio_write_set_pin_15);
    RUN_TEST(test_gpio_write_reset_pin_15);

/*
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

*/

    UNITY_END();

    while(1)
    {

    }

    return 0;
}