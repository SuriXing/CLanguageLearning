#include <stdio.h>
#include <string.h>
#include "c_string_learning.h"

#pragma mark -- testing functions declaration --

void printStr(const char * str);

int myLenOfStr(const char* str);

int myStrCmp(const char* str1, const char* str2);
int myStrnCmp(const char* str1, const char* str2, size_t n);

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

int myStrCmp(const char* str1, const char* str2)
{
    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (str1 - str2);
}

int myStrnCmp(const char* str1, const char* str2, size_t n)
{
    size_t index = 0;

    while((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }
    
    return (*str1 - *str2);
}

void cStringLearningTest()
{

}