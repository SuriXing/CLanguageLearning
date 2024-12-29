#include <stdio.h>
#include "c_array_learning.h"
#include "c_string_testing.h"
#include "c_advanced_learning.h"

#define TESTSUITE(NAME, FUNCTION)\
    printf("\n*** Start testing for %s ***\n", NAME);\
    FUNCTION();\
    printf("*** End testing for %s *** \n", NAME);\

int main()
{
    TESTSUITE("Array", cArrayLearningTest)
    TESTSUITE("String", cStringLearningTest)

//    TESTSUITE("Advanced", cAdvancedLearningTest)    
    return 0;
}