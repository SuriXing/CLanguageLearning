#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "c_string_learning.h"
#include "c_string_testing.h"

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

static void testMyStrcmpAndncmp()
{
    printf("*** Start %s *** \n", __FUNCTION__);

    assert(specialForStrcmp(myStrcmp("abcde", "jklmn")) == specialForStrcmp(strcmp("abcde", "jklmn")));
    assert(specialForStrcmp(myStrcmp("ababababa", "lkjh")) == specialForStrcmp(strcmp("ababababa", "lkjh")));

    assert(specialForStrcmp(myStrncmp("abcdefghijklmnopqrstuvwxyz", "jklmn", 13)) == strncmp("abcdefghijklmnopqrstuvwxyz", "jklmn", 13));
    assert(specialForStrcmp(myStrncmp("bansmdjfkrltz", "ltzz", 10)) == specialForStrcmp(strncmp("bansmdjfkrltz", "ltzz", 10)));

    printf("*** End %s *** \n", __FUNCTION__);
}

static void testMyStrCatAndCpy()
{
    printf("*** Start %s *** \n", __FUNCTION__);

    char test[256] = {};
    char test2[256] = {};

    myStrcat(test, "abcde");
    strcat(test2, "abcde");
    
    assert(specialForStrcmp(strcmp(test, test2)) == 0);
    assert(specialForStrcmp(strcmp(test, test2)) == specialForStrcmp(myStrcmp(test, test2)));

    myStrcpy(test, "abc");
    strcpy(test2, "abc");

    assert(specialForStrcmp(strcmp(test, test2)) == 0);
    assert(specialForStrcmp(strcmp(test, test2)) == specialForStrcmp(myStrcmp(test, test2)));

    myStrcat(test, "qazwsxedc");
    strcat(test2, "qazwsxedc");

    assert(specialForStrcmp(strcmp(test, test2)) == 0);
    assert(specialForStrcmp(strcmp(test, test2)) == specialForStrcmp(myStrcmp(test, test2)));

    myStrcpy(test, "okmijn");
    strcpy(test2, "abcde");

    assert(specialForStrcmp(strcmp(test, test2)) != 0);
    assert(specialForStrcmp(strcmp(test, test2)) == specialForStrcmp(myStrcmp(test, test2)));

    myStrcpy(test, "okmijn");
    strcpy(test2, "okmijn");

    assert(specialForStrcmp(strcmp(test, test2)) == 0);
    assert(specialForStrcmp(strcmp(test, test2)) == specialForStrcmp(myStrcmp(test, test2)));

    myStrcat(test, "abcdefg");
    strcat(test2, "asdfg");

    assert(specialForStrcmp(strcmp(test, test2)) != 0);
    assert(specialForStrcmp(strcmp(test, test2)) == specialForStrcmp(myStrcmp(test, test2)));

    printf("*** End %s *** \n", __FUNCTION__);
}

static void testMyStrstr()
{
    printf("*** Start %s *** \n", __FUNCTION__);

    assert(myStrstr("asdfghjkjmnbvc", "bvc") == strstr("asdfghjkjmnbvc", "bvc"));
    assert(myStrstr("tfdxcvhjk", "cvh") == strstr("tfdxcvhjk", "cvh"));

    printf("*** End %s *** \n", __FUNCTION__);
}

static void testMyStrCharAndrchar()
{
    printf("*** Start %s *** \n", __FUNCTION__);

    assert(myStrchr("abcdefg", 'h') == strchr("abcdefg", 'h'));
    assert(myStrchr("zyxwvutsr", 'r') == strchr("zyxwvutsr", 'r'));

    assert(myStrrchr("abcdefg", 'h') == strrchr("abcdefg", 'h'));
    assert(myStrrchr("zyxwvutsr", 'r') == strrchr("zyxwvutsr", 'r'));

    printf("*** End %s *** \n", __FUNCTION__);
}

static void testMyStrspnAndcspn()
{
    printf("*** Start %s *** \n", __FUNCTION__);

    assert(myStrspn("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqpom") == strspn("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqpom"));
    assert(myStrspn("ababababab", "abcde") == strspn("ababababab", "abcde"));

    //assert(myStrcspn_fast("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqpom") == strcspn("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqpom"));
    //assert(myStrcspn_fast("bleah", "aeh") == strcspn("bleah", "aeh"));

    printf("*** End %s *** \n", __FUNCTION__);
}

void cStringLearningTest()
{
    testMyStrcmpAndncmp();
    testMyStrCatAndCpy();
    testMyStrncatAndncpy();
    testMyStrstr();
    testMyStrCharAndrchar();
    testMyStrspnAndcspn();

/*
    myStrspn("qwertyuiop", "");
    myStrcspn_fast(const char *str1, const char *str2);
*/
}