#include <stdio.h>
#include "unity.h"

static char output[100];

void setUp(void) {
    
}

void tearDown(void) {
    
}

void test_function_NoFormatOperations(void) {
    TEST_ASSERT_EQUAL(3,sprintf(output,"hey"));    
    TEST_ASSERT_EQUAL_STRING("hey",output);
}

void test_function_InsertString(void) {
    TEST_ASSERT_EQUAL(12,sprintf(output,"Hello %s\n","World"));    
    TEST_ASSERT_EQUAL_STRING("Hello World\n",output);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_NoFormatOperations);
    RUN_TEST(test_function_InsertString);
    return UNITY_END();
}