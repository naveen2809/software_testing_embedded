#include <string.h>
#include "my_module.h"
#include "unity.h"

#define LEN 20
uint8_t byte_array[LEN];
uint8_t byte_array_expected[LEN];

void setUp(void)
{
    //Setting the byte array to values other than expected
    memset((char *)byte_array,0xdd,LEN);
}

void tearDown(void)
{
    
}

void test_write_byte_array_type_zero(void)
{
    //Expected value for the byte array
    memset((char *)byte_array_expected,0xcc,LEN);

    TEST_ASSERT_EQUAL(0, write_byte_array(0, byte_array, LEN));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(byte_array_expected,byte_array,LEN);
}

void test_write_byte_array_type_positive(void)
{
    //Expected value for the byte array
    memset((char *)byte_array_expected,0xaa,LEN);

    TEST_ASSERT_EQUAL(0, write_byte_array(1, byte_array, LEN));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(byte_array_expected,byte_array,LEN);
}

void test_write_byte_array_type_negative(void)
{
    //Expected value for the byte array
    memset((char *)byte_array_expected,0xbb,LEN);

    TEST_ASSERT_EQUAL(0, write_byte_array(-1, byte_array, LEN));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(byte_array_expected,byte_array,LEN);
}

void test_write_byte_array_len_zero(void)
{
    //Expected value for the byte array
    memset((char *)byte_array_expected,0xdd,LEN);

    TEST_ASSERT_EQUAL(-1, write_byte_array(0, byte_array, 0));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(byte_array_expected,byte_array,LEN);
}

void test_write_byte_array_len_negative(void)
{
    //Expected value for the byte array
    memset((char *)byte_array_expected,0xdd,LEN);

    TEST_ASSERT_EQUAL(-1, write_byte_array(1, byte_array, -1));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(byte_array_expected,byte_array,LEN);
}

void test_write_byte_array_array_bounds(void)
{
    //Expected value for the byte array
    memset((char *)byte_array_expected,0xcc,LEN);

    TEST_ASSERT_EQUAL(0, write_byte_array(0, &byte_array[2], LEN-4));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(&byte_array_expected[2],&byte_array[2],LEN-4);
    TEST_ASSERT_EQUAL_UINT8(0xdd,byte_array[0]);
    TEST_ASSERT_EQUAL_UINT8(0xdd,byte_array[1]);
    TEST_ASSERT_EQUAL_UINT8(0xdd,byte_array[LEN-2]);
    TEST_ASSERT_EQUAL_UINT8(0xdd,byte_array[LEN-1]);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_write_byte_array_type_zero);
    RUN_TEST(test_write_byte_array_type_positive);
    RUN_TEST(test_write_byte_array_type_negative);
    RUN_TEST(test_write_byte_array_len_zero);
    RUN_TEST(test_write_byte_array_len_negative);
    RUN_TEST(test_write_byte_array_array_bounds);

    return UNITY_END();
}
