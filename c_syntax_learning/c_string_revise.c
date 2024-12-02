#include <stdio.h>
#include <string.h>

#pragma mark -- function declaration --

void printStr(const char *str);

int myLenOfStr(const char *str);

#pragma mark -- testing functions declaration --


#pragma mark -- function definition --

printStr(const char * str)
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