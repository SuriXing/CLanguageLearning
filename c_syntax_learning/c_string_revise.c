#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_string_learning.h"

#pragma mark -- testing function --
static void testMyStrcmpAndncmp();
static void testMyStrCatAndCpy();
static void testMyStrncatAndncpy();
static void testMyStrstr();
static void testMyStrCharAndrchar();
static void testMyStrspnAndcspn();

static int specialForStrcmp(int returnValue)
{
    if (returnValue == 0)
    {
        return 0;
    }
    else if (returnValue > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
#pragma mark-- function definition --

void printStr(const char *str)
{
    assert(NULL != str);

    if (NULL == str)
    {
        return;
    }

    const char *kTest = str;
    while (*kTest != '\0')
    {
        printf("%c", *kTest);

        kTest++;
    }
    printf("\n");
}

int myStrlen(const char *str)
{
    assert(NULL != str);

    if (NULL == str)
    {
        return -1;
    }
    
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
    assert(NULL != str1);
    assert(NULL != str2);

    if ((NULL == str1) || (NULL == str2))
    {
        return -1;
    }

    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (((*str1 - *str2) > 0) ? 1 : ((*str1 - *str2) == 0) ? 0 : -1);
}

int myStrncmp(const char *str1, const char *str2, size_t n)
{
    size_t index = 0;

    assert(NULL != str1);
    assert(NULL != str2);

    if ((NULL == str1) || (NULL == str2))
    {
        return -1;
    }

    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }

    return (((*str1 - *str2) > 0) ? 1 : ((*str1 - *str2) == 0) ? 0 : -1);
}

char *myStrcat(char *dest, const char *src)
{
    assert(NULL != dest);
    assert(NULL != src);

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
    assert(NULL != dest);
    assert(NULL != src);

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
    assert(NULL != dest);
    assert(NULL != src);

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
    assert(NULL != dest);
    assert(NULL != src);

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
    myStrncpy(test, "abcdefghijklmnopqrstuvwqyz", 16);
}

char* myStrstr(const char* str, const char* needle)
{
    assert(NULL != str);
    assert(NULL != needle);

    if ((NULL == str) || (NULL == needle))
    {
        return NULL;
    }

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
    assert(NULL != str);

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
    assert(NULL != str1);
    assert(NULL != str2);

    if ((NULL == str1) || (NULL == str2))
    {
        return 0;
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
    assert(NULL != str1);
    assert(NULL != str2);

    if ((NULL == str1) || (NULL == str2))
    {
        return 0;
    }
    
    char dict[256] = {0};

    while (*str2 != '\0')
    {
        dict[(int)*str2] = 1;
        str2++;
    }
    
    size_t len = 0;

    while (*str1 != '\0')
    {
        if (dict[(int)*str1] != 1)
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
    assert(NULL != str);

    if ((NULL == str))
    {
        return -1;
    }

    int index = myStrlen(str) - 1;

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

void testMyStrcmpAndncmp()
{
    assert(specialForStrcmp(myStrcmp("abcde", "jklmn")) == specialForStrcmp(strcmp("abcde", "jklmn")));
    assert(specialForStrcmp(myStrcmp("ababababa", "lkjh")) == specialForStrcmp(strcmp("ababababa", "lkjh")));

    assert(specialForStrcmp(myStrncmp("abcdefghijklmnopqrstuvwxyz", "jklmn", 13)) == strncmp("abcdefghijklmnopqrstuvwxyz", "jklmn", 13));
    assert(specialForStrcmp(myStrncmp("bansmdjfkrltz", "ltzz", 10)) == specialForStrcmp(strncmp("bansmdjfkrltz", "ltzz", 10)));
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
    assert(myStrstr("asdfghjkjmnbvc", "bvc") == strstr("asdfghjkjmnbvc", "bvc"));
    assert(myStrstr("tfdxcvhjk", "cvh") == strstr("tfdxcvhjk", "cvh"));
}

void cStringLearningTest()
{
    testMyStrcmpAndncmp();
    testMyStrCatAndCpy();
    testMyStrncatAndncpy();
    testMyStrstr();

/*
    printStr("yay");
    myStrChar("asdfghjkl", 'c');
    myStrRChar("qazwsx", 'a');

    myStrspn("qwertyuiop", "");
    myStrcspn_fast(const char *str1, const char *str2);
*/
}