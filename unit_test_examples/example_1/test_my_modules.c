#include <string.h>
#include "my_module_add.h"
#include "my_module_mul.h"
#include "unity.h"

void test_add_num_zeros(void)
{
    TEST_ASSERT_EQUAL(0, add_num(0,0));
}

void test_add_num_positive_integers(void)
{
    TEST_ASSERT_EQUAL(1, add_num(1,0));
    TEST_ASSERT_EQUAL(1, add_num(0,1));
    TEST_ASSERT_EQUAL(2, add_num(1,1));
    TEST_ASSERT_EQUAL(10, add_num(5,5));
}

void test_add_num_negative_integers(void)
{
    TEST_ASSERT_EQUAL(-1, add_num(-1,0));
    TEST_ASSERT_EQUAL(-1, add_num(0,-1));
    TEST_ASSERT_EQUAL(-2, add_num(-1,-1));
    TEST_ASSERT_EQUAL(-10, add_num(-5,-5));
}

void test_add_num_mixed_integers(void)
{
    TEST_ASSERT_EQUAL(0, add_num(-1,1));
    TEST_ASSERT_EQUAL(0, add_num(1,-1));
    TEST_ASSERT_EQUAL(2, add_num(8,-6));
    TEST_ASSERT_EQUAL(-20, add_num(-15,-5));
    TEST_ASSERT_EQUAL(-10, add_num(-1.0,12.5));
}

void test_mul_num_mixed_integers(void)
{
    TEST_ASSERT_EQUAL(0, mul_num(0,0));
    TEST_ASSERT_EQUAL(0, mul_num(1,0));
    TEST_ASSERT_EQUAL(0, mul_num(0,1));
    TEST_ASSERT_EQUAL(1, mul_num(1,1));
    TEST_ASSERT_EQUAL(-1, mul_num(-1,1));
    TEST_ASSERT_EQUAL(-1, mul_num(1,-1));
    TEST_ASSERT_EQUAL(1, mul_num(-1,-1));
}

void test_add10(void)
{
    TEST_ASSERT_EQUAL(10, add10(0));
    TEST_ASSERT_EQUAL(11, add10(1));
    TEST_ASSERT_EQUAL(12, add10(2));
    TEST_ASSERT_EQUAL(0, add10(-10));
    TEST_ASSERT_EQUAL(-10, add10(-20));
    TEST_ASSERT_EQUAL(8, add10(-2));
}

void test_check_even(void)
{
    //Check for even numbers
    TEST_ASSERT_EQUAL(0,check_even(0));
    TEST_ASSERT_EQUAL(0,check_even(2));
    TEST_ASSERT_EQUAL(0,check_even(4));
    TEST_ASSERT_EQUAL(0,check_even(6));
    TEST_ASSERT_EQUAL(0,check_even(8));
    TEST_ASSERT_EQUAL(0,check_even(10));
    TEST_ASSERT_EQUAL(0,check_even(-2));
    TEST_ASSERT_EQUAL(0,check_even(-4));

    //Check for odd numbers
    TEST_ASSERT_EQUAL(-1,check_even(1));
    TEST_ASSERT_EQUAL(-1,check_even(3));
    TEST_ASSERT_EQUAL(-1,check_even(5));
    TEST_ASSERT_EQUAL(-1,check_even(7));
    TEST_ASSERT_EQUAL(-1,check_even(9));
    TEST_ASSERT_EQUAL(-1,check_even(11));
    TEST_ASSERT_EQUAL(-1,check_even(-1));
    TEST_ASSERT_EQUAL(-1,check_even(-3));
    TEST_ASSERT_EQUAL(-1,check_even(-5));
    TEST_ASSERT_EQUAL(-1,check_even(-7));
    TEST_ASSERT_EQUAL(-1,check_even(-9));
    TEST_ASSERT_EQUAL(-1,check_even(-11));
}

void test_num_to_word(void)
{
    int i;
    char output[20];
    char *expected[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    //Positive test cases
    for(i=0;i<10;i++)
    {
        memset(output,0xaa,sizeof(output));
        TEST_ASSERT_EQUAL(0, num_to_word(i,output));
        TEST_ASSERT_EQUAL_STRING(expected[i],output);        
    }

    //Negative test cases
    memset(output,0xaa,sizeof(output));
    TEST_ASSERT_EQUAL(-1, num_to_word(10,output));
    TEST_ASSERT_EQUAL_UINT8(0xaa,output[0]);

    memset(output,0xaa,sizeof(output));
    TEST_ASSERT_EQUAL(-1, num_to_word(100,output));
    TEST_ASSERT_EQUAL_UINT8(0xaa,output[0]);

    memset(output,0xaa,sizeof(output));
    TEST_ASSERT_EQUAL(-1, num_to_word(-1,output));
    TEST_ASSERT_EQUAL_UINT8(0xaa,output[0]);
}

void test_num_to_word_output_array_bounds(void)
{
    int i;
    char output[20];
    char *expected[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    //Positive test cases
    for(i=0;i<10;i++)
    {
        memset(output,0xaa,sizeof(output));
        TEST_ASSERT_EQUAL(0, num_to_word(i,&output[1]));
        TEST_ASSERT_EQUAL_STRING(expected[i],&output[1]);
        TEST_ASSERT_EQUAL_UINT8(0xaa,output[0]);
        TEST_ASSERT_EQUAL_UINT8(0xaa,output[strlen(&output[1]) + 2]);        
    }

    //Negative test cases
    memset(output,0xaa,sizeof(output));
    TEST_ASSERT_EQUAL(-1, num_to_word(10,output));
    for(i=0;i<sizeof(output);i++)
    {
        TEST_ASSERT_EQUAL_UINT8(0xaa,output[i]);
    }
    
    memset(output,0xaa,sizeof(output));
    TEST_ASSERT_EQUAL(-1, num_to_word(100,output));
    for(i=0;i<sizeof(output);i++)
    {
        TEST_ASSERT_EQUAL_UINT8(0xaa,output[i]);
    }

    memset(output,0xaa,sizeof(output));
    TEST_ASSERT_EQUAL(-1, num_to_word(-1,output));
    for(i=0;i<sizeof(output);i++)
    {
        TEST_ASSERT_EQUAL_UINT8(0xaa,output[i]);
    }    
}

void test_my_range(void)
{

    //Test negative numbers
    TEST_ASSERT_EQUAL(-1, my_range(-101));
    TEST_ASSERT_EQUAL(0, my_range(-100));
    TEST_ASSERT_EQUAL(0, my_range(-99));
    TEST_ASSERT_EQUAL(0, my_range(-98));
    TEST_ASSERT_EQUAL(0, my_range(-50));
    TEST_ASSERT_EQUAL(0, my_range(-1));
    TEST_ASSERT_EQUAL(0, my_range(0));

    //Testing positive numbers
    TEST_ASSERT_EQUAL(-1, my_range(102));
    TEST_ASSERT_EQUAL(-1, my_range(101));
    TEST_ASSERT_EQUAL(0, my_range(100));
    TEST_ASSERT_EQUAL(0, my_range(99));
    TEST_ASSERT_EQUAL(0, my_range(98));
    TEST_ASSERT_EQUAL(0, my_range(2));
    TEST_ASSERT_EQUAL(0, my_range(25));
}

void setUp(void)
{

}

void tearDown(void)
{

}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_add_num_zeros);
    RUN_TEST(test_add_num_positive_integers);
    RUN_TEST(test_add_num_negative_integers);
    RUN_TEST(test_mul_num_mixed_integers);
    RUN_TEST(test_add_num_mixed_integers);
    RUN_TEST(test_add10);
    RUN_TEST(test_check_even);
    RUN_TEST(test_num_to_word);
    RUN_TEST(test_num_to_word_output_array_bounds);
    RUN_TEST(test_my_range);
    
    return UNITY_END();
}