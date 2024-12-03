#include <stdio.h>
#include <string.h>
#include "c_string_learning.h"

#pragma mark -- testing functions declaration --


#pragma mark -- function definition --

void printStr(const char * str)
{
    const char* kTest = str;
    while (*kTest != '\0')
    {
        printf("%c", *kTest);

        kTest++;
    }
    printf("\n");
}

int myLenOfStr(const char* str)
{
    int length = 0;

    // All the strings end with '\0'
    // *str mean the current character
    while (*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}

void c_string_learning_test()
{

}