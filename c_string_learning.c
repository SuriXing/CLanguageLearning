#include <stdio.h>
#include <string.h>

#pragma mark -- function declaration --
int myLenOfStr(const char* str); 
void printString(const char* str);
int myStrcmp(const char *str1, const char *str2);
int myStrncmp(const char *str1, const char *str2, size_t n);
int myStrcmp2(const char *str1, const char *str2);
int myStrncmp2(const char *str1, const char *str2, size_t n);
int myStrncmp3(const char *str1, const char *str2, size_t n);
void testStrcmp();
void testStrcatAndStrcpy();
char *myStrcat(char *dest, const char *src);
char *myStrcpy(char *dest, const char *src);
char* myStrcat2(char *dest, const char *src);
char* myStrCpy2(char *dest, const char *src);
void testStrcat2AndStrcpy2();
char* myStrncpy(char* dest, const char* src, size_t n);
void testMyStrncpy();
char* myStrChar(const char* str, char c);
int myStrRChar(char* str, char a);
size_t myStrspn(const char *str1, const char *str2);
size_t myStrspn2(const char *str1, const char *str2);
size_t myStrcspn(const char *str1, const char *str2);
size_t myStrcspn2(const char *str1, const char *str2);

int main()
{
    int res = myStrRChar("Harry Potter and the flying doggy", 't');
    printf("%d\n", res);
    
    char* res2 = myStrChar("Harry Potter and the flying doggy", 't');
    printf("%s\n", res2);
    
    int res3 = myStrcmp("abcdef", "basf");
    printf("%d\n", res3);

    int res4 = myStrncmp3("ac", "ab", 2);
    printf("%d\n", res4);

   /* testStrcmp();
    
    const char* kDemoStr = "I am a demo string";    // a string
    char demoCharArray[] = "I am a demo character array";    // a character array
    demoCharArray[0] = 'Y';

    int arr[11] = {0};
    arr[0] = 1;

    for (int i = 0; i < 256; i++)
    {
        printf("%c\n", (char)i);
    }
    printf("%c\n", (char)47);
    printf("%d\n", (int)'1');
    printf("%d\n", (int)'9');
    printf("%d\n", (int)'a');
    printf("%d\n", '\0');

    int lenOfStr = strlen(kDemoStr);
    printf("Length of String: %d\n", lenOfStr);

    int res = myLenOfStr(kDemoStr);
    printf("My length of String: %d\n", res);

    if (res == strlen(kDemoStr))
    {
        printf("OH YESS\n");
    }
    else
    {
        printf("WHAT\n");
    }

    testStrcatAndStrcpy();

    testStrcat2AndStrcpy2();

    testMyStrncpy();

    return 0;*/
}

#pragma mark -- function implementation --

int myStrncmp3(const char *str1, const char *str2, size_t n)
{
    if((NULL == str1) || (NULL == str2))
    {
        if(str1 == str2)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    int index = 1;

    while((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }
    return (*str1 - *str2);
}

void printString(const char* str)
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

int myStrncmp(const char *str1, const char *str2, size_t n)
{
    // ("abcde", "abc", 1)
    // ("abcde", "abc", 2)
    // ("abcde", "abc", 3)
    // ("abcde", "abc", 4)
    // ("abcde", "abc", 5) 
    size_t index = 0;
    while((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }

    return (index == n) ? 0 : (*str1 - *str2);
}

int myStrncmp2(const char *str1, const char *str2, size_t n)
{
    size_t index = 0;

    while((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (index < n))
    {
        str1++;
        str2++;
        index++;
    }

    return (index == n) ? 0: (*str1 - *str2);
}

int myStrcmp(const char *str1, const char *str2)
{
    // "abcdefgh" vs. "abcdtestStrcatAndStrcpyefg"
    // "abc" vs. "cde"
    // "a" vs. "ab"
    // "a" vs. "a"
    // "c" vs. "abcdef"
    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}

int myStrcmp2(const char *str1, const char *str2)
{
    while((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
    {
        str1 ++;
        str2 ++;
    }
    return (*str1 - *str2);
}

void testStrcatAndStrcpy()
{
    char test[256] = {};

    myStrcat(test, "abcde");
    printf("%s\n", test);

    myStrcpy(test, "abc");
    printf("%s\n", test);
}

void testStrcmp()
{
    printf("%d\t%d\n", myStrncmp("abcde", "abc", 1), myStrcmp("abcde", "abc"));
    printf("%d\t%d\n", myStrncmp("abcde", "abc", 3), myStrcmp("abcde","abc")); 
    printf("%d\n", myStrncmp("abcde","abc", 4)); 
    printf("%d\n", myStrncmp("abcde","abc", 5)); 
    printf("%d\n", myStrncmp("abcdefg","abcdhfg", 5)); 
    printf("%d\n", myStrncmp("asfghj","dfgh", 3));
    printf("%d\n", myStrncmp("big","bigger",2));
    printf("%d\n", myStrncmp("abcde","abcde",5));
    printf("%d\n", myStrncmp("abcded","abcdee",3));
    printf("%d\n", myStrncmp("small","smaller",2));
    printf("%d\n", myStrncmp("median","mediann",3));
    printf("%d\n", myStrncmp("asdfg","azsxdcvfgb",5));
    printf("%d\n", myStrncmp("asdfg","qwert",5));
    printf("%d\n", myStrncmp("zxcvb","zxcvbn",3));
    printf("%d\n", myStrncmp("azsxd","aszdx",5));
    printf("%d\n", myStrncmp("qwert","asdrt",6));
    printf("%d\n", myStrncmp("lol","loll",3));
    printf("%d\n", myStrncmp("doll","dolls",7));
    printf("%d\n", myStrncmp("qazwsx","qazwsc",5));
    printf("%d\n", myStrncmp("abcdefg","abcdefghijklmn",6));
    printf("%d\n", myStrncmp("opq","opqrst",3));
    printf("%d\n", myStrncmp("uwu","uwuuwu",2));
}

char *myStrcpy(char* dest, const char* src)
{
    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    char* destCopy = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

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

void testMyStrncpy()
{
    char test[256] = {};
    
    myStrncpy(test, "Hello World", 9);
    printf("%s\n", test);
}

char* myStrcpy2(char *dest, const char *src)
{
    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    char* destCopy = dest;

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    return destCopy;
}

char *myStrcat(char* dest, const char* src)
{
    if ((NULL == dest) || (NULL == src))
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

char* myStrcat2(char* dest, const char* src)
{
    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    char* destCopy = dest;

    while(*dest != '\0')
    {
        dest++;
    }
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest ='\0';

    return destCopy;
}

void testStrcat2AndStrcpy2()
{
    char test[256] = {};

    myStrcat2(test, "abcdefg");
    printf("%s\n", test);

    myStrcpy2(test, "abcdgjk");
    printf("%s\n", test);
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

int myStrRChar(char* str, char a)
{
    if((NULL == str))
    {
        return -1;
    }

    int index = myLenOfStr(str) - 1;

    while(index >= 0)
    {
        if(str[index] == a)
        {
            return index;
        }
        index--;
    }

    return -1;
}

size_t myStrspn(const char *str1, const char *str2)
{
    if ((NULL == str1) || (NULL == str2))
    {
        return -1;
    }

    int len = 0;
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

size_t myStrspn2(const char *str1, const char *str2)
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

size_t myStrcspn(const char *str1, const char *str2)
{
    if ((NULL == str1) || (NULL == str2))
    {
        return -1;
    }

    size_t index = 0;

    while (*str1 != '\0')
    {
        if (myStrChar(str2, *str1) == NULL)
        {
            return index;
        }
        index ++;
        str1++;
    }

    return -1;
}

size_t myStrcspn2(const char *str1, const char *str2)
{
    if ((NULL == str1) || (NULL == str2))
    {
        return -1;
    }

    size_t index = 0;

    while(*str1 != '\0')
    {
        if (myStrChar(str2, *str1) == NULL)
        {
            return index;
        }
        index++;
        str1++;
    }
    return -1;
}