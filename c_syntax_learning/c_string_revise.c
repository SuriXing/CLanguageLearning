#include <stdio.h>
#include <string.h>
#include "c_string_learning.h"

#pragma mark-- function definition --

void printStr(const char *str)
{
    const char *kTest = str;
    while (*kTest != '\0')
    {
        printf("%c", *kTest);

        kTest++;
    }
    printf("\n");
}

int myLenOfStr(const char *str)
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

int myStrCmp(const char *str1, const char *str2)
{
    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (str1 - str2);
}

int myStrnCmp(const char *str1, const char *str2, size_t n)
{
    size_t index = 0;

    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }

    return (*str1 - *str2);
}

char *myStrcat(char *dest, const char *src)
{
    if ((dest == NULL) || (src == NULL))
    {
        return NULL;
    }

    char *destCopy = dest;

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return destCopy;
}

char *myStrcpy(char *dest, const char *src)
{
    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    char *destCopy = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return destCopy;
}

void testMyStrCatAndCpy()
{
    char test[256] = {};

    myStrcat(test, "abcde");
    printf("%s\n", test);

    myStrcpy(test, "abc");
    printf("%s\n", test);
}

char* myStrncat(char* dest, const char* src, size_t n)
{
    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    char* destCopy = dest;
    size_t count = 0;

    while (*dest != '\0')
    {
        dest++;
    }

    while ((*src != '\0') && (count < n))
    {
        *dest = *src;
        dest++;
        src++;
        count++;
    }

    return destCopy;
}

char* myStrncpy(char* dest, const char* src, size_t n)
{
    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    char* destCopy = dest;
    size_t count = 0;
    
    while ((*src != '\0') && (count < n))
    {
        *dest = *src;
        dest++;
        src++;
        count++;
    }
    *dest = '\0';

    return destCopy;
}

void testMyStrncatAndncpy()
{
    char test[256] = "";

    myStrncat(test, "abcdeqazwsxedgujf", 7);
    printf("%s\n", test);

    myStrncpy(test, "abcdefghijklmnopqrstuvwqyz", 16);
    printf("%s\n", test);
}

char* myStrstr(const char* str, const char* needle)
{
    while (*str != '\0')
    {
        const char* str1 = str;
        const char* str2 = needle;

        while ((*str2 != '\0') && (*str1 == *str2))
        {
            str1++;
            str2++;
        }

        if (*str2 == '\0')
        {
            return (char*)str;
        }

        str++;
    }

    return NULL;
}

void testMyStrstr()
{
    printf("%s\n", myStrstr("asdfghjkjmnbvc", "bvc"));
    printf("%s\n", myStrstr("tfdxcvhjk", "cvh"));
    printf("%s\n", myStrstr("olghdsghsunm", "lghds"));
}

char* myStrChar(const char* str, char c)
{
    if (NULL == str)
    {
        return NULL;
    }

    while ((*str != c) && (*str != '\0'))
    {
        str++;
    }
    
    return ((*str == '\0') ? NULL : ((char*)str));
}

size_t myStrspn(const char *str1, const char *str2)
{
    if ((NULL == str1) || (NULL == str2))
    {
        return -1;
    }

    size_t index = 0;

    while (*str1 != '\0')
    {
        if (myStrChar(str2, *str1) != NULL)
        {
            return index;
        }
        
        str1++;
        index++;
    }

    return -1;
}

void cStringLearningTest()
{
    //testMyStrCatAndCpy();

    testMyStrstr();
}