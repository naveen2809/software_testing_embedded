#include "my_module_add.h"
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
    RUN_TEST(test_add_num_mixed_integers);
    
    return UNITY_END();
}