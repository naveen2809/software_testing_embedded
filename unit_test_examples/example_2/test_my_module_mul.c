#include "my_module_mul.h"
#include "unity.h"

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

void setUp(void)
{

}

void tearDown(void)
{

}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_mul_num_mixed_integers);
   
    return UNITY_END();
}