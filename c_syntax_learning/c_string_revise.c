#include <stdio.h>
#include <string.h>
#include <assert.h>
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

int myStrcmp(const char *str1, const char *str2)
{
    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int myStrncmp(const char *str1, const char *str2, size_t n)
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

size_t myStrcspn_fast(const char *str1, const char *str2)
{
    if ((NULL == str1) || (NULL == str2))
    {
        return 0;
    }
    
    char dict[256] = {0};

    while (*str2 != '\0')
    {
        dict[*str2] = 1;
        str2++;
    }
    
    size_t len = 0;

    while (*str1 != '\0')
    {
        if (dict[*str1] != 1)
        {
            return len;
        }
        str1++;
        len++;
    }
    return -1;
}

int myStrRChar(char* str, char a)
{
    if ((NULL == str))
    {
        return -1;
    }

    int index = myLenOfStr(str) - 1;

    while (index >= 0)
    {
        if (str[index] == a)
        {
            return index;
        }
        index--;
    }

    return -1;
}

void testMyStrCatAndCpy()
{
    char test[256] = {};
    char test2[256] = {};

    myStrcat(test, "abcde");
    strcat(test2, "abcde");
    
    assert(strcmp(test, test2) == 0);
    assert(strcmp(test, test2) == myStrcmp(test, test2));

    myStrcpy(test, "abc");
    strcpy(test2, "abc");

    assert(strcmp(test, test2) == 0);
    assert(strcmp(test, test2) == myStrcmp(test, test2));

    myStrcat(test, "qazwsxedc");
    strcat(test2, "qazwsxedc");

    assert(strcmp(test, test2) == 0);
    assert(strcmp(test, test2) == myStrcmp(test, test2));

    myStrcpy(test, "okmijn");
    strcpy(test2, "abcde");

    assert(strcmp(test, test2) != 0);
    assert(strcmp(test, test2) == myStrcmp(test, test2));

    myStrcpy(test, "okmijn");
    strcpy(test2, "okmijn");

    assert(strcmp(test, test2) == 0);
    assert(strcmp(test, test2) == myStrcmp(test, test2));

    myStrcat(test, "abcdefg");
    strcat(test2, "asdfg");

    assert(strcmp(test, test2) != 0);
    assert(strcmp(test, test2) == myStrcmp(test, test2));
}

void testMyStrstr()
{
    printf("%s\n", myStrstr("asdfghjkjmnbvc", "bvc"));
    printf("%s\n", myStrstr("tfdxcvhjk", "cvh"));
    printf("%s\n", myStrstr("olghdsghsunm", "lghds"));
}

void cStringLearningTest()
{
    testMyStrCatAndCpy();

    testMyStrstr();
}