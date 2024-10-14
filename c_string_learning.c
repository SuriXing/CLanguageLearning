#include <stdio.h>
#include <string.h>

#pragma mark -- function declaration --
int myLenOfStr(const char* str);
void printString(const char* str);
int myStrcmp(const char *str1, const char *str2);
int myStrncmp(const char *str1, const char *str2, size_t n);
void testStrcmp();

int main()
{
    int strcmp(const char *str1, const char *str2);
    
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

    testStrcmp();

    return 0;
}

#pragma mark -- function implementation --

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

int myStrcmp(const char *str1, const char *str2)
{
    // "abcdefgh" vs. "abcdefg"
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