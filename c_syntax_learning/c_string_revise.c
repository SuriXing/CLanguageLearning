#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_string_learning.h"

#pragma mark-- function definition --

void printStr(const char *str)
{
    // Check for NULL pointer
    if (str == NULL)
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

size_t myStrlen(const char *str)
{
    // Check for NULL pointer
    if (str == NULL)
    {
        return 0;
    }

    size_t length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}

int myStrcmp(const char *str1, const char *str2)
{
    // Check for NULL pointers
    if (str1 == NULL || str2 == NULL)
    {
        return -1;
    }

    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return ((*str1 - *str2) > 0) ? 1 : ((*str1 - *str2) == 0) ? 0 : -1;
}

int myStrncmp(const char *str1, const char *str2, size_t n)
{
    // Check for NULL pointers
    if (str1 == NULL || str2 == NULL)
    {
        return -1;
    }

    size_t index = 0;
    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }

    return ((*str1 - *str2) > 0) ? 1 : ((*str1 - *str2) == 0) ? 0 : -1;
}

char *myStrcat(char *dest, const char *src)
{
    // Check for NULL pointers
    if (dest == NULL || src == NULL)
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
    // Check for NULL pointers
    if (dest == NULL || src == NULL)
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
    // Check for NULL pointers
    if (dest == NULL || src == NULL)
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

    *dest = '\0';
    return destCopy;
}

char* myStrncpy(char* dest, const char* src, size_t n)
{
    // Check for NULL pointers
    if (dest == NULL || src == NULL)
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

    // Ensure the destination string is null-terminated
    if (count < n)
    {
        *dest = '\0';
    }

    return destCopy;
}

void testMyStrncatAndncpy()
{
    char test[256] = "";

    // Check the return value of myStrncat
    if (myStrncat(test, "abcdeqazwsxedgujf", 7) == NULL)
    {
        printf("myStrncat failed\n
    }
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

char* myStrchr(const char* str, char c)
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
        return -1;
    }

    size_t index = 0;

    while (*str1 != '\0')
    {
        if (myStrchr(str2, *str1) == NULL)
        {
            break;
        }
        
        str1++;
        index++;
    }

    return index;
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

char* myStrrchr(const char* str, char a)
{
    assert(NULL != str);

    if (NULL == str)
    {
        return NULL;
    }

    int index = myStrlen(str) - 1;

    while (index >= 0)
    {
        if (str[index] == a)
        {
            break;
        }
        index--;
    }

    return (index >= 0 ? (char*)(str + index) : NULL);
}